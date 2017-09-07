#include <stdio.h>
#include <stdlib.h>

#define TSIZE 45	/*存放影片的数组大小*/
#define FMAX 5		/*最大影片数*/

struct film
{
	char title[TSIZE];
	int rating;
};

int main(void)
{
	struct film movies[FMAX];
	int i = 0;
	int j;

	system("color 0A");
	puts("Enter first movie title (empty line to stop):");
	while (i < FMAX && gets_s(movies[i].title, TSIZE) != NULL
		&& movies[i].title[0] != '\0')
	{
		puts("Enter your rating <0 - 10>:");
		scanf_s("%d", &movies[i].rating, 10);
		movies[i++].rating &= 0xF;
		while (getchar() != '\n')
		{
			;
		}
		puts("Enter next movie title (empty to stop):");
	}
	if (!i)
	{
		puts("No data entered.");
	}
	else
	{
		puts("Here is the list of movies:");
		for (j = 0; j < i; j++)
		{
			printf("Movie: %s Rating: %d.\n", movies[j].title, movies[j].rating);
		}
	}
	puts("\nBye!");

	system("pause");
	return 0;
}