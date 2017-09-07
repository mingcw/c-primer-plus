//产生随机数
static unsigned long int next = 1;					//静态随机数种子（让它具有内部链接而不是空链接是为了在该文件内的2个函数之间共享，暂时没写另一个函数）

int rand0(void);									//rand0()的函数原型（可选的，该文件内并不调用）

int rand0(void)
{
	next = next * 1103515245 + 12345;				//产生伪随机数的魔术般的公式。。。

	return (unsigned int)(next / 65535) % 32768;	//返回值是一个0-32767之间的无符号数
}
