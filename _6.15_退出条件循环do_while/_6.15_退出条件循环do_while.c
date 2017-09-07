#include <stdio.h>

int main(void)
{
	//读取输入，当输入为13时，结束循环
	const int secret_code = 13;
	int code_entered;
	
	do
	{
		printf("To enter the triskaidekaphobia therapy club, \n");
		printf("please enter the secret code number: ");
		scanf_s("%d", &code_entered);
	} while (code_entered != secret_code);	//do while()循环本身是一个语句，需要结尾的分号
	printf("OK, you have restored from the triskaidekaphobia!\n");

	getchar();
	getchar();
	return 0;

	//使用等价的while()循环代码会变长，需要先判断一次，参见 _6.16_入口条件循环
}