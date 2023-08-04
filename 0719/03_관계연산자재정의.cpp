//03_관계연산자재정의.cpp
/*
객체가 연산자를 사용할 때 어떤 방식으로 호출되느냐?

[맴버형태로 연산자를 재정의]<-- 

객체 a = 객체 b + 객체 c;    // b.operator+( c );
						     // 객체 operator+( const 객체 & r);

if(객체 a == 객체 b);	    // a.operator==(b);
							// bool operator==(const 객체 & r);

[전역함수형태로 연산자를 재정의]<--어쩔 수 없을 경우

*/
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
	void Print() const { cout << year << "-" << month << "-" << day << endl; }
	bool equals(const MyDate & d)
	{
		if (year == d.year && month == d.month && day == d.day)
			return true;
		else
			return false;
	}

	bool operator==(const MyDate & d)
	{
		if (year == d.year && month == d.month && day == d.day)
			return true;
		else
			return false;
	}
};

int main()
{
	MyDate d1(2021, 7, 19);
	MyDate d2(2021, 7, 19);

	//if (d1.equals(d2))		
	if ( d1 == d2)					//d1.operator==(d2)
		cout << "동일" << endl;
	else
		cout << "다르다" << endl;

	return 0;
}