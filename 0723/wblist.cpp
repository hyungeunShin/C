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
		throw "노드 생성 에러";

	if (head == NULL && tail == NULL)  //비어있는 상태
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
		throw "노드 생성 에러";

	if (head == NULL && tail == NULL)  //비어있는 상태
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
		throw "노드 생성 에러";

	if (tail == cur)  //전달된 노드 위치가 꼬리일 겨우
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
	//비어있는 상황
	if (head == NULL)
		throw "비어 있는 상황(삭제할 노드가 없다)";

	node* del = head;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
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
		throw "비어 있는 상황(삭제할 노드가 없다)";

	struct node* del = tail;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
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
	//헤더부분
	if (del == head)
	{
		frontdelete();
	}
	else if (del == tail)	//꼬리부부
	{
		reardelete();
	}
	else  //중간
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
		size--;
	}
}



