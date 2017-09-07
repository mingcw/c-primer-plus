#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define WORDS "beast"
#define SIZE 41
#define ID_1 1
#define ELAPSE 1000

void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);

int main(void)
{
	char * orig = WORDS;
	char copy[SIZE] = "Be the best that you can be.";;

	system("color 0A");

	puts(WORDS);
	puts(copy);
	strcpy_s(copy + 7, SIZE - 7, orig);
	puts(copy);
	puts(copy + 7);

	/*以下代码是临时写的一个调用相系统API创建定时器的，临时写的，与本节知识点无关
	  强迫症，临时(ˇˍˇ) 想～的，就写了*/
	UINT id = SetTimer(NULL, NULL, ELAPSE, TimerProc);
	MSG msg;

	while (GetMessageW(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	getchar();
	return 0;
}

void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime)
{
	UINT s, min = 0, h = 0;
	
	s = dwTime / 1000;
	if (s >= 60)
	{
		min = s / 60;
		s %= 60;
	}
	if (min >= 60)
	{
		h = min / 60;
		min %= 60;
	}
	printf("Started：%02dh%02dmin%02ds\n", h, min, s);
}