#include <stdio.h>
#include <stdlib.h>

#define CTRL_Z '\32'			//DOS文本文件中的文件结尾标记
#define SLEN 51

int main(void)
{
	/*反序显示一个文件

	方法：打开文件，用fseek()定位到文件结尾,用ftell()获取当前读写的字节位置，
	依次向前取一个字符并回显，直到取出的字符为MOS-DOS文本文件的文件结尾或LINUX文本文件的行尾\r时，结束回显
	
	新函数：
	fseek()：设置文件流的读写位置,失败返回非0错误码（移动超出文件范围，返回-1）（具体信息请查阅MSDN）
	ftell()：获取当前读写的字节位置（...）*/

	char file[SLEN];
	char ch;
	FILE * fp;
	long count, last;

	system("color 5A");
	puts("Enter the name of the file to be processed:");
	gets_s(file, SLEN);
	if (fopen_s(&fp, file, "rb"))
	{				//只读和二进制模式
		printf("reverse can't open %s \n", file);		//打开失败异常退出
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);							//定位到文件结尾
					//常量宏，文件结尾标识
	last = ftell(fp);									//标记当前位置，即文件尾
					//ftell()接受文件流指针，返回文件的当前位置
	for (count = 0L; count < last; count++)
	{
		fseek(fp, count, SEEK_SET);					//回退
		ch = getc(fp);

		/*检查是否文件尾字符，或者是否回车符
		（1.二进制文件的行尾用\r\n标识，在输出时剔除回车符的影响）
		2.文本文件的行尾C是可以识别的，会将\r\n视作\n字符，
		所以文本视图的DOS文件只需检查是否文件尾字符决定是否继续打印，
		而二进制文件不只检查是否文件尾字符，也要剔除行尾的回车符，然后决定是否打印）*/
		//针对DOS，在Unix下也可工作
		if (ch != CTRL_Z && ch != '\r')						/*1.在文本视图下，C可以认出结尾字符是标识文件结尾的字符
															  2.二进制模式打开的MS_DOS文件（Windows NT向DOS兼容）：
																（1）它的文件结尾被C视作文件中的一个字符（CTRL_Z），即'\32'，
																（2）二进制打开的文件行尾用\r\n标识，所以为了防止打印回车符，必须在打印前检测和剔除掉回车符

															  3.之所以选择二进制打开文件，是因为ftell()函数返回距文件开始处的字节数目来确定文件位置，
																在ASCI C下，这种定义只适用于以二进制模式打开的文件*/
		{
			putchar(ch);
		}
		//针对Macintosh
		/*if (ch == '\r'){putchar(ch);}else{putchar(ch);}*/
	}
	
	putchar('\n');
	fclose(fp);
	

	system("pause");
	return 0;
}