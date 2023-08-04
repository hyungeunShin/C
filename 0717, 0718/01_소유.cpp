//01_소유
/*
[학생]이 [펜]으로 글씨를 쓰다.
-> 다른 객체의 기능을 사용하려면 해당 객체를 소유해야 한다.
*/

#include <iostream>
using namespace std;

class Pen
{
private:
	string color;
public:
	Pen()				{ color = "검정"; }
	Pen(string _color) { this->color = _color; }

public:
	void write(string msg)
	{
		cout << "[" << color.c_str() << "] ";
		cout << msg.c_str() << endl;
	}
};

class Student
{
private:
	string name;
	Pen * pen;		//펜을 소유하기 위한 맴버 필드
public:
	Student(string _name)	{ name = _name;  pen = NULL; }

public:
	void in_pen(Pen *pen)	{ this->pen = pen;			}
	void write_pen() 
	{
		pen->write("글씨를 출력합니다");
	}
	void out_pen()			{ this->pen = NULL;			}
};

int main()
{
	//모든 객체가 생성됨!!!!
	Student stu("홍길동");
	Pen red_pen("빨강");
	Pen black_pen;

	//---------------------------------------------------
	//필요에 의해서 소유와 해제가 반복...[일시적 소유]
	stu.in_pen(&red_pen);
	stu.write_pen();
	stu.out_pen();

	stu.in_pen(&black_pen);
	stu.write_pen();
	stu.out_pen();

	return 0;
}

