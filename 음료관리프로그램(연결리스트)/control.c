//control.c
#include "std.h"

linkedlist g_list;

void con_init()
{
	list_init(&g_list);
	file_read(&g_list);
}

void con_exit()
{
	file_write(&g_list);
}

void con_printall()
{
	list_next_printall(&g_list);
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
	if (list_frontinsert(&g_list, dr) == 1)
		printf("저장되었습니다\n");
	else
		printf("저장할 공간이 부족합니다.\n");
}

void con_select()
{
	printf("[제품 정보 검색]\n\n");

	char name[20];
	wb_getstring("검색할 이름", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	drink_println(&cur->data);
}

void con_update()
{
	printf("[제품 정보 수정]\n\n");

	char name[20];
	wb_getstring("검색할 이름(수정할 대상)", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	int price;
	price = wb_getint("수정할 가격");	
	cur->data.price = price;

	printf("수정되었습니다\n");
}

void con_delete()
{
	printf("[제품 정보 삭제]\n\n");

	char name[20];
	wb_getstring("삭제할 이름", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}
	
	list_nodedelete(&g_list, cur);

	printf("삭제되었습니다\n");
}