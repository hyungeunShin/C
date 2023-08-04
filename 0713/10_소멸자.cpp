//10_소멸자
/*
[객체 생성시]
1. 메모리 생성(맴버 변수)
2. 생성자 호출
   컴파일러가 만들어 주는 생성자 -> 클래스명() { } 

[객체 소멸시]
1. 소멸자 호출
   컴파일러가 만들어 주는 소멸자 -> ~클래스명() { }
2. 메모리 해제

* 소멸자는 모양이 1개.
  반환타입 X
  이름    ~클래스명
  매개변수 X
*/
#include <iostream>
using namespace std;

class Sample
{
public:
	Sample()		{ cout << "Sample()" << endl;			}		//1
	Sample(int n)	{ cout << "Sample(int)" << endl;	}		//2

	~Sample()		{ cout << "~Sample()" << endl;		}		//3
};

int main()
{
//	Sample s1;			//1 -> 3
//	Sample s2(10);		//2 -> 3 

//	Sample s3[3];    //1, 1, 1 -> 3, 3, 3 
//	Sample s4[3] = { Sample(10), Sample(2) };	// 2, 2, 1 -> 3, 3, 3 

	//---------------------------------
//	Sample *p1;	//객체 생성이 아니라 객체의 주소를 저장하는 4byte 메모리를 생성
//	p1 = new Sample;  //heap메모리에 Sample 1개를 생성.		// 1

//	delete p1;		//heap 메모리 소멸처리					// 3

	//-------------------------------------------
//	Sample *p2;
//	p2 = new Sample(10);	// 2

//	delete p2;				//3

	//----------------------------------------------------------
	Sample * arr[5];	// 객체의 주소를 5개 저장하는 공간을 생성!

	arr[0] = new Sample;			//1
	arr[1] = new Sample(10);		//2
	arr[2] = new Sample(30);		//2

	delete arr[0];					//3
	delete arr[1];					//3
	delete arr[2];					//3

	return 0;
}