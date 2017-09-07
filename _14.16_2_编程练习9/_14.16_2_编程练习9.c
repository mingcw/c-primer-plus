/*
	扩充第8题，现有另一架灰机，可以灰4个航班：102、311、444、519。
	......
	原题要求是根据第7题的菜单模式来写，觉得不好；所以离开题目要求，将第8题扩充实现，功能就强了些。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAMESIZE 21
#define SEATSIZE 12
#define FLIGHTSIZE 4

#define FILENAME "flight.dat"

struct name
{
	char fname[NAMESIZE];
	char lname[NAMESIZE];
};

typedef struct name NAME;

struct seat
{
	int num;
	bool assign;
	NAME passenger;
};

typedef struct seat SEAT;

struct flight
{
	int num;
	SEAT seats[SEATSIZE];
};

typedef struct flight FLIGHT;

bool get_info(FLIGHT flights[], int n);
void initial_num(FLIGHT flights[], int n);
void show_topmenu(void);
char get_topchoice(void);
void eatline(void);
void show_submenu(int flight_num);
char get_subchoice(void);
void empty_seats_count(const FLIGHT * pflight, int index);
int  get_flight_index(char topchoice);
void empty_seats_list(const FLIGHT * pflight, int index);
void alpha_seats_list(FLIGHT * pflight, int index);
void assign_seat(FLIGHT * pflight, int index);
void Delete_assignment(FLIGHT * pflight, int index);
void save_info(FLIGHT flights[], int n);

int  main(void)
{
	FLIGHT flights[FLIGHTSIZE] = { 0 };
	char topchoice, subchoice;
	bool IsRecExist;
	int index;

	system("color 5A");
	//获取数据
	IsRecExist = get_info(flights, FLIGHTSIZE);
	if (!IsRecExist)
	{
		initial_num(flights, FLIGHTSIZE);
	}
topmenu:
	show_topmenu();
	topchoice = get_topchoice();
	index = get_flight_index(topchoice);
	if (topchoice != 'e')
	{
		show_submenu(flights[index].num);
		subchoice = get_subchoice();
		while (subchoice != 'g')
		{
			switch (subchoice)
			{
			case 'a':
				empty_seats_count(flights, index);
				break;
			case 'b':
				empty_seats_list(flights, index);
				break;
			case 'c':
				alpha_seats_list(flights, index);
				break;
			case 'd':
				assign_seat(flights, index);
				break;
			case 'e':
				Delete_assignment(flights, index);
				break;
			case 'f':
				goto topmenu;
				break;
			}
			show_submenu(flights[index].num);
			subchoice = get_subchoice();
		}
	}
	puts("Bye!");
	//保存信息
	save_info(flights, FLIGHTSIZE);

	system("pause");
	return 0;

}

bool get_info(FLIGHT flights[], int n)
{
	FILE * fp;
	int count = 0;
	bool IsRecExist = false;
	size_t size = sizeof(FLIGHT);

	if (fopen_s(&fp, FILENAME, "a+b") != 0)
	{
		puts("Can't open file.");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	if (fread(flights, size, FLIGHTSIZE, fp) == 4)
	{
		IsRecExist = true;
	}
	fclose(fp);

	return IsRecExist;
}

void initial_num(FLIGHT flights[], int n)
{
	flights[0].num = 102;
	flights[1].num = 311;
	flights[2].num = 444;
	flights[3].num = 519;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < SEATSIZE; j++)
		{
			flights[i].seats[j].num = j + 101;
		}
	}
}

void show_topmenu(void)
{
	puts("To choose a flight, enter its letter label:");
	puts("a) Flitht 102");
	puts("b) Flitht 311");
	puts("c) Flitht 444");
	puts("d) Flitht 519");
	puts("e) Quit");
}

char get_topchoice(void)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("abcde", ch) == NULL)
	{
		puts("Please enter a, b, c, d or e:");
		ch = tolower(getchar());
		eatline();
	}

	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void show_submenu(int flight_num)
{
	printf("F%d: enter a letter label:\n", flight_num);
	puts("a) Show num of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Return topmenu");
	puts("g) Quit");
}

char get_subchoice(void)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("abcdefg", ch) == NULL)
	{
		puts("Please enter a, b, c, d, e, f or g:");
		ch = tolower(getchar());
		eatline();
	}

	return ch;
}

void empty_seats_count(const FLIGHT * pflight, int index)
{
	int total = 0;

	for (int i = 0; i < SEATSIZE; i++)
	{
		if ((pflight + index)->seats[i].assign == false)
		{
			total++;
		}
	}

	if (total)
	{
		printf("F%d: Empty seats' number: %d\n", (pflight + index)->num, total);
	}
	else
	{
		puts("0");
	}
}

int  get_flight_index(char topchoice)
{
	int i = 0;

	switch (topchoice)
	{
	case 'a':i = 0; break;
	case 'b':i = 1; break;
	case 'c':i = 2; break;
	case 'd':i = 3; break;
	}

	return i;
}

void empty_seats_list(const FLIGHT * pflight, int index)
{
	bool IsExist = false;

	for (int i = 0; i < SEATSIZE; i++)
	{
		if ((pflight + index)->seats[i].assign == false)
		{
			printf("%6s %5s %9s %11s\n", "Flight", "Num", "Assign", "Passenger");
			printf(" F%d %6d %6d %10s %-17s\n", (pflight + index)->num, (pflight + index)->seats[i].num, (pflight + index)->seats[i].assign,
				(pflight + index)->seats[i].passenger.fname, (pflight + index)->seats[i].passenger.lname);
			IsExist = true;
		}
	}

	if (!IsExist)
	{
		puts("Has no empty seats.");
	}
}

void alpha_seats_list(FLIGHT * pflight, int index)
{
	SEAT temp;

	//排序
	for (int i = 0; i < SEATSIZE - 1; i++)
	{
		for (int j = 0; j < SEATSIZE - 1 - i; j++)
		{
			if (strcmp((pflight + index)->seats[j].passenger.fname,
				(pflight + index)->seats[j + 1].passenger.fname) > 0)
			{
				temp = (pflight + index)->seats[j];
				(pflight + index)->seats[j] = (pflight + index)->seats[j + 1];
				(pflight + index)->seats[j + 1] = temp;
			}
		}
	}

	//显示
	printf("%6s %5s %9s %11s\n", "Flight", "Num", "Assign", "Passenger");
	for (int i = 0; i < SEATSIZE; i++)
	{
		printf(" F%d %6d %6d %10s %-17s\n", (pflight + index)->num, (pflight + index)->seats[i].num, (pflight + index)->seats[i].assign,
			(pflight + index)->seats[i].passenger.fname, (pflight + index)->seats[i].passenger.lname);
	}
}

void assign_seat(FLIGHT * pflight, int index)
{
	int seat_index = -1;

	//查空座
	for (int i = 0; i < SEATSIZE; i++)
	{
		if ((pflight + index)->seats[i].assign == false)
		{
			seat_index = i;
			break;
		}
	}

	//读入乘客信息
	if (seat_index != -1)
	{
		printf("F%d: the seat-number is %d\n", (pflight + index)->num, (pflight + index)->seats[seat_index].num);
		puts("Please enter the first name of passage:");
		gets_s((pflight + index)->seats[seat_index].passenger.fname, NAMESIZE);
		puts("Last name:");
		gets_s((pflight + index)->seats[seat_index].passenger.lname, NAMESIZE);
		(pflight + index)->seats[seat_index].assign = true;
		//反馈预定成功
		printf("Success! Flight: F%d, Seat: %d, Passenger: %s %-s\n",
			(pflight + index)->num, (pflight + index)->seats[seat_index].num,
			(pflight + index)->seats[seat_index].passenger.fname, (pflight + index)->seats[seat_index].passenger.lname);
	}
	else
	{
		puts("Sorry, all seats has been assigned.");
	}
}

void Delete_assignment(FLIGHT * pflight, int index)
{
	int num;
	NAME zero = { "", "" };
	bool success = false;

	printf("F%d: input seat-number to delete assignment:", (pflight + index)->num);
	if (scanf_s("%d", &num, 10) == 1)
	{
		for (int i = 0; i < SEATSIZE; i++)
		{
			if ((pflight + index)->seats[i].num == num)
			{
				(pflight + index)->seats[i].assign = false;
				(pflight + index)->seats[i].passenger = zero;
				puts("Delete success.");
				success = true;
				break;
			}
		}
		if (!success)
		{
			puts("No valid seat_number.");
		}
	}
	else
	{
		puts("Input error.");
	}

	eatline();
}

void save_info(FLIGHT flights[], int n)
{
	FILE * fp;
	int count = 0;
	size_t size = sizeof(FLIGHT);

	if (fopen_s(&fp, FILENAME, "wb") != 0)
	{
		puts("Can't open file.");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	fwrite(flights, size, n, fp);
	fclose(fp);
}
