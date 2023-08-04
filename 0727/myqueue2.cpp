//myqueue2.cpp
#include <iostream>
using namespace std;
#include "myqueue2.h"

myqueue2::myqueue2(int _max /*= 10*/) : max(_max), rear(0), front(0)
{
	base = new void*[max]; //void* 를 max개 저장할 수 있는 동적배열 요청
	for (int i = 0; i < max; i++)
	{
		base[i] = NULL;
	}
}

myqueue2::~myqueue2()
{
	for (int i = 0; i < max; i++)
	{
		if (base[i] != NULL)
			free(base[i]);
	}
	free(base);
}

//개수 반환
int myqueue2::count()
{
	int count = 0;
	if (rear >= front)
	{
		count = rear - front;
	}
	else
	{
		count = (rear + max) - front;
	}
	return count;
}

//오버플로우 검사
bool myqueue2::overflow()
{
	if ((rear + 1) % max == front)
		return true;
	else
		return false;
}

//언더플로우(empty)검사
bool myqueue2::empty()
{
	if (rear == front)
		return true;
	else
		return false;
}

//저장
bool myqueue2::put(void* value)
{
	if (overflow() == true)
		return false;

	base[rear] = value;
	rear = (rear + 1) % max;	//원형 이동
	return true;
}

//삭제
void* myqueue2::get()
{
	if (empty() == true)
		return NULL;

	void* temp = base[front];
	front = (front + 1) % max;
	return temp;
}

//가장 상단에 있는 데이터 반환
void* myqueue2::peek()
{
	if (empty() == true)
		return NULL;

	return base[front];
}