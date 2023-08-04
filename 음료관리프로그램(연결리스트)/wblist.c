//wblist.c

#include "std.h"

//초기화
void list_init(linkedlist *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

//순회---------------------------------------------------------------------------
//데이터 접근 코드
void list_next_printall(linkedlist *plist)
{
	printf("[저장개수 : %d]\n", plist->size);

	struct node *cur = plist->head;
	while (cur != NULL)
	{
		//방문
		drink_print(&cur->data);		//<--------------------------------------
		cur = cur->next;
	}
	printf("\n");
}
//데이터 접근 코드
void list_prev_printall(linkedlist *plist)
{
	printf("[저장개수 : %d] ", plist->size);

	struct node *cur = plist->tail;
	while (cur != NULL)
	{
		//방문
		drink_print(&cur->data);		//<--------------------------------------
		cur = cur->prev;
	}
	printf("\n");
}


//저장 -----------------------------------------------------------------------------
//앞(head) 부분에 추가
int list_frontinsert(linkedlist *plist, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	if (newnode == NULL)
		return 0;

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL && plist->tail == NULL)  //비어있는 상태
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->next = plist->head;
		plist->head = newnode;
		newnode->next->prev = newnode;
	}
	plist->size++;
	return 1;
}

//뒤(tail) 부분에 추가
void list_rearinsert(linkedlist *plist, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL && plist->tail == NULL)  //비어있는 상태
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	plist->size++;
}

//전달된 노드 뒤에 추가
void list_nextinsert(linkedlist *plist, node* cur, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->tail == cur)  //전달된 노드 위치가 꼬리일 겨우
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next = newnode;
		newnode->next->prev = newnode;
	}
	plist->size++;
}

//검색--------------------------------------------------------------------------------------
//데이터 접근 코드
node* list_select1(linkedlist *plist, const char* name)
{
	struct node *cur = plist->head;
	while (cur != NULL)
	{
		drink dr = cur->data;
		if (strcmp(dr.name, name) == 0)			//<----------------------
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//----------------------------------------------------------------------
//첫(head) 노드 삭제
void list_frontdelete(linkedlist *plist)
{
	if (plist->head == NULL)
		return;

	struct node* del = plist->head;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
	{
		plist->head = plist->tail = NULL;
	}
	else
	{
		plist->head = del->next;
		plist->head->prev = NULL;
	}
	free(del);
	plist->size--;
}

//마지막(tail) 노드 삭제
void list_reardelete(linkedlist *plist)
{
	if (plist->head == NULL)
		return;

	struct node* del = plist->tail;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
	{
		plist->head =  plist->tail = NULL;
	}
	else
	{
		plist->tail = del->prev;
		plist->tail->next = NULL;
	}
	free(del);
	plist->size--;
}

void list_nodedelete(linkedlist *plist, node* del)  //첫번째 노드, 중간 노드, 마지막 노드
{
	if (del == plist->head)
	{
		list_frontdelete(plist);
	}
	else if (del == plist->tail)
	{
		list_reardelete(plist);
	}
	else
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
		plist->size--;
	}
}
