#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 81			//字符串长度限制(包括空字符)
#define ROWS 20			//最多读取的行数


void stsrt(char * ptstr[], int rows);		//指针排序

int main(void)
{
	char input[ROWS][SIZE];			//字符串数组
	char * ptstr[ROWS];				//指针数组保存每个字符串的地址(用来对指向字符串的指针进行排序，注意字符串数组每个字符串名作为指针时，不能交换指针，因为这是指向字符串的地址常量，常量不允许修改)
	int ct = 0;						//输入计数
	int i;							//输出计数
	
	system("color 0A");

	printf("Input up to %d lines, and I will sort them.\n", ROWS);
	printf("To stop, press the Enter key ay a line's start.\n");
	while (ct < ROWS && gets_s(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];		//指针数组成员指向每一个字符串
		ct++;						//统计输入的字符串数
	}
	stsrt(ptstr, ct);				//指针排序
	puts("\nHere's the sorted list: \n");
	for (i = 0; i < ct; i++)
	{
		puts(ptstr[i]);				//打印排序后的指针指向的字符串
	}

	getchar();
	return 0;
}


//字符串指针排序函数
void stsrt(char * ptstr[], int rows)
{
	char * temp;

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = i + 1; j < rows ; j++)
		{
			if (strcmp(ptstr[i], ptstr[j])> 0)
			{
				temp = ptstr[i];
				ptstr[i] = ptstr[j];
				ptstr[j] = temp;
			}
		}
	}
}