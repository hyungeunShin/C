//control.c
#include "std.h"

int g_flag[10], g_c[10], g_cpp[10], g_struct[10];	

void con_printall()
{
	printf("인덱스\tC언어\tC++언어\t자료구조\t합계\t평균\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{		
		printf("[%02d]\t%d\t%d\t%d\t\t%d\t%.1f\n", 
			i, g_c[i], g_cpp[i], g_struct[i],				 //인덱스, 과목별 점수
			g_c[i] + g_cpp[i] + g_struct[i],				 //합
			(g_c[i] + g_cpp[i] + g_struct[i]) / 3.0f);		 //평균 (정수 / 실수)
	}
}

void con_insert()
{
	int idx, c, cpp, st;

	printf("인덱스(0~9) : ");			scanf_s("%d", &idx);
	printf("C언어     점수 : ");		scanf_s("%d", &c);
	printf("C++언어   점수 : ");		scanf_s("%d", &cpp);
	printf("자료구조  점수 : ");		scanf_s("%d", &st);
	//-------------------------------------------------
	
	if (idx < 0 || idx >9)
	{
		printf("잘못된 인덱스 입니다.\n");
	}
	else if (g_flag[idx] != 0)
	{
		printf("값이 존재합니다.\n");
	}
	else
	{
		g_flag[idx] = 1;	//<---------------------------------
		g_c[idx] = c;
		g_cpp[idx] = cpp;
		g_struct[idx] = st;
		printf("저장되었습니다.\n");
	}
}

void con_update()
{
	int idx, c, cpp, st;

	printf("인덱스(0~9) : ");				scanf_s("%d", &idx);
	printf("C언어     점수 수정 : ");		scanf_s("%d", &c);
	printf("C++언어   점수 수정 : ");		scanf_s("%d", &cpp);
	printf("자료구조  점수 수정 : ");		scanf_s("%d", &st);
	//-------------------------------------------------

	if (idx < 0 || idx >9)
	{
		printf("잘못된 인덱스 입니다.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("값이 존재하지 않습니다.\n");
	}
	else
	{
		g_c[idx]		= c;
		g_cpp[idx]		= cpp;
		g_struct[idx]	= st;
		printf("수정되었습니다.\n");
	}
}

void con_select()
{
	int idx;

	printf("인덱스(0~9) : ");
	scanf_s("%d", &idx);

	if (idx < 0 || idx >9)
	{
		printf("잘못된 인덱스 입니다.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("값이 존재하지 않습니다.\n");
	}
	else
	{
		printf("C언어     점수 : %d점\n", g_c[idx]);
		printf("C++언어   점수 : %d점\n", g_cpp[idx]);
		printf("자료구조  점수 : %d점\n", g_struct[idx]);
		printf("합             : %d점\n", g_c[idx] + g_cpp[idx] + g_struct[idx]);
		printf("평균           : %.1f점\n", (g_c[idx] + g_cpp[idx] + g_struct[idx])/3.0f);
	}
}

void con_delete()
{
	int idx;

	printf("삭제할 인덱스(0~9) : ");
	scanf_s("%d", &idx);

	if (idx < 0 || idx >9)
	{
		printf("잘못된 인덱스 입니다.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("값이 존재하지 않습니다.\n");
	}
	else
	{
		g_flag[idx]		= 0;
		g_c[idx]		= 0;
		g_cpp[idx]		= 0;
		g_struct[idx]	= 0;
		printf("삭제되었습니다.\n");
	}
}