//wblist.h

#pragma once

class WbList
{
	//노드 구조체 정의
public:
	struct node
	{
		void* data;				//<--- 저장 타입 변경 
		struct node* next;
		struct node* prev;
		node(void* _data)
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
	WbList();
	~WbList();

	//get& set메서드
public:
	int getSize()	 { return size;   }
	node* getHead()  { return head;   }
	node* getTail()  { return tail;   }

	//메서드
public:
	void frontinsert( void* value);			
	void rearinsert( void* value);			
	void nextinsert( node* cur, void* value);

	void frontdelete();
	void reardelete();
	void nodedelete(node* del);
};



