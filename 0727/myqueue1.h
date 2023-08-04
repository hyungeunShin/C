//myqueue1.h
#pragma once

//전역 함수 기반(C기반)
typedef struct tagmyqueue1 myqueue1;
struct tagmyqueue1
{
	void** base;
	int max;
	int rear;		//저장 위치 
	int front;		//삭제 위치 
};

//개수 반환
int myqueue_count(myqueue1* pqueue);

//초기화
void myqueue_init(myqueue1* pqueue, int max);
//종료처리
void myqueue_exit(myqueue1* pqueue);

//오버플로우 검사
int myqueue_overflow(const myqueue1* pqueue);
//언더플로우(empty)검사
int myqueue_empty(const myqueue1* pqueue);

//저장
int myqueue_put(myqueue1* pqueue, void* value);
//삭제
void* myqueue_get(myqueue1* pqueue);

//가장 상단에 있는 데이터 반환
void* myqueue_peek(myqueue1* pqueue);
