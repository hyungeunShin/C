//03_���迬����������.cpp
/*
��ü�� �����ڸ� ����� �� � ������� ȣ��Ǵ���?

[�ɹ����·� �����ڸ� ������]<-- 

��ü a = ��ü b + ��ü c;    // b.operator+( c );
						     // ��ü operator+( const ��ü & r);

if(��ü a == ��ü b);	    // a.operator==(b);
							// bool operator==(const ��ü & r);

[�����Լ����·� �����ڸ� ������]<--��¿ �� ���� ���

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
		cout << "����" << endl;
	else
		cout << "�ٸ���" << endl;

	return 0;
}