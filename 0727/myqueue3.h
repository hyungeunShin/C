//myqueue3.h
// myqueue2.h �� myqueue2.cpp ���� �״�� ����
// void* -> T
#pragma once
#include <iostream>
using namespace std;

template<typename T>
class myqueue3
{
	T* base;
	int max;
	int rear;		//���� ��ġ 
	int front;		//���� ��ġ 

public:
	myqueue3(int _max = 10);
	~myqueue3();

public:
	int get_max() const { return max; }
	int get_rear() const { return rear; }
	int get_front() const { return front; }
	T operator[](int idx) { return base[idx]; }

public:
	//���� ��ȯ
	int count();

	//�����÷ο� �˻�
	bool overflow();
	//����÷ο�(empty)�˻�
	bool empty();

	//����
	bool put(T value);
	//����
	T get();

	//���� ��ܿ� �ִ� ������ ��ȯ
	T peek();
};

template<typename T>
myqueue3<T>::myqueue3(int _max /*= 10*/) : max(_max), rear(0), front(0)
{
	base = new T[max]; //T �� max�� ������ �� �ִ� �����迭 ��û
	for (int i = 0; i < max; i++)
	{
		base[i] = NULL;
	}
}

template<typename T>
myqueue3<T>::~myqueue3()
{
	for (int i = 0; i < max; i++)
	{
		if (base[i] != NULL)
			delete base[i];
	}
	delete[] base;
}

//���� ��ȯ
template<typename T>
int myqueue3<T>::count()
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
template<typename T>
bool myqueue3<T>::overflow()
{
	if ((rear + 1) % max == front)
		return true;
	else
		return false;
}

//����÷ο�(empty)�˻�
template<typename T>
bool myqueue3<T>::empty()
{
	if (rear == front)
		return true;
	else
		return false;
}

//����
template<typename T>
bool myqueue3<T>::put(T value)
{
	if (overflow() == true)
		return false;

	base[rear] = value;
	rear = (rear + 1) % max;	//���� �̵�
	return true;
}

//����
template<typename T>
T myqueue3<T>::get()
{
	if (empty() == true)
		return NULL;

	T temp = base[front];
	front = (front + 1) % max;
	return temp;
}

//���� ��ܿ� �ִ� ������ ��ȯ
template<typename T>
T myqueue3<T>::peek()
{
	if (empty() == true)
		return NULL;

	return base[front];
}