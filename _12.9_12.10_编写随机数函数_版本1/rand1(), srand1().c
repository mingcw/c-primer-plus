/*包含随机数函数和初始化随机数种子函数的文件 */
static unsigned long int next = 1;			//种子

int rand1(void)
{
	next = next * 1103515245 + 12345;		//产生伪随机数的魔术般的公式

	return (unsigned int)(next / 65536) % 32768;

}

void srand1(unsigned int seed)
{
	next = seed;
}