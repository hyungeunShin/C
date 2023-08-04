//myqueue3.h
// myqueue2.h 와 myqueue2.cpp 파일 그대로 복사
// void* -> T
#pragma once
#include <iostream>
using namespace std;

template<typename T>
class myqueue3
{
	T* base;
	int max;
	int rear;		//저장 위치 
	int front;		//삭제 위치 

public:
	myqueue3(int _max = 10);
	~myqueue3();

public:
	int get_max() const { return max; }
	int get_rear() const { return rear; }
	int get_front() const { return front; }
	T operator[](int idx) { return base[idx]; }

public:
	//개수 반환
	int count();

	//오버플로우 검사
	bool overflow();
	//언더플로우(empty)검사
	bool empty();

	//저장
	bool put(T value);
	//삭제
	T get();

	//가장 상단에 있는 데이터 반환
	T peek();
};

template<typename T>
myqueue3<T>::myqueue3(int _max /*= 10*/) : max(_max), rear(0), front(0)
{
	base = new T[max]; //T 를 max개 저장할 수 있는 동적배열 요청
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

//개수 반환
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

//오버플로우 검사
template<typename T>
bool myqueue3<T>::overflow()
{
	if ((rear + 1) % max == front)
		return true;
	else
		return false;
}

//언더플로우(empty)검사
template<typename T>
bool myqueue3<T>::empty()
{
	if (rear == front)
		return true;
	else
		return false;
}

//저장
template<typename T>
bool myqueue3<T>::put(T value)
{
	if (overflow() == true)
		return false;

	base[rear] = value;
	rear = (rear + 1) % max;	//원형 이동
	return true;
}

//삭제
template<typename T>
T myqueue3<T>::get()
{
	if (empty() == true)
		return NULL;

	T temp = base[front];
	front = (front + 1) % max;
	return temp;
}

//가장 상단에 있는 데이터 반환
template<typename T>
T myqueue3<T>::peek()
{
	if (empty() == true)
		return NULL;

	return base[front];
}