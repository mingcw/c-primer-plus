#include<stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);		//可以省略名称
int sum2d(int (*pt)[COLS], int rows);	//另一种语法形式

int main(void)
{
	int junk[ROWS][COLS] = {
		{ 2, 4, 6, 8 },
		{ 3, 5, 7, 9 },
		{ 12, 10, 8, 6}
	};

	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

	getchar();
	return 0;
}

//计算每行的和
void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;

	for (r = 0; r < rows; r++)
	{
		tot = 0;
		for (c = 0; c < COLS; c++)  //计算一行的所有列的和
			tot += ar[r][c];
		printf("row %d: sum = %d\n", r, tot);

	}
}

//计算每列的和
void sum_cols(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;

	for (c = 0; c < COLS; c++)
	{
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
		printf("col %d: sum = %d\n", c, tot);
	}
}

//计算二维数组元素和
int sum2d(int ar[][COLS], int rows)	/*编译器会把数组符号转换成指针符号，“int ar[][4]”表示ar是指向包含4个int的数组的指针，
										也可以在另一对方括号中填写大小，即“int ar[3][4]”，但编译器将忽略之
										
									一般地，声明N维数组的指针时，除了最左边的方括号可以省略外，其他都需要填写数值

									int sum4d(int ar[][12][20][30], int rows);
									首方括号表示这是一个指针，而其他方括号描述的是所指向对象的数据类型，等效声明如下：
									int sum4d(int (*ar)[12][20][30],int rows);		//ar是一个指针
									ar指向一个12 x 20 x 30的int数组

									另外，数组的维数必须是常量，不能用变量代替COLS*/
{
	int r;
	int c;
	int tot = 0;

	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	}
	
	return tot;
}

//typedef int arr4[4];				//声明类型，arr4是4个int的数组
//typedef arr4 arr3x4[3];			//。。。。，arr3x4是3个arr4的数组

//int sum2(arr3x4 ar, int rows);	//同下
//int sum2(int ar[3][4], int rows);	//同下
//int sum2(int ar[][4], int rows);	//标准形式
