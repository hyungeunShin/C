//myqueue1.h
#pragma once

//���� �Լ� ���(C���)
typedef struct tagmyqueue1 myqueue1;
struct tagmyqueue1
{
	void** base;
	int max;
	int rear;		//���� ��ġ 
	int front;		//���� ��ġ 
};

//���� ��ȯ
int myqueue_count(myqueue1* pqueue);

//�ʱ�ȭ
void myqueue_init(myqueue1* pqueue, int max);
//����ó��
void myqueue_exit(myqueue1* pqueue);

//�����÷ο� �˻�
int myqueue_overflow(const myqueue1* pqueue);
//����÷ο�(empty)�˻�
int myqueue_empty(const myqueue1* pqueue);

//����
int myqueue_put(myqueue1* pqueue, void* value);
//����
void* myqueue_get(myqueue1* pqueue);

//���� ��ܿ� �ִ� ������ ��ȯ
void* myqueue_peek(myqueue1* pqueue);
