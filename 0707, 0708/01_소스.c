//01_소스.c

#include <stdio.h>
#include <malloc.h>

//단계1,2,3)
struct node
{
	int data;
	struct node *next;
};

struct linkedlist
{
	struct node *head;	//필수.
	int size;			//옵션.
};

struct linkedlist g_list;

void list_init()
{
	g_list.head = NULL;
	g_list.size = 0;
}

//앞(head) 부분에 추가
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

//꼬리찾기(마지막 노드의 주소 반환)
struct node* list_findtailnode()
{
	if (g_list.head == NULL) //비어있을 때
		return NULL;

	struct node *cur = g_list.head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}

//뒤(마지막 노드 다음)에 추가
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

//전달된 노드의 다음 노드에 추가
void list_nextinsert(struct node *cur, int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;

	if (cur->next == NULL) //꼬리일 경우
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

//순회
void list_printall()
{
	printf("[저장개수 : %d] ", g_list.size);

	struct node *cur = g_list.head;
	while (cur != NULL)
	{
		//방문
		printf("%3d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//첫(head) 노드 삭제
void list_frontdelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.head;
	g_list.head = del->next;

	free(del);
	g_list.size--;
}

//꼬리(마지막) 노드 삭제
void list_reardelete()
{
	if (g_list.head == NULL)	//비어있는 상황
		return;

	//--------------------------------------------------------
	struct node* prev	= g_list.head;
	struct node* del	= g_list.head;

	if (g_list.head->next == NULL)	//노드가 하나인 상황
	{
		g_list.head = NULL;		
	}
	else  //노드가 하나 이상인 상황
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

	list_nextinsert(g_list.head,  15);  //마지막 노드에 추가
	list_printall();			//[2] 10 15


	for (int i = 20; i <= 50; i = i + 10)
		list_rearinsert(i);

	list_printall();   // [6] 10 15 20 30 40 50 
	//====================================================

	list_nextinsert(g_list.head->next->next, 25);
	list_printall();   // [7] 10 15 20 25 30 40 50

	//---삭제 테스트
	printf("\n삭제 테스트\n");
	for (int i = 0; i < 10; i++)
	{
		list_reardelete();
		list_printall();
	}

	return 0;
}