/*程序调试
#include <stdio.h>
int main(void)
(		//第一处
int n, int n2, int n3;		// 第二处
/*该程序含有几处错误		// 第三处

n=5;
n2=n*n;
n3=n2*n2;		//第四处(由下一句代码"n cubed = %d"知道)
printf("n = %d, n squared = %d, n cubed = %d",n,n2,n3);
return 0;

)		//第一处
*/

//修正后的正确代码
#include <stdio.h>
int main(void)
{
	int n, n2, n3;
	n = 5;
	n2 = n*n;
	n3 = n2*n;
	printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
	getchar();
	return 0;

}