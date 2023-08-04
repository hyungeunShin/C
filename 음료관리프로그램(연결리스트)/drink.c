//member.c

#include "std.h"

void drink_print(const drink *pdrink)
{
	printf("%s\t", pdrink->name);   
	printf("%d원\n", pdrink->price);
}

void drink_println(const drink *pdrink)
{
	printf("이    름 : %s\n", pdrink->name);
	printf("가    격 : %d원\n", pdrink->price);
}


drink drink_createdrink(const char* name, int price)
{
	drink dr;

	strcpy_s(dr.name, sizeof(dr.name), name);
	dr.price = price;

	return dr;
}