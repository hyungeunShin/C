//wblist.h

#pragma once

class WbList
{
	//��� ����ü ����
public:
	struct node
	{
		void* data;				//<--- ���� Ÿ�� ���� 
		struct node* next;
		struct node* prev;
		node(void* _data)
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
	WbList();
	~WbList();

	//get& set�޼���
public:
	int getSize()	 { return size;   }
	node* getHead()  { return head;   }
	node* getTail()  { return tail;   }

	//�޼���
public:
	void frontinsert( void* value);			
	void rearinsert( void* value);			
	void nextinsert( node* cur, void* value);

	void frontdelete();
	void reardelete();
	void nodedelete(node* del);
};



