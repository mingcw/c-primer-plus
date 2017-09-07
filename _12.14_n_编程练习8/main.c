#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int arr[], int n);

int main(void)
{
	int size;
	int value;
	int * pa;

	system("color 5A");
	printf("Enter the number of elements: ");
	scanf_s("%d", &size, 10);
	while (size > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value, 10);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements ( < 1 to quit): ");
		scanf_s("%d", &size, 10);
	}
	printf("Done!\n");

	system("pause");
	return 0;
}

int * make_array(int elem, int val)
{
	int * ptr;					//动态分配内存后指向数组首元素的指针

	ptr = (int *)malloc(elem * sizeof (int));
	/*if (!ptr)					//不必写，主程序有检测数组是否创建成功的处理代码
	{
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}*/
	for (int i = 0; i < elem; i++)
	{
		ptr[i] = val;
	}

	return ptr;
}

void show_array(const int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%5d", arr[i]);
		if (i % 8 == 7)
		{
			putchar('\n');
		}
	}
	if (i % 8 != 0)
	{
		putchar('\n');
	}
}