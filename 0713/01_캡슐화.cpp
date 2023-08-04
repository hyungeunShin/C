//01_ĸ��ȭ.cpp

//�ð��� �����ϴ� ���α׷�
//����ð� ����, ���,���ϴ� �ð����� ����ó�� ���,

#include <iostream>
using namespace std;

//1�ܰ�) C��� �Լ� ���� ���ܰ�
/*
int main()
{
	int hour;
	int min;
	int sec;

	//���� �ð� ����
	hour = 9;
	min = 47;
	sec = 21;

	//���� �ð� ���
	cout << hour << ":" << min << ":" << sec << endl; 

	//���� �ð��� 10:50:33
	hour = 10;
	min = 50;
	sec = 33;

	//����� �ð��� ���
	cout << hour << ":" << min << ":" << sec << endl;

	return 0;
}
*/


//2�ܰ�) C��� �Լ��� �����.
/*
void current_time(int*h, int*m, int*s)
{
	*h = 9;
	*m = 47;
	*s = 21;
}
void print_time(int h, int m, int s)
{
	cout << h << ":" << m << ":" << s << endl;
}
void update_time(int*h, int*m, int*s, int uh, int um, int us)
{
	*h = uh;
	*m = um;
	*s = us;
}
int main()
{
	int hour;
	int min;
	int sec;

	//���� �ð� ����
	current_time(&hour, &min, &sec);

	//���� �ð� ���
	print_time(hour, min, sec);

	//���� �ð��� 10:50:33
	update_time(&hour, &min, &sec, 10, 50, 33);

	//����� �ð��� ���
	print_time(hour, min, sec);

	return 0;
}
*/

//3�ܰ�) C��� ����ü�� �����.
/*
typedef struct mytime mytime;
struct mytime
{
	int hour;
	int min;
	int sec;
};

void current_time(mytime* t)
{
	(*t).hour	= 9;
	t->min		= 47;
	t->sec		= 21;
}
void print_time(mytime t)
{
	cout << t.hour << ":" << t.min << ":" << t.sec << endl;
}
void update_time(mytime* t, int uh, int um, int us)
{
	t->hour		= uh;
	t->min		= um;
	t->sec		= us;
}
void print_time1(int h, int m, int s)
{
	cout << h << ":" << m << ":" << s << endl;
}

int main()
{
	mytime t1; //hour, min, sec

	//���� �ð� ����
	current_time(&t1);

	//���� �ð� ���
	print_time(t1);

	//���� �ð��� 10:50:33
	update_time(&t1, 10, 50, 33);

	//����� �ð��� ���
	print_time1(t1.hour, t1.min, t1.sec);

	return 0;
}
*/
//-----------------------------------------------------------------

//4�ܰ�) C++�� ����ü�� Ȱ���� ĸ��ȭ�� ����.
//       ĸ��ȭ : �����Ϳ� �Լ��� ���� ���Ҵ�.
//       
struct mytime
{
	//�ɹ�����
	int hour;
	int min;
	int sec;

	//�ɹ��Լ�
	void current_time()
	{
		hour = 9;
		min = 47;
		sec = 21;
	}
	void print_time()
	{
		cout << hour << ":" << min << ":" << sec << endl;
	}
	void update_time(int uh, int um, int us)
	{
		hour = uh;
		min = um;
		sec = us;
	}	
};

int main()
{
	mytime t1; //hour, min, sec

	//���� �ð� ����
	t1.current_time();  //t1�� �ɹ��Լ� ȣ��	//current_time(&t1);

	//���� �ð� ���
	t1.print_time(); //print_time(t1);

	//���� �ð��� 10:50:33
	t1.update_time(10, 50, 30);  //update_time(&t1, 10, 50, 33);

	//����� �ð��� ���
	t1.print_time(); //print_time(t1);

	return 0;
}
