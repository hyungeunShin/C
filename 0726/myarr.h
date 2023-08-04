//myarr.h
//전역 함수 기반(C기반)
//1) [배열] 구조체 정의

typedef struct tagmystack mystack;
struct tagmystack
{
	void* *base;  //void* 를 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리
};

//초기화
void mystack_init(mystack *pstack, int max);
//종료처리
void mystack_exit(mystack *pstack);
//오버플로우 검사
int mystack_overflow(const mystack *pstack);
//언더플로우(empty)검사
int mystack_empty(const mystack *pstack);
//저장
int mystack_push(mystack *pstack, void *value);
//삭제
void* mystack_pop(mystack *pstack);
//가장 상단에 있는 데이터 반환
void* mystack_peek(mystack *pstack);
