#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEG_TO_RAD ((4 * atan(1)) / 180)

typedef struct polar_v
{
	double magnitude;
	double angle;
} POLAR_V;

typedef struct rect_v
{
	double x;
	double y;
} RECT_V;

RECT_V polar_to_rect(POLAR_V polar);

int main(void)
{
	POLAR_V polar;
	RECT_V rect;

	system("color 5A");
	puts("Please input magnitude and angle (0 0 to quit)");
	if (scanf_s("%lf %lf", &polar.magnitude, &polar.angle) == 2
		&& polar.magnitude)
	{
		rect = polar_to_rect(polar);
		printf("x = %.2lf, y = %.2lf\n", rect.x, rect.y);
	}
	if (polar.magnitude == 0)
	{
		puts("x= 0, y = 0");
	}
	puts("Bye.");

	system("pause");
	return 0;
}

RECT_V polar_to_rect(POLAR_V polar)
{
	RECT_V rect;

	rect.x = polar.magnitude * cos(polar.angle * DEG_TO_RAD);
	rect.y = polar.magnitude * sin(polar.angle * DEG_TO_RAD);

	return rect;
}