/*
	前言：我的编译器不支持变长数组，所以不写代码，主分析函数功能、区别、和优劣

	VLA与malloc()在功能类似： 创建一个大小在运行时决定的数组，例如：
				int vlamn(void)
				{
					int n;
					int * pi;
					scanf("%d",&n);

					pi = (int *)malloc(n * sizeof(int));		//为数组动态分配n个int的内存
					int arr[n];									//VLA

					pi[2] = ar[2] = -5;
					...
				}

	区别：	VLA是自动存储类,函数vlamn()终止的时候，VLA占用的内存被自动释放

			malloc()创建的数组不必局限在一个函数里（函数实际是在运行期间分配了内存块），
					函数可以创建一个数组并返回指向指针给主调函数，主调函数可以通过该指针访问数组（内存块）,主调函数访问数组结束之后可以用free()释放内存
	
	VLA的优点：对多维数组来说更方便
	而malloc()创建多维数组，语法很麻烦：例如

	int n = 5;
	int m = 6;

`	int ar2[n][m];		//n x m 的VLA
	
	int (* p2)[6];		//指向6个int的指针
	int (* p3)[m];		//指向m个int的指针，需要VLA数组的支持

	p2 = (int (*)[6])malloc(n * 6 * sizeof(int));			//分配内存创建，n x 6的数组
	p3 = (int (*)[m])malloc(n * m * sizeof(int));			//需要变长数组的支持

	ar2[1][2] =  p2[1][2] = 12;
	*/	