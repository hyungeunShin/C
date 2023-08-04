//wbtlist.h
//템플릿은 외부함수 정의도 h파일에...
//틀이지 소스코드가 아니다.
#pragma once

#include <iostream>
using namespace std;

//void*  --> T
template<typename T>
class WbTList
{
	//노드 구조체 정의
public:
	struct node
	{
		T data;				//<--- 저장 타입 변경 
		struct node* next;
		struct node* prev;
		node(T _data)	//<----------------------
		{
			data = _data;
			next = prev = NULL;
		}
	};

	//맴버 필드
private:
	struct node* head;	//필수.
	struct node* tail;	//옵션.
	int size;			//옵션.

	//생성자 & 소멸자
public:
	WbTList();
	~WbTList();

	//get& set메서드
public:
	int getSize() { return size; }
	node* getHead() { return head; }
	node* getTail() { return tail; }

	//메서드
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
		throw "노드 생성 에러";

	if (head == NULL && tail == NULL)  //비어있는 상태
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
		throw "노드 생성 에러";

	if (head == NULL && tail == NULL)  //비어있는 상태
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

template<typename T>
void WbTList<T>::frontdelete()
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

template<typename T>
void WbTList<T>::reardelete()
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

template<typename T>
void WbTList<T>::nodedelete(node* del)
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





