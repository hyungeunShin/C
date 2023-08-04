//member.c

#include "std.h"

void member_print(const member *pmem)
{
	printf("%s\t", pmem->name);   // (*pmem).name;
	printf("%s\n", pmem->phone);
}

void member_println(const member *pmem)
{
	printf("이    름 : %s\n", pmem->name);
	printf("전화번호 : %s\n", pmem->phone);
}


member member_createmember(const char* name, const char* phone)
{
	member mem;

	mem.flag = 1; //<-------------------------------------------------------
	strcpy_s(mem.name, sizeof(mem.name), name);
	strcpy_s(mem.phone, sizeof(mem.phone), phone);

	return mem;
}