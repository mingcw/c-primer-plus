#include <stdio.h>

void display(char ch, int lines,int cols);

int main(void)
{
	//调试结果，bug1：scanf扫描输入，跳过空白自符。输入数据后，scanf跳过了最后的空白换行符，而getchar则获取到了换行符，所以在回应用户后，马上又提示“Bye”（获取到了换行符）
	//修改结果见_8.6_源代码
	int ch;
	int lines, cols;

	printf("Please enter a character\n");
	printf("Enter a new line to quit : ");
	while ((ch = getchar()) != '\n')
	{
		printf("Enter two integers : ");
		scanf_s("%d %d", &lines, &cols, 10);
		display(ch, lines, cols);
		printf("Please Enter another character\n");
		printf("Enter a new line to quit : ");
	}
	printf("Bye!\n");
	
	getchar();
	getchar();
	return 0;
}

void display(char ch, int lines, int cols)
{
	for (int i = 1; i <= lines; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			putchar(ch);
		}
		printf("\n");
	}
}