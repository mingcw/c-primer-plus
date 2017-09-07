#include <stdio.h>

int imax(int n, int m);	

int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3, 5));		
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));		//“double”转换到“int”丢失精度，会警告但不会报错（编译时会自动转换（截断））

	getchar();
	return 0;
}

int imax(int n, int m)
{
	int max;

	if (n > m)
		max = n;
	else
		max = m;
	
	return max;
}