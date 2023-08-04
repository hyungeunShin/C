//wblist.h

typedef struct node node;
struct node
{
	drink data;				//<--- 저장 타입 변경 
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

void list_init(linkedlist *plist);

int list_frontinsert(linkedlist *plist, drink value);			//<-----
void list_rearinsert(linkedlist *plist, drink value);			//<-----
void list_nextinsert(linkedlist *plist, node* cur, drink value); //<------

void list_frontdelete(linkedlist *plist);
void list_reardelete(linkedlist *plist);
void list_nodedelete(linkedlist *plist, node* del);

//데이터 접근 코드
void list_next_printall(linkedlist *plist);
void list_prev_printall(linkedlist *plist);

node* list_select1(linkedlist *plist, const char* name);    //<--------
