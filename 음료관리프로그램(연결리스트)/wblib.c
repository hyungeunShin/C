//wblib.c
#include "std.h"

int wb_getint(const char* msg)
{
	int num;
	printf("%s : ", msg);
	scanf_s("%d", &num);
	char dummy = getchar();		//<---------------------
	return num;
}

char wb_getchar(const char* msg)
{
	char ch;
	printf("%s : ", msg);
	scanf_s("%c", &ch);
	char dummy = getchar();		//<---------------------
	return ch;
}

void wb_getstring(const char* msg, char *inputstr, int size)
{
	char str[50];
	printf("%s : ", msg);
	gets_s(str, sizeof(str));

	strcpy_s(inputstr, size, str);
}