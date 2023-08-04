//myqueue1.cpp
#include <iostream>
using namespace std;
#include "myqueue1.h"


//개수 반환
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


//초기화
void myqueue_init(myqueue1* pqueue, int max)
{
	pqueue->max = max;
	pqueue->rear = 0;
	pqueue->front = 0;
	pqueue->base = (void**)malloc(sizeof(void*) * max); //void* 를 max개 저장할 수 있는 동적배열 요청
	for (int i = 0; i < max; i++)
	{
		pqueue->base[i] = NULL;
	}
}

//종료처리
void myqueue_exit(myqueue1* pqueue)
{
	for (int i = 0; i < pqueue->max; i++)
	{
		if( pqueue->base[i] != NULL)
			free(pqueue->base[i]);
	}

	free(pqueue->base);
}

//오버플로우 검사
int myqueue_overflow(const myqueue1* pqueue)
{
	if ((pqueue->rear + 1) % pqueue->max == pqueue->front)
		return 1;
	else
		return 0;
}
//언더플로우(empty)검사
int myqueue_empty(const myqueue1* pqueue)
{
	if (pqueue->rear == pqueue->front)
		return 1;
	else
		return 0;
}

//저장
int myqueue_put(myqueue1* pqueue, void* value)
{
	if (myqueue_overflow(pqueue) == 1)
		return 0;

	pqueue->base[pqueue->rear] = value;
	pqueue->rear = (pqueue->rear + 1) % pqueue->max;	//원형 이동
	return 1;
}
//삭제
void* myqueue_get(myqueue1* pqueue)
{
	if (myqueue_empty(pqueue) == 1)
		return 0;

	void* temp = pqueue->base[pqueue->front];
	pqueue->front = (pqueue->front + 1) % pqueue->max;
	return temp;
}

//가장 상단에 있는 데이터 반환
void* myqueue_peek(myqueue1* pqueue)
{
	if (myqueue_empty(pqueue) == 1)
		return NULL;

	return pqueue->base[pqueue->front];
}
