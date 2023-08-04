//wbListStack.h

//����� ->[WbListStack] -> WbTList
#pragma once

#include "wbtlist.h"

template <typename T>
class WbListStack
{
private:
	WbTList<T> list;		//����(has a) : WbListStack������ WbTList ���� ������.

public:
	int gettop()  { return list.getSize(); }

public:
	T operator[](int idx)
	{
		WbTList<int*>::node *begin = list.getHead();
		for (int i = 0; i < idx; i++)
		{
			begin = begin->next;
		}
		return begin->data;
	}

	void push(T data)
	{
		list.rearinsert(data);
	}

	T pop()
	{
		return list.reardelete();
	}

	T peek()
	{
		//WbTList<T>::node *cur =  list.getTail();
		//return cur->data;

		return list.getTail()->data;
	}
};

