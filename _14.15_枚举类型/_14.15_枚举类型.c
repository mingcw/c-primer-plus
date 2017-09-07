#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>				//C99特性，向C++兼容
#include <string.h>

#define	LEN 30

enum spectrum						//枚举类型模板，枚举的常量列表用默认值
{
	red,
	orange,
	yellow,
	green,
	blue,
	violet
};

const char * colors[] = { "red", "orange", "yellow", "greem", "blue", "violer" };

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;
	
	system("COLOR 0A");
	puts("Enter a color (empty line to quit):");
	while (gets_s(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
		{
			switch (color)
			{
			case red:	puts("Rose are red.");
				break;
			case orange:puts("Poppies are orange.");
				break;
			case yellow:puts("Sunflowers are yellow.");
				break;
			case green:	puts("Grass is green.");
				break;
			case blue:	puts("Bluebells are blue.");
				break;
			case violet:puts("Violets are violet.");
				break;
			default:
				break;
			}			
		}
		else
		{
			printf("I don't know about the color %s.\n", choice);
		}
		color_is_found = false;
		puts("Next color, please (empty line to stop):");
	}
	puts("Good bye.");

	system("pause");
	return 0;
}
/*共享的名字空间：
	在一个特定作用域内的结构标记、联合标记、枚举标记，共享同一个名字空间，并且这个名字空间与普通变量使用的名字空间是不相同的。
	
	也就是说：
	可以在同一个作用域内对一个变量和一个标记使用同一个名字而不冲突；但是不能在同一个作用域内使用名字相同的两个标记或名字相同的两个变量：
	即：
	struct rect{double x; double y};
	int rect;	//在C中并不冲突
	但是，用两种不同的方式使用同一种标识符会造成混乱；
	而且，C++不允许在同一个作用域内对一个变量和一个标记使用同一个名字，因为它把标记和变量名放在同一个名字空间。

	其实就是一句话，尽量不要使用同名的标识符。
*/