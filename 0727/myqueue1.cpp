//myqueue1.cpp
#include <iostream>
using namespace std;
#include "myqueue1.h"


//���� ��ȯ
int myqueue_count(myqueue1* pqueue)
{
	int count = 0;
	if (pqueue->rear >= pqueue->front)
	{
		count = pqueue->rear - pqueue->front;
	}
	else
	{
		count = (pqueue->rear + pqueue->max) - pqueue->front;
	}
	return count;
}


//�ʱ�ȭ
void myqueue_init(myqueue1* pqueue, int max)
{
	pqueue->max = max;
	pqueue->rear = 0;
	pqueue->front = 0;
	pqueue->base = (void**)malloc(sizeof(void*) * max); //void* �� max�� ������ �� �ִ� �����迭 ��û
	for (int i = 0; i < max; i++)
	{
		pqueue->base[i] = NULL;
	}
}

//����ó��
void myqueue_exit(myqueue1* pqueue)
{
	for (int i = 0; i < pqueue->max; i++)
	{
		if( pqueue->base[i] != NULL)
			free(pqueue->base[i]);
	}

	free(pqueue->base);
}

//�����÷ο� �˻�
int myqueue_overflow(const myqueue1* pqueue)
{
	if ((pqueue->rear + 1) % pqueue->max == pqueue->front)
		return 1;
	else
		return 0;
}
//����÷ο�(empty)�˻�
int myqueue_empty(const myqueue1* pqueue)
{
	if (pqueue->rear == pqueue->front)
		return 1;
	else
		return 0;
}

//����
int myqueue_put(myqueue1* pqueue, void* value)
{
	if (myqueue_overflow(pqueue) == 1)
		return 0;

	pqueue->base[pqueue->rear] = value;
	pqueue->rear = (pqueue->rear + 1) % pqueue->max;	//���� �̵�
	return 1;
}
//����
void* myqueue_get(myqueue1* pqueue)
{
	if (myqueue_empty(pqueue) == 1)
		return 0;

	void* temp = pqueue->base[pqueue->front];
	pqueue->front = (pqueue->front + 1) % pqueue->max;
	return temp;
}

//���� ��ܿ� �ִ� ������ ��ȯ
void* myqueue_peek(myqueue1* pqueue)
{
	if (myqueue_empty(pqueue) == 1)
		return NULL;

	return pqueue->base[pqueue->front];
}
