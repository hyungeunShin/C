//myarr.cpp
#include <iostream>
using namespace std;
#include "myarr.h"

//�ʱ�ȭ
void mystack_init(mystack *pstack, int max)
{
	pstack->max = max;
	pstack->top = -1;
	pstack->base = (void**)malloc(sizeof(void*)* max); //void* �� max�� ������ �� �ִ� �����迭 ��û
}

//����ó��
void mystack_exit(mystack *pstack)
{
	for (int i = 0; i <= pstack->top; i++)
	{
		free(pstack->base[i]);
	}
	free(pstack->base);
}

//�����÷ο� �˻�
int mystack_overflow(const mystack *pstack)
{
	if (pstack->max <= pstack->top + 1)
		return 1;
	else
		return 0;
}

//����÷ο�(empty)�˻�
int mystack_empty(const mystack *pstack)
{
	if (pstack->top == -1)
		return 1;
	else
		return 0;
}

//����
int mystack_push(mystack *pstack, void *value)
{
	if (mystack_overflow(pstack) == 1)
		return 0;

	pstack->top++;
	pstack->base[pstack->top] = value;
	return 1;
}

//����
void* mystack_pop(mystack *pstack)
{
	if (mystack_empty(pstack) == 1)
		return NULL;

	void* pvalue = pstack->base[pstack->top];
	pstack->top--;
	return pvalue;
}

//���� ��ܿ� �ִ� ������ ��ȯ
void* mystack_peek(mystack *pstack)
{
	if (mystack_empty(pstack) == 1)
		return NULL;

	return pstack->base[pstack->top];
}