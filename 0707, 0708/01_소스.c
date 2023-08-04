//01_�ҽ�.c

#include <stdio.h>
#include <malloc.h>

//�ܰ�1,2,3)
struct node
{
	int data;
	struct node *next;
};

struct linkedlist
{
	struct node *head;	//�ʼ�.
	int size;			//�ɼ�.
};

struct linkedlist g_list;

void list_init()
{
	g_list.head = NULL;
	g_list.size = 0;
}

//��(head) �κп� �߰�
void list_frontinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;

	if (g_list.head == NULL)
	{
		g_list.head = newnode;
	}
	else
	{
		newnode->next	= g_list.head;
		g_list.head		= newnode;
	}
	g_list.size++;
}

//����ã��(������ ����� �ּ� ��ȯ)
struct node* list_findtailnode()
{
	if (g_list.head == NULL) //������� ��
		return NULL;

	struct node *cur = g_list.head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}

//��(������ ��� ����)�� �߰�
void list_rearinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;

	if (g_list.head == NULL)
	{
		g_list.head = newnode;
	}
	else
	{
		struct node * tail = list_findtailnode();
		tail->next = newnode;
	}
	g_list.size++;
}

//���޵� ����� ���� ��忡 �߰�
void list_nextinsert(struct node *cur, int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;

	if (cur->next == NULL) //������ ���
	{
		struct node * tail = list_findtailnode();
		tail->next = newnode;
	}
	else
	{
		newnode->next = cur->next;
		cur->next     = newnode;
	}
	g_list.size++;
}

//��ȸ
void list_printall()
{
	printf("[���尳�� : %d] ", g_list.size);

	struct node *cur = g_list.head;
	while (cur != NULL)
	{
		//�湮
		printf("%3d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//ù(head) ��� ����
void list_frontdelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.head;
	g_list.head = del->next;

	free(del);
	g_list.size--;
}

//����(������) ��� ����
void list_reardelete()
{
	if (g_list.head == NULL)	//����ִ� ��Ȳ
		return;

	//--------------------------------------------------------
	struct node* prev	= g_list.head;
	struct node* del	= g_list.head;

	if (g_list.head->next == NULL)	//��尡 �ϳ��� ��Ȳ
	{
		g_list.head = NULL;		
	}
	else  //��尡 �ϳ� �̻��� ��Ȳ
	{
		while (del->next != NULL)
		{
			prev = del; //
			del = del->next;
		}
		prev->next = NULL;		
	}
	free(del);
	g_list.size--;
}


int main()
{
	list_init();

	list_frontinsert(10);
	list_printall();			//[1] 10

	list_nextinsert(g_list.head,  15);  //������ ��忡 �߰�
	list_printall();			//[2] 10 15


	for (int i = 20; i <= 50; i = i + 10)
		list_rearinsert(i);

	list_printall();   // [6] 10 15 20 30 40 50 
	//====================================================

	list_nextinsert(g_list.head->next->next, 25);
	list_printall();   // [7] 10 15 20 25 30 40 50

	//---���� �׽�Ʈ
	printf("\n���� �׽�Ʈ\n");
	for (int i = 0; i < 10; i++)
	{
		list_reardelete();
		list_printall();
	}

	return 0;
}