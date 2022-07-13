#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

void test1()
{
	PhoneBook PB;
	InitContact(&PB);

	AddContact(&PB);
	AddContact(&PB);
	AddContact(&PB);
	AddContact(&PB);

	FindContact(&PB);

	RevContact(&PB);

	SortContact(&PB);

	DelContact(&PB);

	PrintContact(&PB);

}


int main()
{
	test1();

	return 0;
}