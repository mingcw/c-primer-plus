#include <stdio.h>

int main(void)
{
	int cm, n, m;
	cm = 100;
	n = 1;
	m = 1;

	printf("%d米是%d厘米\n", m, cm);
	printf("%d米是%d厘米\n", m, n*cm);
	printf("%d米是%d厘米\n", 5 * m, 5 * cm);

	getchar();
	return 0;

}