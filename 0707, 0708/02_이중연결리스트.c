//02_이중연결리스트.c

#include <stdio.h>
#include <malloc.h>


//단계1,2,3)
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
	struct node *head;	//필수.
	struct node *tail;	//옵션.
	int size;			//옵션.
};

linkedlist g_list;

//초기화
void list_init()
{
	g_list.head = NULL;
	g_list.tail = NULL;
	g_list.size = 0;
}

//순회---------------------------------------------------------------------------
void list_next_printall()
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

void list_prev_printall()
{
	printf("[저장개수 : %d] ", g_list.size);

	struct node *cur = g_list.tail;
	while (cur != NULL)
	{
		//방문
		printf("%3d", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}


//저장 -----------------------------------------------------------------------------
//앞(head) 부분에 추가
void list_frontinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.head == NULL && g_list.tail == NULL)  //비어있는 상태
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

//뒤(tail) 부분에 추가
void list_rearinsert(int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.head == NULL && g_list.tail == NULL)  //비어있는 상태
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

//전달된 노드 뒤에 추가
void list_nextinsert(node* cur, int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //#include <malloc.h>
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (g_list.tail == cur)  //전달된 노드 위치가 꼬리일 겨우
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

//검색--------------------------------------------------------------------------------------
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
//첫(head) 노드 삭제
void list_frontdelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.head;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
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

//마지막(tail) 노드 삭제
void list_reardelete()
{
	if (g_list.head == NULL)
		return;

	struct node* del = g_list.tail;

	if (del->next == NULL && del->prev == NULL) //노드가 하나인 상황
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

void list_nodedelete(node* del)  //첫번째 노드, 중간 노드, 마지막 노드
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

	list_nextinsert(g_list.head, 15);  //마지막 노드에 추가
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

	//--검색----------------------------
	node *findnode = list_select1(100);
	if (findnode != NULL)
		printf("검색 결과 : %d\n", findnode->data);
	else
		printf("없다\n");
	printf("\n");

	//-- 노드 삭제(첫번째)
	list_nodedelete(g_list.head);
	list_next_printall();
	list_prev_printall();
	printf("\n");

	//-- 노드 삭제(꼬리)
	list_nodedelete(g_list.tail);
	list_next_printall();
	list_prev_printall();
	printf("\n");

	//-- 중간 노드 삭제
	list_nodedelete(g_list.head->next->next);
	list_next_printall();
	list_prev_printall();
	printf("\n");



	//---삭제 테스트
	/*printf("\n삭제 테스트\n");
	for (int i = 0; i < 10; i++)
	{
		list_reardelete();
		list_next_printall();  
		list_prev_printall();
		printf("\n");
	}*/

	return 0;
}