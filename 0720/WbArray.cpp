//wbarray.cpp

#include <iostream>
using namespace std;
#include "WbArray.h"

WbArray::WbArray(int _max /*= 10*/) : max(_max), size(0)
{
	//동적배열
	base = new void*[max];  //void*를 max개 저장할 수 있는 배열을 생성

	//모든 배열을 NULL초기화
	for (int i = 0; i < max; i++)
		base[i] = NULL;
}

WbArray::~WbArray()
{
	//생성된 객체 소멸
	for (int i = 0; i < size; i++)
		delete base[i];

	//생성된 동적 배열 소멸
	delete[] base;
}

bool WbArray::push_back(void* value)
{
	if (max <= size) //Overflow
		return false;

	base[size] = value;
	size++;
	return true;
}

bool WbArray::erase(int idx)
{
	//정상적인 인덱스 판별
	if (idx < 0 || idx > size - 1)
		return false;

	void* del = base[idx];			//<-------------------
	for (int i = idx; i < size - 1; i++)
	{
		base[i] = base[i + 1];
	}
	size--;

	delete del;
	return true;
}
