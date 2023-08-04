//wblist.h

typedef struct node node;
struct node
{
	drink data;				//<--- ���� Ÿ�� ���� 
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

void list_init(linkedlist *plist);

int list_frontinsert(linkedlist *plist, drink value);			//<-----
void list_rearinsert(linkedlist *plist, drink value);			//<-----
void list_nextinsert(linkedlist *plist, node* cur, drink value); //<------

void list_frontdelete(linkedlist *plist);
void list_reardelete(linkedlist *plist);
void list_nodedelete(linkedlist *plist, node* del);

//������ ���� �ڵ�
void list_next_printall(linkedlist *plist);
void list_prev_printall(linkedlist *plist);

node* list_select1(linkedlist *plist, const char* name);    //<--------
