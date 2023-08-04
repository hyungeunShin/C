//소스.cpp
#include <iostream>
using namespace std;
#include "wblist.h"

//데이터 접근 코드
void list_next_printall(WbList *list)
{
	printf("[저장개수 : %d]\n", list->getSize());

	WbList::node* cur = list->getHead();
	while (cur != NULL)
	{
		//방문
		int *p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->next;
	}
	cout << endl;
}
//데이터 접근 코드
void list_prev_printall(WbList *list)
{
	printf("[저장개수 : %d]\n", list->getSize());

	WbList::node* cur = list->getTail();
	while (cur != NULL)
	{
		//방문
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->prev;
	}
	cout << endl;
}
//검색
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

//일반 클래스 사용
void exam1()
{
	//생성
	WbList list;

	//데이터 저장
	for (int i = 0; i < 100; i++)
	{
		int* value = new int(i + 1);
		list.rearinsert(value);
	}

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);

	//검색
	WbList::node* cur = list_select1(&list, 50);
	if (cur == NULL)
		cout << "없다" << endl;
	else
	{
		int* pvalue = (int*)cur->data;
		cout << "검색결과 : " << *pvalue << endl;
	}

	//수정(검색 -> 찾은 정보를 변경)
	int* pvalue = (int*)(cur->data);
	*pvalue = 555;

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);

	//삭제
	for (int i = 0; i < 50; i++)
		list.reardelete();

	list.nodedelete(cur);

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);
}



#include "wbtlist.h"

//데이터 접근 코드
void list_next_printall(WbTList<int*>* list)
{
	printf("[저장개수 : %d]\n", list->getSize());

	WbTList<int*>::node* cur = list->getHead();
	while (cur != NULL)
	{
		//방문
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->next;
	}
	cout << endl;
}
//데이터 접근 코드
void list_prev_printall(WbTList<int*>* list)
{
	printf("[저장개수 : %d]\n", list->getSize());

	WbTList<int*>::node* cur = list->getTail();
	while (cur != NULL)
	{
		//방문
		int* p = (int*)(cur->data);
		cout << *p << " ";
		cur = cur->prev;
	}
	cout << endl;
}
//검색
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


//템플릿 클래스 사용
void exam2()
{
	//생성
	WbTList<int*> list; //<---

	//데이터 저장
	for (int i = 0; i < 100; i++)
	{
		int* value = new int(i + 1);
		list.rearinsert(value);
	}

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);

	//검색
	WbTList<int*>::node* cur = list_select1(&list, 50);//<----
	if (cur == NULL)
		cout << "없다" << endl;
	else
	{
		int* pvalue = (int*)cur->data;
		cout << "검색결과 : " << *pvalue << endl;
	}

	//수정(검색 -> 찾은 정보를 변경)
	int* pvalue = (int*)(cur->data);
	*pvalue = 555;

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);

	//삭제
	for (int i = 0; i < 50; i++)
		list.reardelete();

	list.nodedelete(cur);

	//출력
	list_next_printall(&list);
	list_prev_printall(&list);
}

int main()
{
	exam2();

	return 0;
}