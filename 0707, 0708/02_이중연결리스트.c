//02_���߿��Ḯ��Ʈ.c

#include <stdio.h>
#include <malloc.h>


//�ܰ�1,2,3)
typedef struct node node;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct linkedlist linkedlist;
struct linkedlist
{
	struct node *head;	//�ʼ�.
	struct node *tail;	//�ɼ�.
	int size;			//�ɼ�.
};

linkedlist g_list;

//�ʱ�ȭ
void list_init()
{
	g_list.head = NULL;
	g_list.tail = NULL;
	g_list.size = 0;
}

//��ȸ---------------------------------------------------------------------------
void list_next_printall()
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

void list_prev_printall()
{
	printf("[���尳�� : %d] ", g_list.size);

	struct node *cur = g_list.tail;
	while (cur != NULL)
	{
		//�湮
		printf("%3d", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}


//���� -----------------------------------------------------------------------------
//��(head) �κп� �߰�
void list_frontinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.head == NULL && g_list.tail == NULL)  //����ִ� ����
	{
		g_list.head = newnode;
		g_list.tail = newnode;
	}
	else
	{
		newnode->next = g_list.head;
		g_list.head = newnode;
		newnode->next->prev = newnode; 
	}
	g_list.size++;
}

//��(tail) �κп� �߰�
void list_rearinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.head == NULL && g_list.tail == NULL)  //����ִ� ����
	{
		g_list.head = newnode;
		g_list.tail = newnode;
	}
	else
	{		
		newnode->prev		=  g_list.tail;
		g_list.tail->next	= newnode;
		g_list.tail			= newnode;
	}
	g_list.size++;
}

//���޵� ��� �ڿ� �߰�
void list_nextinsert(node* cur, int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.tail == cur)  //���޵� ��� ��ġ�� ������ �ܿ�
	{
		newnode->prev = g_list.tail;
		g_list.tail->next = newnode;
		g_list.tail = newnode;
	}
	else
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next = newnode;
		newnode->next->prev = newnode;
	}
	g_list.size++;
}

//�˻�--------------------------------------------------------------------------------------
node* list_select1(int value)
{
	struct node *cur = g_list.head;
	while (cur != NULL)
	{		
		if (cur->data == value)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

int list_select2(int value)
{
	struct node *cur = g_list.head;
	while (cur != NULL)
	{
		if (cur->data == value)
			return cur->data;

		cur = cur->next;
	}
	return -1;  //??????????????
}

//----------------------------------------------------------------------
//ù(head) ��� ����
void list_frontdelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.head;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
	{
		g_list.head = g_list.tail = NULL;
	}
	else
	{
		g_list.head			= del->next;  
		g_list.head->prev	= NULL;  
	}
	free(del);
	g_list.size--;
}

//������(tail) ��� ����
void list_reardelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.tail;

	if (del->next == NULL && del->prev == NULL) //��尡 �ϳ��� ��Ȳ
	{
		g_list.head = g_list.tail = NULL;
	}
	else
	{
		g_list.tail			= del->prev;
		g_list.tail->next	= NULL;
	}
	free(del);
	g_list.size--;
}

void list_nodedelete(node* del)  //ù��° ���, �߰� ���, ������ ���
{
	if (del == g_list.head)
	{
		list_frontdelete();
	}
	else if (del == g_list.tail)
	{
		list_reardelete();
	}
	else
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
		g_list.size--;			
	}
}

int main()
{
	list_init();

	list_frontinsert(10);
	list_next_printall();			//[1] 10
	list_prev_printall();
	printf("\n");

	list_nextinsert(g_list.head, 15);  //������ ��忡 �߰�
	list_next_printall();			//[2] 10 15
	list_prev_printall();
	printf("\n");

	for (int i = 20; i <= 50; i = i + 10)
		list_rearinsert(i);

	list_next_printall();   // [6] 10 15 20 30 40 50 
	list_prev_printall();
	printf("\n");
	//====================================================

	list_nextinsert(g_list.head->next->next, 25);
	list_next_printall();   // [7] 10 15 20 25 30 40 50
	list_prev_printall();
	printf("\n");

	//--�˻�----------------------------
	node *findnode = list_select1(100);
	if (findnode != NULL)
		printf("�˻� ��� : %d\n", findnode->data);
	else
		printf("����\n");
	printf("\n");

	//-- ��� ����(ù��°)
	list_nodedelete(g_list.head);
	list_next_printall();
	list_prev_printall();
	printf("\n");

	//-- ��� ����(����)
	list_nodedelete(g_list.tail);
	list_next_printall();
	list_prev_printall();
	printf("\n");

	//-- �߰� ��� ����
	list_nodedelete(g_list.head->next->next);
	list_next_printall();
	list_prev_printall();
	printf("\n");



	//---���� �׽�Ʈ
	/*printf("\n���� �׽�Ʈ\n");
	for (int i = 0; i < 10; i++)
	{
		list_reardelete();
		list_next_printall();  
		list_prev_printall();
		printf("\n");
	}*/

	return 0;
}