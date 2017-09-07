
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 41

int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	char str3[SIZE] = "Change the world by programing!";
	//printf("%d", strlen(str3));							31

	system("color 0A");

	//1.复制字符串
	strcpy_s(str1, SIZE, "MingCxx");				//源字符串拷贝到目标位置（包括空字符）				必须保证目标位置有足够的存储空间
	puts(str1);

	//2.复制字符串（最多n个字符）
	strncpy_s(str2, SIZE,"MingC " , 6);				/*将源字符串拷贝到目标位置，最多n个字符。
													如果源字符串长度小于n，在目标字符串中以空字符填充剩余空间；
													如果大于等于n，空字符不被复制。		此时，安全起见，目标字符串的尾部应设置为空字符:
													dest[n] = '\0';		//n个字符后添加空字符，数组元素由0开始
													
													不过，这个_s的较安全版本会自动填充空字符（调试结果）*/
	//str2[6] = '\0';								//调试结果知，该句可有可无，但对于C库中的标准strcpy()函数，必须保证字符串最后一个字符是空字符
	puts(str2);


	//3.连接字符串
	strcat_s(str2, SIZE, str3);						//把源字符串接在目标字符串的尾部，并追加空字符
	puts(str2);
	//printf("%d", strlen(str2));							37

	//4.连接字符串（最多n个字符）
	strncat_s(str1, SIZE, str3, SIZE - 1);			//把源字符串接在目标字符串的尾部，并追加空字符
	puts(str1);

	//5.比较字符串
	printf("strcmp(\"ABC\",\"ABD\") is %d \n", strcmp("ABC", "ABD"));
													//比较两字符串每一对字符 ANSCII之差，大于0返回正值，小于0返回负值，等于零继续查找下一对(空字符也参与比较)

	//6.比较字符串（最多n个字符）
	printf("strncmp(\"ABC\",\"ABD\") is %d \n", strncmp("ABC", "ABD", 2));
													//比较比较两字符串每一对字符 ANSCII之差，最多比较前n个字符或遇到空字符为止
	
	//7.查找单个字符在字符串中的 首位置
	char *p = strchr("Fish.com", 'c');				//查找目标字符串中首次出现该字符的位置，返回指向该位置的char指针（或空指针）
	printf("The index of \'c\' in the \"Fish.com\" is %d <%p> \n", p - "Fish.com", p);		//打印该元素在字符串中首次出现位置的偏移


	//8.查找控制字符串中的任一字符
	char *p1 = strpbrk("Fish.com", "ABmn");			//查找目标字符串中首次出现源字符串中任一字符的位置，返回指向该位置的char指针（或空指针）
	printf("The index of someone character from \"ABmn\" in the \"Fish.com\" is %d <%p> \n", p1 - "Fish.com", p1);

	//9.查找单个字符在字符串中的 末位置
	char *p2 = strrchr("www.Fish.com", '.');		//查找目标字符串中首次出现该字符的位置，返回从字符串中的这个位置起，一直到字符串结束的所有字符（也就是该位置的指针（或空指针））
	printf("The index of \'.\' in the \"www.Fish.com\" is %d <%p> \n", p2 - "www.Fish.com", p2);		//打印该元素在字符串中最后出现位置的偏移

	//10.查找子字符串
	char *p3 = strstr("www.Fish.com", "Fish");		//查找目标字符串中首次出现该子字符串的位置，返回指向该位置的char指针（或空指针）
	printf("The index of \'Fish\' in the \"www.Fish.com\" is %d <%p> \n", p3 - "www.Fish.com", p3);		//打印该子字符串在字符串中首次出现位置的偏移
	p3 = strstr("www.Fish.com", "fish");
	printf("The index of \'fish\' in the \"www.Fish.com\" is %d <%p> \n", p3 - "www.Fish.com", p3);

	//11.字符串长度
	printf("The length of \"MingC\" is %d\n", strlen("MingC"));		//返回以字节为单位的字符串长度（不包括空字符）


	//12.写入格式化数据到字符串
	sprintf_s(str1, SIZE, "%s come up! %d 123", p2, 23423432);
	puts(str1);

	getchar();
	return 0;
}
