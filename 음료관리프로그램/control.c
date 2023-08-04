//control.c
#include "std.h"

wbarr  g_arr; 

void con_init()
{
	arr_init(&g_arr, 10);
	file_read(&g_arr);
}

void con_exit()
{
	file_write(&g_arr);
	arr_exit(&g_arr);
}

void con_printall()
{
	for (int i = 0; i < g_arr.size; i++)
	{
		drink dr = g_arr.base[i];
		printf("%d : ", i);
		drink_print(&dr);
	}
}

void con_insert()
{
	printf("[제품 정보 저장]\n\n");
	//변수 선언
	char name[20];
	int  price;

	//초기화	
	wb_getstring("이름", name, sizeof(name));
	price = wb_getint("가격");
	
	//저장 데이터 생성
	drink dr = drink_createdrink(name, price);

	//저장
	if (arr_insert(&g_arr, dr) == 1)
		printf("저장되었습니다\n");
	else
		printf("저장할 공간이 부족합니다.\n");
}

int nametoidx(const char* name)
{
	for (int i = 0; i < g_arr.size; i++)
	{
		drink mem = g_arr.base[i];
		if (strcmp(mem.name, name) == 0)
		{			
			return i;
		}
	}
	return -1;
}

void con_select()
{
	printf("[제품 정보 검색]\n\n");

	char name[20];
	wb_getstring("검색할 이름", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	//drink_println(&g_arr.base[idx]);
	drink_println(g_arr.base + idx);
}

void con_update()
{
	printf("[제품 정보 수정]\n\n");

	char name[20];
	wb_getstring("검색할 이름(수정할 대상)", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	//수정작업
	//g_arr.base[idx].price = wb_getint("수정할 가격");

	int price;
	price = wb_getint("수정할 가격");	
	g_arr.base[idx].price = price;

	printf("수정되었습니다\n");
}

void con_delete()
{
	printf("[제품 정보 삭제]\n\n");

	char name[20];
	wb_getstring("삭제할 이름", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	arr_delete(&g_arr, idx);

	printf("삭제되었습니다\n");
}