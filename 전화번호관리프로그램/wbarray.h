//wbarray.h

//구조체 정의
typedef struct wbarr wbarr;
struct wbarr
{
	member *base;	//<------------------1)  크기가 정해지지 않은 배열 구조.
	int max;								// 힙 메모리에 생성되는 배열의 주소를 저장!
	int size;
};

//초기화
void arr_init(wbarr *parr, int usermax);
//종료처리
void arr_exit(wbarr *parr);
//저장
int arr_insert(wbarr *parr, member value);
//삭제
int arr_delete(wbarr *parr, int idx);