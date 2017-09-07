#include <stdio.h>
#include <stdlib.h>

#define SIZEAR 1000

int main(int argc, char * argv[])
{
	/*随机存取最常用于使用二进制IO写入的二进制文件：
	程序功能：创建一个double类型数值的文件，允许用户访问文件内的数值内容
	
	注意：文件IO最好用二进制模式打开、二进制IO函数进行IO、也提供了文件定位函数准确字节计数值*/

	double numbers[SIZEAR];
	double value;
	const char * file = "numbers.dat";
	int i;
	long pos;
	FILE * iofile;

	system("COLOR 0A");
	//创建double数组
	for (i = 0; i < SIZEAR; i++)
	{
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	}

	//尝试打开文件（w方式打开二进制流）
	if (fopen_s(&iofile, file, "wb") != 0)
	{
		fprintf(stderr, "Can't open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}

	//把数组内容以二进制形式写到文件
	fwrite(numbers, sizeof(double), SIZEAR, iofile);
	if (ferror(iofile) != 0)
	{
		fprintf(stderr, "Error in writing %s.\n", file);
		exit(EXIT_FAILURE);
	}
	fclose(iofile);

	//打开二进制输入流，r模式
	if (fopen(&iofile, file, "rb") != 0)
	{
		fprintf(stderr, "Can't open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}

	//获取下标
	printf("Enter an index in 0 - %d:\n", SIZEAR - 1);
	scanf_s("%d", &i, 10);

	//下标在数组内时，定位到指定位置，二进制形式取出一个double值
	while (i >= 0 && i < SIZEAR)
	{
		pos = (long)i * sizeof(double);			//计算偏移量
		fseek(iofile, pos, SEEK_SET);			//定位到指定偏移处
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f\n", value);
		printf("Next index (out of range < 0 - %d> to quit):\n", SIZEAR - 1);
		scanf_s("%d", &i, 10);
	}
	fclose(iofile);
	puts("Bye!");

	system("pause");
	return 0;
}