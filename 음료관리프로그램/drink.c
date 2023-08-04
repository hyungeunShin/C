//member.c

#include "std.h"

void drink_print(const drink *pdrink)
{
	printf("%s\t", pdrink->name);   
	printf("%d��\n", pdrink->price);
}

void drink_println(const drink *pdrink)
{
	printf("��    �� : %s\n", pdrink->name);
	printf("��    �� : %d��\n", pdrink->price);
}


drink drink_createdrink(const char* name, int price)
{
	drink dr;

	strcpy_s(dr.name, sizeof(dr.name), name);
	dr.price = price;

	return dr;
}