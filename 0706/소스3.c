//소스3.c
//int 가 아닌 char 를 저장하는 wbarr 구조체를 정의하고, 적절히 코드를 수정할 것

#include <stdio.h>

#define DATA_MAX	26

//구조체 정의
typedef struct wbarr wbarr;
struct wbarr
{
	char base[DATA_MAX];		//<------------------------------------(1)
	int max;
	int size;
};

//전역변수 : 자동 초기화
wbarr arrlist;

//초기화
void arr_init()
{
	for (int i = 0; i < DATA_MAX; i++)
		arrlist.base[i] = ' ';				//<----------------------(2)

	arrlist.max = DATA_MAX;
	arrlist.size = 0;
}

//저장
int arr_insert(char value)				//<-------------------------(3)
{
	if (arrlist.max <= arrlist.size)
		return 0;

	arrlist.base[arrlist.size] = value;
	arrlist.size++;
	return 1;
}

//전체 출력
void arr_printall() //순회
{
	printf("[%2d] : ", arrlist.size);
	for (int i = 0; i < arrlist.size; i++)  //저장된 위치까지??
	{
		printf("%c ", arrlist.base[i]);			//<--------------------------------4)
	}
	printf("\n");
}

//검색
int arr_select(char value)						//<--------------------------------- 5)
{
	for (int i = 0; i < arrlist.size; i++)
	{
		if (arrlist.base[i] == value)
			return i;
	}
	return -1;
}

//삭제 - 비효율적.
int arr_delete(int idx)
{
	//정상적인 인덱스 판별
	if (idx < 0 || idx > arrlist.size - 1)
		return 0;

	for (int i = idx; i < arrlist.size - 1; i++)
	{
		arrlist.base[i] = arrlist.base[i + 1];
	}

	arrlist.size--;
	return 1;
}

//수정..(검색/삭제/수정유사)

int main()
{
	arr_init();

	for (int i = 0; i < 7; i++)
	{
		if (arr_insert(i + 'A') == 0)   //A 부터 저장...
		{
			printf("저장 실패\n");
			continue;
		}
		arr_printall();   //[개수] A B C D ....
	}

	arr_delete(2);
	arr_printall();

	arr_delete(2);
	arr_printall();

	if (arr_delete(5) == 0)
		printf("삭제 오류\n");
	arr_printall();

	return 0;
}