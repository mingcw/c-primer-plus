#include <stdio.h>

const int S_PER_M = 60;		//每分钟的秒数
const int S_PER_H = 3600;	//每小时的秒数
double M_PER_K = 0.62137;	//每公里的英里数

int main(void)
{	
	//计算长跑的运动数据

	double distK, distM;	//以公里和英里计的距离
	double rate;			//平均速度（单位：英里每小时）
	int min, sec;			//分钟数和秒数
	int time;				//总秒数
	double mTime;			//跑完1英里的用时（单位：秒）
	int mMin, mSec;			//跑完1英里的用时，分钟+秒数

	printf("This program converts your time for a metric race\n");
	printf("to a time for running a mile and to your average\n");
	printf("speed in miles per hour.\n");
	printf("Please enter, in kilometre, a distance run:\n");
	scanf_s("%lf",&distK,10);	//格式化扫描输入一个double类型值
	printf("Next enter the time in minutes and seconds.\n");
	printf("Bengin by entering the minutes:\n");
	scanf_s("%d", &min,10);
	printf("Now enter the seconds:\n");
	scanf_s("%d", &sec,10);
	//把时间转换为秒
	time = min * S_PER_M + sec;
	//把公里转换为英里
	distM = distK * M_PER_K;
	//英里/秒*秒/小数 =英里/小时
	rate = distM / time * S_PER_H;
	//时间/距离=跑完每英里的用时
	mTime = (double)time / distM;
	mMin = (int)mTime / S_PER_M;	//算出分钟数
	mSec = (int)mTime % S_PER_M;	//算出剩余秒数
	printf("You ran %1.2f kilometers(%1.2f miles) in %d min, %d sec\n",
		distK, distM, min, sec);
	printf("That pace corresponds to running a mile in %d min ",
		mMin);
	printf("%d sec.\nYour average speed was %1.2f mph\n",
		mSec, rate);

	getchar();
	getchar();
	return 0;
}