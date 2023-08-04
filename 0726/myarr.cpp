//myarr.cpp
#include <iostream>
using namespace std;
#include "myarr.h"

//초기화
void mystack_init(mystack *pstack, int max)
{
	pstack->max = max;
	pstack->top = -1;
	pstack->base = (void**)malloc(sizeof(void*)* max); //void* 를 max개 저장할 수 있는 동적배열 요청
}

//종료처리
void mystack_exit(mystack *pstack)
{
	for (int i = 0; i <= pstack->top; i++)
	{
		free(pstack->base[i]);
	}
	free(pstack->base);
}

//오버플로우 검사
int mystack_overflow(const mystack *pstack)
{
	if (pstack->max <= pstack->top + 1)
		return 1;
	else
		return 0;
}

//언더플로우(empty)검사
int mystack_empty(const mystack *pstack)
{
	if (pstack->top == -1)
		return 1;
	else
		return 0;
}

//저장
int mystack_push(mystack *pstack, void *value)
{
	if (mystack_overflow(pstack) == 1)
		return 0;

	pstack->top++;
	pstack->base[pstack->top] = value;
	return 1;
}

//삭제
void* mystack_pop(mystack *pstack)
{
	if (mystack_empty(pstack) == 1)
		return NULL;

	void* pvalue = pstack->base[pstack->top];
	pstack->top--;
	return pvalue;
}

//가장 상단에 있는 데이터 반환
void* mystack_peek(mystack *pstack)
{
	if (mystack_empty(pstack) == 1)
		return NULL;

	return pstack->base[pstack->top];
}