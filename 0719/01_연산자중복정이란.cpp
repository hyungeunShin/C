//01_�������ߺ����Ƕ�
//��ü�� �����ڸ� ����� �� �ֵ��� �����ϴ� ����!
//����? ������!
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

	//��ü++;  // int num = 10; num++;
	//�����ڸ� �̿��� ȣ���� �ɹ��Լ� ȣ�ⱸ���� ����!
	d1++;		// d1.operator++(); 
	d1.Print();

	return 0;
}