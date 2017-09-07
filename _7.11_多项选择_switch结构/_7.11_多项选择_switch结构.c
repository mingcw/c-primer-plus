#include <stdio.h>
#include <ctype.h>		//提供islower()函数原型

int main(void)
{
	//提示用户输入一个小写字母，程序给出一个以该小写字母开头的动物名字

	char ch;

	printf("Give me a letter of the alphabet, and i will give ");
	printf("an animals name \nbeginning with that letter.\n");
	printf("Please type in a letter : type # to end my act.\n");
	while ((ch = getchar()) != '#')
	{
		if (islower(ch))
		{
			switch (ch)
			{
			case 'a':
				printf("argali, a wild sheep of Asia\n");
				break;
			case 'b':
				printf("babirusa, a wild pig of Malay\n");
				break;
			case 'c':
				printf("coati, racoonlike mammal\n");
				break;
			case 'd':
				printf("desman, aquatic, molelike critter\n");
				break;
			case 'e':
				printf("echidna, the spiny anteater\n");
				break;
			case 'f':
				printf("fisher, brownish marten\n");
				break;
			default:
				printf("That's a stumper!\n");
				break;
			}
		}
		else
		{
			printf("I recognize only lowercase letters.\n");
		}
		while (getchar() != '\n')
		{
			continue;	/*跳过输入行的剩余部分,
						仅处理第一个字符，
						其他字符仅被读取并丢弃，
						当读取丢弃最后一个换行符时，下个字符是下一行的首字符,由外层while循环的getchar()读取并赋值给ch,
						*/
		}
		printf("Please type another letter or a #.\n");
	}
	printf("Bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}