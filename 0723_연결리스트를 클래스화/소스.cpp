//�ҽ�.cpp
#include <iostream>
using namespace std;
#include "wblist.h"

//������ ���� �ڵ�
void list_next_printall(WbList *list)
{
	printf("[���尳�� : %d]\n", list->getSize());

	WbList::node* cur = list->getHead();
	while (cur != NULL)
	{
		//�湮
		int *p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->next;
	}
	cout << endl;
}
//������ ���� �ڵ�
void list_prev_printall(WbList *list)
{
	printf("[���尳�� : %d]\n", list->getSize());

	WbList::node* cur = list->getTail();
	while (cur != NULL)
	{
		//�湮
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->prev;
	}
	cout << endl;
}
//�˻�
WbList::node* list_select1(WbList* list, int value)
{
	WbList::node* cur = list->getHead();
	while (cur != NULL)
	{
		int* pvalue = (int*)cur->data;
		if ( *pvalue == value)			
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//�Ϲ� Ŭ���� ���
void exam1()
{
	//����
	WbList list;

	//������ ����
	for (int i = 0; i < 100; i++)
	{
		int* value = new int(i + 1);
		list.rearinsert(value);
	}

	//���
	list_next_printall(&list);
	list_prev_printall(&list);

	//�˻�
	WbList::node* cur = list_select1(&list, 50);
	if (cur == NULL)
		cout << "����" << endl;
	else
	{
		int* pvalue = (int*)cur->data;
		cout << "�˻���� : " << *pvalue << endl;
	}

	//����(�˻� -> ã�� ������ ����)
	int* pvalue = (int*)(cur->data);
	*pvalue = 555;

	//���
	list_next_printall(&list);
	list_prev_printall(&list);

	//����
	for (int i = 0; i < 50; i++)
		list.reardelete();

	list.nodedelete(cur);

	//���
	list_next_printall(&list);
	list_prev_printall(&list);
}



#include "wbtlist.h"

//������ ���� �ڵ�
void list_next_printall(WbTList<int*>* list)
{
	printf("[���尳�� : %d]\n", list->getSize());

	WbTList<int*>::node* cur = list->getHead();
	while (cur != NULL)
	{
		//�湮
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->next;
	}
	cout << endl;
}
//������ ���� �ڵ�
void list_prev_printall(WbTList<int*>* list)
{
	printf("[���尳�� : %d]\n", list->getSize());

	WbTList<int*>::node* cur = list->getTail();
	while (cur != NULL)
	{
		//�湮
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->prev;
	}
	cout << endl;
}
//�˻�
WbTList<int*>::node* list_select1(WbTList<int*>* list, int value)
{
	WbTList<int*>::node* cur = list->getHead();
	while (cur != NULL)
	{
		int* pvalue = (int*)cur->data;
		if (*pvalue == value)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


//���ø� Ŭ���� ���
void exam2()
{
	//����
	WbTList<int*> list; //<---

	//������ ����
	for (int i = 0; i < 100; i++)
	{
		int* value = new int(i + 1);
		list.rearinsert(value);
	}

	//���
	list_next_printall(&list);
	list_prev_printall(&list);

	//�˻�
	WbTList<int*>::node* cur = list_select1(&list, 50);//<----
	if (cur == NULL)
		cout << "����" << endl;
	else
	{
		int* pvalue = (int*)cur->data;
		cout << "�˻���� : " << *pvalue << endl;
	}

	//����(�˻� -> ã�� ������ ����)
	int* pvalue = (int*)(cur->data);
	*pvalue = 555;

	//���
	list_next_printall(&list);
	list_prev_printall(&list);

	//����
	for (int i = 0; i < 50; i++)
		list.reardelete();

	list.nodedelete(cur);

	//���
	list_next_printall(&list);
	list_prev_printall(&list);
}

int main()
{
	exam2();

	return 0;
}