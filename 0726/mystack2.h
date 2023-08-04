//mystack2.h
//mystack1.h 와 mystack1.cpp 코드 복사
#pragma once

#include <iostream>
using namespace std;

template<typename T>
class mystack2
{
private:
	T *base;  //void* 를 --> T 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리

public:
	mystack2(int _max = 10);
	~mystack2();

public:
	int gettop() const					{ return top;		}
	T getdata(int idx) const			{ return base[idx]; }
	T operator[](int idx)	const		{ return base[idx]; }

public:
	//오버플로우 검사
	bool overflow();
	//언더플로우(empty)검사
	bool empty();

public:
	//저장
	bool push(T value);
	//삭제
	T pop();
	//가장 상단에 있는 데이터 반환
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
	delete[] base;		//배열 삭제
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
