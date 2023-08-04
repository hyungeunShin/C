//wblist.cpp

#include <iostream>
using namespace std;
#include "wblist.h"

WbList::WbList() : head(NULL), tail(NULL), size(0)
{
}

WbList::~WbList()
{
}

void WbList::frontinsert(void* value)
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
		newnode->next	= head;
		head->prev		= newnode;
		head			= newnode;	
	}
	size++;
}

void WbList::rearinsert(void* value)
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
		newnode->prev	= tail;
		tail->next		= newnode;
		tail			= newnode;
	}
	size++;
}

void WbList::nextinsert(node* cur, void* value)
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

void WbList::frontdelete()
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

void WbList::reardelete()
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

void WbList::nodedelete(node* del)
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



