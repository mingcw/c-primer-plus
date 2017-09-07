#include <stdio.h>
#include<math.h>

int main(void)
{
	float about = 43215.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;

	//打印浮点数
	printf("%f ★ %e ★ %E ★ %a ★ %A\n", about, about, about, about, about);		//%e(%E)是按照e(指数/科学)计数法打印，%a(%A)打印成十六进制
	printf("%lf ★ %e ★ %E ★ %a ★ %A\n", abet, abet, abet, abet, abet);
	printf("%f ★ %e ★ %E ★ %a ★ %A\n\n", dip, dip, dip, dip, dip);

	//浮点数的上溢
	float toobig = 3.4e38*100.0f;		//3.4e38*100.0f的结果超出float范围，数据上溢，printf()打印出一个代表无穷大的特殊值xx#INFxx,infinity或inf之类的
	printf("%f\n\n", toobig);		//1.#INF00

	//浮点数的下溢 太复杂，暂且不论O(∩_∩)O
	/*另外，有一个特殊的浮点数"NaN"(Not a Number).如asin()反正弦函数的参数必须在(0,1)之间(正弦函数的值域是(0,1)),
	  绝对没有超出1的正弦值(参数)，如果输入(0,1)以外的参数，返回值为NaN，即不是一个数，printf()函数将此值打印为xx#INDxx,nan,NaN,或类似形式，示例如下*/
	double fl = asin(1.1e3);
	printf("%f\n", fl);  //-1.#IND00

	getchar();
	return 0;

}