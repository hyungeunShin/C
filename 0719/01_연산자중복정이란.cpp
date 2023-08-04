//01_연산자중복정의란
//객체도 연산자를 사용할 수 있도록 정의하는 문법!
//이유? 가독성!
#include <iostream>
using namespace std;

class MyDate
{
	int year;
	int month;
	int day;
public:
	MyDate(int y, int m, int d) : year(y), month(m), day(d) {}

public:
	void Print() const { cout << year << "-" << month << "-" << day << endl;  }
	void AddDay()      { day = day + 1;  }
	void operator++()  { day = day + 1;  }
};

int main()
{
	MyDate d1(2021, 7, 19);			d1.Print();
	d1.AddDay();					d1.Print();

	//객체++;  // int num = 10; num++;
	//연산자를 이용한 호출은 맴버함수 호출구조와 유사!
	d1++;		// d1.operator++(); 
	d1.Print();

	return 0;
}