//myqueue2.cpp
#include <iostream>
using namespace std;
#include "myqueue2.h"

myqueue2::myqueue2(int _max /*= 10*/) : max(_max), rear(0), front(0)
{
	base = new void*[max]; //void* �� max�� ������ �� �ִ� �����迭 ��û
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

//���� ��ȯ
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

//�����÷ο� �˻�
bool myqueue2::overflow()
{
	if ((rear + 1) % max == front)
		return true;
	else
		return false;
}

//����÷ο�(empty)�˻�
bool myqueue2::empty()
{
	if (rear == front)
		return true;
	else
		return false;
}

//����
bool myqueue2::put(void* value)
{
	if (overflow() == true)
		return false;

	base[rear] = value;
	rear = (rear + 1) % max;	//���� �̵�
	return true;
}

//����
void* myqueue2::get()
{
	if (empty() == true)
		return NULL;

	void* temp = base[front];
	front = (front + 1) % max;
	return temp;
}

//���� ��ܿ� �ִ� ������ ��ȯ
void* myqueue2::peek()
{
	if (empty() == true)
		return NULL;

	return base[front];
}