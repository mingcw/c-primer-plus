//Ïà¹Øº¯Êý

#include <stdio.h>

int set_mode(int errmode)
{
	int mode;

	if (errmode != 0 && errmode != 1)
	{
		mode = 1;
		printf("Invalid mode specified.Mode 1 (US) used.\n");
	}
	mode = (int)errmode;

	return mode;
}

void get_info(int * mode, float * x, float * y)
{
	printf("Enter distance travelled in %s: ", 
		(mode ? "miles" : "kilometers"));
	scanf_s("%f", x, 10);
	printf("Enter fuel consumed in %s: ", 
		(mode ? "gallons" : "liters"));
	scanf_s("%f", y, 10);
}

void show_info(int mode, float x, float y)
{
	float consumption;

	if (mode)
		consumption = (float)(x / y);
	else
		consumption = (float)(y / x * 100.0);
	printf("Fuel consumption is %.*f liters per %s.\n",
		(mode ? 1 : 2), consumption, (mode ? "gallon" : "100km"));
}
