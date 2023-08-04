//소스4.c

//동적메모리
#include <stdio.h>
#include <malloc.h> //동적메모리

//mallc(byte), calloc(저장할타입크기, 개수) ==> byte(저장할타입크기 * 개수)
//free
//realloc
void exam1()
{
	//heap(동적메모리) 요청 -> 주소 반환
	int *p1 = (int*)malloc(sizeof(int));		//4byte
	char*p2 = (char*)malloc(sizeof(char));		//1byte
	int *p3 = (int*)calloc(sizeof(int), 1);		//4 * 1byte
	char*p4 = (char*)calloc(sizeof(char), 1);	//1 * 1byte

	//-------------사용(포인터 변수와 동일)----------------
	*p1 = 10;
	*p2 = 'A';
	*p3 = 20;
	*p4 = *p2;
	//-----------------------------------------------------
	
	//메모리 해제 요청!
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}

//예외처리
//동적메모리 요청은 실패할 수도 있다.(실패시 NULL이 반환, 성공시 주소 반환)
void exam2()
{
	int *p1;
	p1 = (int*)malloc(sizeof(int)); 
	if (p1 == NULL)
	{
		printf("메모리 생성 오류\n");
		return;
	}

	//사용

	free(p1);
}


//활용1) 동적메모리를 활용한 동적 배열 생성
//int num = 10;
//int arr[num];  //에러
void exam3()
{
	int arr[10];  // 고정된 크기의 배열
	int* arr1;    // 포인터~ (1차원 배열의 주소를 저장할 수 있다.)
	arr1 = arr;

	int* arr2;
	int max;
	printf("저장 개수 : ");			scanf_s("%d", &max);
	arr2 = malloc(sizeof(int)* max); //힙에 배열 생성

	for (int i = 0; i < max; i++)
		arr2[i] = i;

	for (int i = 0; i < max; i++)
		printf("%d ", arr2[i]);


	free(arr2);
}

//활용2) 동적저장
int* g_arr[5];  //int의 주소를 저장하는 공간 5개 생성

void exam4()
{
	int num = 10;
	g_arr[0] = &num;	//ok.( 사라지는 변수의 주소를 저장...)?

	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	g_arr[0] = p;
}

void exam4_1()
{
	printf("%d\n", *g_arr[0]); // 역참조(어딘가로 접근)
}

//realloc : 동적메모리 재할당,
void exam5()
{
	int max = 5;
	int *arr = (int*)malloc(sizeof(int)* max);

	for (int i = 0; i < 5; i++)
		arr[i] = i;

	//추가로 5개의 공간을 더 확보( 기존 5 + 추가 5 )
	max = 10;
	arr= realloc(arr, sizeof(int)* 10);   // arr는 현재 동적메모리 시작 주소. 10개의 공간으로 확장

	for (int i = 5; i < 10; i++)
		arr[i] = i;

	//출력확인
	for (int i = 0; i < max; i++)
		printf("%d ", arr[i]);

	free(arr);
}

int main()
{
	//exam4();
	//exam4_1();
	exam5();

	return 0;
}