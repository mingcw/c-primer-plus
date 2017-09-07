#define NSIZE 20
#define TSIZE 30

typedef struct name
{
	char first[NSIZE];
	char last[NSIZE];
} NAME;

typedef struct bem
{
	int limbs;
	NAME title;
	char type[TSIZE];
} BEM;