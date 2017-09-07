#include <stdio.h>
#include <ctype.h>		//提供issapce()的函数原型
#include <stdbool.h>	//提供bool,true,false的定义

#define STOP '|'

int main(void)
{
	char ch;				//读入字符
	char prev;				//前一个读入字符
	long  n_chars = 0L;		//字符数
	int n_lines = 0;			//行数
	int n_words = 0;			//单词数
	int p_lines = 0;			//不完整的行数
	bool inWord = false;	//标记一个单词的开始，如果ch在一个单词里，则inWord == true

	printf("Please enter text to be analyzed (| to terminate):\n");
	prev = '\n';			//识别完整的行
	while ((ch = getchar())!= STOP)
	{
		n_chars++;		//统计字符
		if (ch == '\n')
		{
			n_lines++;	//统计行
		}	
		if (!isspace(ch) && !inWord)		//如果ch不是空白字符，并且ch不处于一个单词里
		{
			inWord = true;		//开始一个新单词
			n_words++;			//统计单词
		}
		if (isspace(ch) && inWord)		//如果ch是空白字符，并且ch处于一个单词里
		{
			inWord = false;		//到达单词的尾部
		}
		prev = ch;				//保存字符值
	}
	if (prev != '\n')
	{
		p_lines = 1;
	}
	printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
	printf("partical lines = %d\n", p_lines);

	getchar();
	getchar();
	getchar();
	return 0;
}