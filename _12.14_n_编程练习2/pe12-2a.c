//Ïà¹Øº¯Êý

#include <stdio.h>

static float mode = 0;
static float x = 0;
static float y = 0;

void set_mode(float errmode)
{
	if (errmode != 0 && errmode != 1)
	{
		mode = 1;
		printf("Invalid mode specified.Mode 1 (US) used.\n");
	}
}

void get_info(void)
{
	printf("Enter distance travelled in %s: ", 
		mode ? "miles" : "kilometers");
	scanf_s("%f", &x);
	printf("Enter fuel consumed in %s: ", 
		mode ? "gallons" : "liters");
	scanf_s("%f", &y);
}

void show_info(void)
{
	float consumption;
	if (mode)
		consumption = (float)(x / y);
	else
		consumption = (float)(y / x * 100.0);
	printf("Fuel consumption is %.*f liters per %s.\n", 
		mode ? 1 : 2, consumption, mode ? "gallon" : "100km");
}
