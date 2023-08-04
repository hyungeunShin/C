//mystack2.h
//mystack1.h �� mystack1.cpp �ڵ� ����
#pragma once

#include <iostream>
using namespace std;

template<typename T>
class mystack2
{
private:
	T *base;  //void* �� --> T ������ ���ִ� �迭
	int max;
	int top;	//���� & ���� ��ġ ����

public:
	mystack2(int _max = 10);
	~mystack2();

public:
	int gettop() const					{ return top;		}
	T getdata(int idx) const			{ return base[idx]; }
	T operator[](int idx)	const		{ return base[idx]; }

public:
	//�����÷ο� �˻�
	bool overflow();
	//����÷ο�(empty)�˻�
	bool empty();

public:
	//����
	bool push(T value);
	//����
	T pop();
	//���� ��ܿ� �ִ� ������ ��ȯ
	T peek();
};

template<typename T>
mystack2<T>::mystack2(int _max /*= 10*/) : max(_max), top(-1)
{
	base = new T[max];
}

template<typename T>
mystack2<T>::~mystack2()
{
	delete[] base;		//�迭 ����
}

template<typename T>
bool mystack2<T>::overflow()
{
	if (max <= top + 1)
		return true;
	else
		return false;
}

template<typename T>
bool mystack2<T>::empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template<typename T>
bool mystack2<T>::push(T value)
{
	if (overflow() == true)
		return false;

	top++;
	base[top] = value;
	return true;
}

template<typename T>
T mystack2<T>::pop()
{
	if (empty() == true)
		return NULL;  // 0

	T pvalue = base[top];
	top--;
	return pvalue;
}

template<typename T>
T mystack2<T>::peek()
{
	if (empty() == true)
		return NULL;

	return base[top];
}
