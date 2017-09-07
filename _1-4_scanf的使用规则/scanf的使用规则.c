#include <stdarg.h>

int main(void)
{
	int age;		//变量
	float assets;	//变量
	char pet[30];	//char数组

	/*scanf("%d %f", &age, &assets)使用空字符（空格，制表符，换行符）决定怎样将输入分成几个字段，
	再用转换说明符依次与字段匹配，字段之间的空字符自动忽略
	也就是，如果输入多个字段时，每个字段之间用空字符隔开，
	scanf会自动分割匹配与转换说明符相应的字段内容，存储到指定的变量地址*/
	printf("Enter your age, assets, and favourte pet.\n");
	scanf("%d %f", &age, &assets);//对变量使用&
	scanf("%s", pet);			  //对char数组不使用&
	printf("%d $%.2f %s", age, assets, pet);
	
	getchar();
	getchar();
	return 0;
}