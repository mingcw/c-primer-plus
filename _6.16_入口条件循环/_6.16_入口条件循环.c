#include <stdio.h>

int main(void)
{
	//_6.15_退出条件循环do_while 的等价代码while循环，但代码量会增大，需要先行判断一次

	const int secret_code = 13;
	int code_entered;

	printf("To enter the triskaidekaphobia therapy club, \n");
	printf("please enter the secret code number: ");
	scanf_s("%d", &code_entered);
	while (code_entered != secret_code)
	{
		printf("To enter the triskaidekaphobia therapy club, \n");
		printf("please enter the secret code number: ");
		scanf_s("%d", &code_entered);
	}
	printf("OK, you have restored from the triskaidekaphobia!\n");

	getchar();
	getchar();
	return 0;
}