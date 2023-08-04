//07_동적메모리 new / delete

#include <iostream>
using namespace std;

//C언어
void exam1()
{
	//stack : p1이 생성
	//heap  : 정수 1개 저장할 공간을 생성
	int *p1 = (int*)malloc(sizeof(int));

	*p1 = 10;
	*p1 = 20;

	free(p1);

	//stack : p2가 생성
	//headp : 정수 10개 저장할 공간을 생성 --> 10짜리 배열이 생성!
	int *p2 = (int*)malloc(sizeof(int)* 10);

	p2[0] = 10;
	p2[1] = 20;
	p2[9] = 30;

	free(p2);
}

//C++언어
//[컴파일러의 관점에서 중요한 것은 어떤 사용될 때 타입 ]
//int* p1; //주소를 따라가면 정수가 있다.
void exam2()
{
	//stack : p1
	//heap  : int 저장공간 1개 생성, 쓰레기
	int *p1 = new int;

	cout << *p1 << endl; 
	*p1 = 1;
	cout << *p1 << endl; 

	delete p1;   //힙메모리 삭제 요구 코드 : 4byte로 생각 -> 4byte해제.

	//stack : p2
	//headp : int 저장공간 1개 생성, 10으로 초기화!!!!!!
	int *p2 = new int(10);

	cout << *p2 << endl; 

	delete p2;

	//stack : p3
	//headp : int 저장공간 10개 생성, 쓰레기...
	int *p3 = new int[10];

	p3[0] = 10;
	p3[1] = 20;
	p3[9] = 30;

//	delete p3; // 잘못된 사용 예. 힙메모리의 4byte만 해제 처리...
	delete[] p3;  //p3는 배열의 주소이다.....
}

int main()
{
	exam2();

	return 0;
}