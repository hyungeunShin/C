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
		member member = g_arr.base[i];
		printf("%d : ", i);
		member_print(&member);
	}
}

void con_insert()
{
	printf("[회원 정보 저장]\n\n");
	//변수 선언
	char name[20], phone[20];

	//초기화	
	wb_getstring("이름", name, sizeof(name));
	wb_getstring("전화번호", phone, sizeof(phone));

	//저장 데이터 생성
	member mem = member_createmember(name, phone);

	//저장
	if (arr_insert(&g_arr, mem) == 1)
		printf("저장되었습니다\n");
	else
		printf("저장할 공간이 부족합니다.\n");
}

int nametoidx(const char* name)
{
	for (int i = 0; i < g_arr.size; i++)
	{
		member mem = g_arr.base[i];
		if (strcmp(mem.name, name) == 0)
		{			
			return i;
		}
	}
	return -1;
}

void con_select()
{
	printf("[회원 정보 검색]\n\n");

	char name[20];
	wb_getstring("검색할 이름", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	//member_println(&g_arr.base[idx]);
	member_println(g_arr.base + idx);
}

void con_update()
{
	printf("[회원 정보 수정]\n\n");

	char name[20];
	wb_getstring("검색할 이름(수정할 대상)", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	//수정작업
//	wb_getstring("수정할 전화번호", g_arr.base[idx].phone, sizeof(g_arr.base[idx].phone));

	char phone[20];
	wb_getstring("수정할 전화번호", phone, sizeof(phone));

	strcpy_s(g_arr.base[idx].phone, sizeof(g_arr.base[idx].phone), phone);

	printf("수정되었습니다\n");
}

void con_delete()
{
	printf("[회원 정보 삭제]\n\n");

	char name[20];
	wb_getstring("삭제할 이름", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("해당 이름은 존재하지 않습니다.\n");
		return;
	}

	//삭제
	//1인자 : 시작주소
	//2인자 : 모든 바이트를 0으로 변경
	//3인자 : 시작주소부터 0으로 변경할 사이즈
	memset(&g_arr.base[idx], 0, sizeof(member));
	g_arr.base[idx].flag = 0;	//<--------------------------------------------
	strcpy_s(g_arr.base[idx].name, sizeof(g_arr.base[idx].name), "");
	g_arr.base[idx].phone[0] = '\0';

	printf("삭제되었습니다\n");
}