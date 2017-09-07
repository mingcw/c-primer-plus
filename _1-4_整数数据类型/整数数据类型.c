#include <stdio.h>

int main(void)
{
	unsigned int un = 3000000000;			//(unsigned)int四字节32位
	//printf("%d\n", sizeof(unsigned int));  4
	short end = 200;						//short二字节16位，
	//printf("%d\n", sizeof(short));	2
	long big = 65537;						//long四字节32位
	//printf("%d\n", sizeof(long));  4
	long long verybig = 12345678765433345632;		//long long八字节64位
	//printf("%\nd", sizeof(long long));  8

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and not %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);
	printf("\n数据的存储范围大小依次是 short16位<int32位=long32位<long long64位");
	getchar();
	return 0;

}