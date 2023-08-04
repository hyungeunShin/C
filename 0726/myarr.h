//myarr.h
//���� �Լ� ���(C���)
//1) [�迭] ����ü ����

typedef struct tagmystack mystack;
struct tagmystack
{
	void* *base;  //void* �� ������ ���ִ� �迭
	int max;
	int top;	//���� & ���� ��ġ ����
};

//�ʱ�ȭ
void mystack_init(mystack *pstack, int max);
//����ó��
void mystack_exit(mystack *pstack);
//�����÷ο� �˻�
int mystack_overflow(const mystack *pstack);
//����÷ο�(empty)�˻�
int mystack_empty(const mystack *pstack);
//����
int mystack_push(mystack *pstack, void *value);
//����
void* mystack_pop(mystack *pstack);
//���� ��ܿ� �ִ� ������ ��ȯ
void* mystack_peek(mystack *pstack);
