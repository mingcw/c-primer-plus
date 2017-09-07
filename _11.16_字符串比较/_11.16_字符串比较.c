#include <stdio.h>
#include <string.h>


#define SIZE 41
#define ANSWER "Grant"

int main(void)
{
	char try_[41];
	
	puts("Who is buried in Grant's tomb?");
	gets_s(try_, SIZE);
	while (try_ != ANSWER)		/*错误的条件；显然，如果被比较的2个字符串不一样，提示用户继续输入，直到一样为止，
								  但是，try和ANSWER实际上是char类型的指针，指针值（2字符串的地址）永远不相等，
								  所以无论输入什么，都会无限循环*/
	{
		puts("No, that's wrong. Try again.");
		gets_s(try_, SIZE);
	}
	puts("That's right!");

	getchar();
	return 0;
}