#include <stdio.h>

int main(void)
{
	//统计输入字符串的元音字母数目

	//char ch;
	//int a_ct, e_ct, i_ct, o_ct, u_ct;

	//a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	//printf("Enter some text(# to quit):\n");
	//while((ch = getchar())!= '#')
	//{
	//	switch (ch)
	//	{
	//	case 'a':
	//	case 'A':
	//		a_ct++;
	//		break;
	//	case 'e':
	//	case 'E':
	//		e_ct++;
	//		break;
	//	case 'i': //如果chs是i，switch定位到case 'i'标签，因为没有break与该标签关联，所以程序流程继续前进到下一个语句，即i_ct++;如果ch是I，程序流程直接定位到那条语句。本质上，两个标签都指向相同的语句
	//	case 'I':
	//		i_ct++;
	//		break;
	//	case 'o':
	//	case 'O':
	//		o_ct++;
	//		break;
	//	case 'u':
	//	case 'U':
	//		u_ct++;
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//printf("number of vowels; A E I O U\n");
	//printf("                  %d %d %d %d %d\n",
		//a_ct, e_ct, i_ct, o_ct, u_ct);

	//或者，可以用ctype.h的toupper()转换到大写字母，避免多重标签
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("Enter some text(# to quit):\n");
	while ((ch = getchar()) != '#')
	{
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			a_ct++;
			break;
		case 'E':
			e_ct++;
			break;
		case 'I':
			i_ct++;
			break;
		case 'O':
			o_ct++;
			break;
		case 'U':
			u_ct++;
			break;
		default:
			break;
		}
	}
	printf("number of vowels; A E I O U\n");
	printf("                  %d %d %d %d %d\n",
		a_ct, e_ct, i_ct, o_ct, u_ct);

	getchar();
	getchar();
	return 0;
}