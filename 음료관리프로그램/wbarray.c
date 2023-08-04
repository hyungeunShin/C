//wbarray.c

#include "std.h"

//초기화
void arr_init(wbarr *parr, int usermax)
{
	parr->max	= usermax;
	parr->size	= 0;

	//동적배열
	parr->base = (drink*)malloc(sizeof(drink)* usermax);//<---------------------------1)

	//for (int i = 0; i < parr->max; i++)
	//{
	//	strcpy_s(parr->base[i].name, sizeof(parr->base[i].name), "");		//<---2)
	//	parr->base[i].price = 0;											//<-- 2.1)
	//}
}

//종료처리
void arr_exit(wbarr *parr)
{
	free(parr->base);						
}

//저장
int arr_insert(wbarr *parr, drink value)		//<------------------ 수정.
{
	if (parr->max <= parr->size)
		return 0;

	parr->base[parr->size] = value;
	parr->size++;
	return 1;
}

//삭제
int arr_delete(wbarr *parr, int idx)
{
	//정상적인 인덱스 판별
	if (idx < 0 || idx > parr->size - 1)
		return 0;

	for (int i = idx; i < parr->size - 1; i++)
	{
		parr->base[i] = parr->base[i + 1];
	}

	parr->size--;
	return 1;
}
