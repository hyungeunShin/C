//wblist.c

#include "std.h"

//�ʱ�ȭ
void list_init(linkedlist *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

//��ȸ---------------------------------------------------------------------------
//������ ���� �ڵ�
void list_next_printall(linkedlist *plist)
{
	printf("[���尳�� : %d]\n", plist->size);

	struct node *cur = plist->head;
	while (cur != NULL)
	{
		//�湮
		drink_print(&cur->data);		//<--------------------------------------
		cur = cur->next;
	}
	printf("\n");
}
//������ ���� �ڵ�
void list_prev_printall(linkedlist *plist)
{
	printf("[���尳�� : %d] ", plist->size);

	struct node *cur = plist->tail;
	while (cur != NULL)
	{
		//�湮
		drink_print(&cur->data);		//<--------------------------------------
		cur = cur->prev;
	}
	printf("\n");
}


//���� -----------------------------------------------------------------------------
//��(head) �κп� �߰�
int list_frontinsert(linkedlist *plist, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	if (newnode == NULL)
		return 0;

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL && plist->tail == NULL)  //����ִ� ����
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

//��(tail) �κп� �߰�
void list_rearinsert(linkedlist *plist, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL && plist->tail == NULL)  //����ִ� ����
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

//���޵� ��� �ڿ� �߰�
void list_nextinsert(linkedlist *plist, node* cur, drink value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->tail == cur)  //���޵� ��� ��ġ�� ������ �ܿ�
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

//�˻�--------------------------------------------------------------------------------------
//������ ���� �ڵ�
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
//ù(head) ��� ����
void list_frontdelete(linkedlist *plist)
{
	if (plist->head == NULL)
		return;

	struct node* del = plist->head;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
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

//������(tail) ��� ����
void list_reardelete(linkedlist *plist)
{
	if (plist->head == NULL)
		return;

	struct node* del = plist->tail;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
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

void list_nodedelete(linkedlist *plist, node* del)  //ù��° ���, �߰� ���, ������ ���
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
