#include <stdio.h>
#include "pe12-2a.h"
#include <stdlib.h>

int main(void)
{
	int mode;
	float x;
	float y;

	system("COLOR 5A");
	printf("Enter 0 for metric mode, 1 for US code: ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		mode = set_mode(mode);
		get_info(&mode, &x, &y);
		show_info(mode, x, y);
		printf("Enter 0 for metric mode, 1 for US code ");
		printf("(-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}