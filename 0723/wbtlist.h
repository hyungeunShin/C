//wbtlist.h
//���ø��� �ܺ��Լ� ���ǵ� h���Ͽ�...
//Ʋ���� �ҽ��ڵ尡 �ƴϴ�.
#pragma once

#include <iostream>
using namespace std;

//void*  --> T
template<typename T>
class WbTList
{
	//��� ����ü ����
public:
	struct node
	{
		T data;				//<--- ���� Ÿ�� ���� 
		struct node* next;
		struct node* prev;
		node(T _data)	//<----------------------
		{
			data = _data;
			next = prev = NULL;
		}
	};

	//�ɹ� �ʵ�
private:
	struct node* head;	//�ʼ�.
	struct node* tail;	//�ɼ�.
	int size;			//�ɼ�.

	//������ & �Ҹ���
public:
	WbTList();
	~WbTList();

	//get& set�޼���
public:
	int getSize() { return size; }
	node* getHead() { return head; }
	node* getTail() { return tail; }

	//�޼���
public:
	void frontinsert(T value);
	void rearinsert(T value);
	void nextinsert(node* cur, T value);

	void frontdelete();
	void reardelete();
	void nodedelete(node* del);
};

template<typename T>
WbTList<T>::WbTList() : head(NULL), tail(NULL), size(0)
{
}

template<typename T>
WbTList<T>::~WbTList()
{
}

template<typename T>
void WbTList<T>::frontinsert(T value)
{
	node* newnode = new node(value);
	if (newnode == NULL)
		throw "��� ���� ����";

	if (head == NULL && tail == NULL)  //����ִ� ����
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	size++;
}

template<typename T>
void WbTList<T>::rearinsert(T value)
{
	node* newnode = new node(value);
	if (newnode == NULL)
		throw "��� ���� ����";

	if (head == NULL && tail == NULL)  //����ִ� ����
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
}

template<typename T>
void WbTList<T>::nextinsert(node* cur, T value)
{
	node* newnode = new node(value);
	if (newnode == NULL)
		throw "��� ���� ����";

	if (tail == cur)  //���޵� ��� ��ġ�� ������ �ܿ�
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next = newnode;
		newnode->next->prev = newnode;
	}
	size++;
}

template<typename T>
void WbTList<T>::frontdelete()
{
	//����ִ� ��Ȳ
	if (head == NULL)
		throw "��� �ִ� ��Ȳ(������ ��尡 ����)";

	node* del = head;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
	{
		head = tail = NULL;
	}
	else
	{
		head = del->next;
		head->prev = NULL;
	}
	free(del);
	size--;
}

template<typename T>
void WbTList<T>::reardelete()
{
	if (head == NULL)
		throw "��� �ִ� ��Ȳ(������ ��尡 ����)";

	struct node* del = tail;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
	{
		head = tail = NULL;
	}
	else
	{
		tail = del->prev;
		tail->next = NULL;
	}
	free(del);
	size--;
}

template<typename T>
void WbTList<T>::nodedelete(node* del)
{
	//����κ�
	if (del == head)
	{
		frontdelete();
	}
	else if (del == tail)	//�����κ�
	{
		reardelete();
	}
	else  //�߰�
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
		size--;
	}
}





