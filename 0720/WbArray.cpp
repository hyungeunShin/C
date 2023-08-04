//wbarray.cpp

#include <iostream>
using namespace std;
#include "WbArray.h"

WbArray::WbArray(int _max /*= 10*/) : max(_max), size(0)
{
	//�����迭
	base = new void*[max];  //void*�� max�� ������ �� �ִ� �迭�� ����

	//��� �迭�� NULL�ʱ�ȭ
	for (int i = 0; i < max; i++)
		base[i] = NULL;
}

WbArray::~WbArray()
{
	//������ ��ü �Ҹ�
	for (int i = 0; i < size; i++)
		delete base[i];

	//������ ���� �迭 �Ҹ�
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
	//�������� �ε��� �Ǻ�
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
