//01_캡슐화.cpp

//시간을 관리하는 프로그램
//현재시간 저장, 출력,원하는 시간으로 변경처리 출력,

#include <iostream>
using namespace std;

//1단계) C언어 함수 배우기 전단계
/*
int main()
{
	int hour;
	int min;
	int sec;

	//현재 시간 저장
	hour = 9;
	min = 47;
	sec = 21;

	//현재 시간 출력
	cout << hour << ":" << min << ":" << sec << endl; 

	//현재 시간을 10:50:33
	hour = 10;
	min = 50;
	sec = 33;

	//변경된 시간을 출력
	cout << hour << ":" << min << ":" << sec << endl;

	return 0;
}
*/


//2단계) C언어 함수를 배웠다.
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

	//현재 시간 저장
	current_time(&hour, &min, &sec);

	//현재 시간 출력
	print_time(hour, min, sec);

	//현재 시간을 10:50:33
	update_time(&hour, &min, &sec, 10, 50, 33);

	//변경된 시간을 출력
	print_time(hour, min, sec);

	return 0;
}
*/

//3단계) C언어 구조체를 배웠다.
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

	//현재 시간 저장
	current_time(&t1);

	//현재 시간 출력
	print_time(t1);

	//현재 시간을 10:50:33
	update_time(&t1, 10, 50, 33);

	//변경된 시간을 출력
	print_time1(t1.hour, t1.min, t1.sec);

	return 0;
}
*/
//-----------------------------------------------------------------

//4단계) C++의 구조체를 활용한 캡슐화의 개념.
//       캡슐화 : 데이터와 함수를 묶어 놓았다.
//       
struct mytime
{
	//맴버변수
	int hour;
	int min;
	int sec;

	//맴버함수
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

	//현재 시간 저장
	t1.current_time();  //t1의 맴버함수 호출	//current_time(&t1);

	//현재 시간 출력
	t1.print_time(); //print_time(t1);

	//현재 시간을 10:50:33
	t1.update_time(10, 50, 30);  //update_time(&t1, 10, 50, 33);

	//변경된 시간을 출력
	t1.print_time(); //print_time(t1);

	return 0;
}
