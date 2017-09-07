#include <stdio.h>
#include <stdlib.h>

#define COLOR system("COLOR 0A")

int main(void)
{
	int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };
	int(*pz)[2];  //pz是指向包含2个int的数组的指针

	pz = zippo;
	
	COLOR;
	printf("zippo: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%7d", zippo[i][j]);
		}
		putchar('\n');
	}

	printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
	printf("pz[o] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
	printf("  *pz = %p,   *pz + 1 = %p\n\n", *pz, *pz + 1);

	printf("pz[0][0] = %d\n", pz[0][0]);
	printf("  *pz[0] = %d\n", *pz[0]);
	printf("    **pz = %d\n\n", **pz);

	printf("pz[2][1] = %d\n", pz[2][1]);
	printf("*(*(pz + 2) + 1) = %d\n\n", *(*(pz + 2) + 1));

	getchar();
	return 0;
}