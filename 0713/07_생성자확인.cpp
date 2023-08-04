//07_생성자확인
/*
객체가 생성될 때(반드시)
1. 메모리 생성(맴버 변수)
2. 생성자 호출
*/

#include <iostream>
using namespace std;

class Sample
{
};

void exam1()
{
	Sample s1;	 //객체 생성
	//맴버 변수가 없기 때문에 메모리는 최소 메모리인 1byte 지원(컴파일러가)
	//생성자가 없기 때문에 인자가 없는 기본생성자를 제공(컴파일러가)
	//[컴파일러가 제공해 주는 기본 생성자]
	// Sample() { } 
	cout << sizeof(s1) << endl;   // 1byte..
}


//다양한 생성자의 호출 형태
//생성자는 오버로딩이 가능하다.
class Sample1
{
	//2개의 생성자 -> 객체를 생성하는 방법이 2가지다.
public:
	//Sample1() {}
	Sample1(int n1)				{ cout << "Sample(int)" << endl;		}
	Sample1(int n1, char ch)	{ cout << "Sample(int, char)" << endl;  }
};

void exam2()
{
//	Sample1 s0;			// 에러...생성자를 만들면 컴파일러는 더이상 기본생성자를
						//제공해 주지 않는다.
	Sample1 s1(10);
	Sample1 s2(10, 'A');
}

class Sample2
{
private:		//명시적으로 눈에 보이게끔.
	int		number;
	char	c;

public:
	Sample2(int n1)				{ number = n1;    c = n1; }
	Sample2(int n1, char ch)	{ number = n1;    c = ch; }

public:
	void Print()
	{
		cout << number << ", " << c << endl; 
	}
};

void exam3()
{
	Sample2 s1(65);				// 1) 5byte 메모리가 생성 2) 생성자를 호출->초기화
	Sample2 s2(65, 'B');

	s1.Print();
	s2.Print();
}

int main()
{
	exam3();	

	return 0;
}


