//mystack1.cpp

#include <iostream>
using namespace std;
#include "mystack1.h"

mystack1::mystack1(int _max /*= 10*/) : max(_max), top(-1)
{
	base = new void*[max]; 
}

mystack1::~mystack1()
{
	for (int i = 0; i <= top; i++)
	{
		delete base[i];		//�迭�� �� �ε����� ����Ǿ��� ���� ���嵥���� ����
	}
	delete[] base;		//�迭 ����
}

bool mystack1::overflow()
{
	if (max <= top + 1)
		return true;
	else
		return false;
}

bool mystack1::empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool mystack1::push(void *value)
{
	if (overflow() == true)
		return false;

	top++;
	base[top] = value;
	return true;
}

void* mystack1::pop()
{
	if (empty() == true)
		return NULL;

	void* pvalue = base[top];
	top--;
	return pvalue;
}

void* mystack1::peek()
{
	if (empty() == true)
		return NULL;

	return base[top];
}