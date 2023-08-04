//01_����
/*
[�л�]�� [��]���� �۾��� ����.
-> �ٸ� ��ü�� ����� ����Ϸ��� �ش� ��ü�� �����ؾ� �Ѵ�.
*/

#include <iostream>
using namespace std;

class Pen
{
private:
	string color;
public:
	Pen()				{ color = "����"; }
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
	Pen * pen;		//���� �����ϱ� ���� �ɹ� �ʵ�
public:
	Student(string _name)	{ name = _name;  pen = NULL; }

public:
	void in_pen(Pen *pen)	{ this->pen = pen;			}
	void write_pen() 
	{
		pen->write("�۾��� ����մϴ�");
	}
	void out_pen()			{ this->pen = NULL;			}
};

int main()
{
	//��� ��ü�� ������!!!!
	Student stu("ȫ�浿");
	Pen red_pen("����");
	Pen black_pen;

	//---------------------------------------------------
	//�ʿ信 ���ؼ� ������ ������ �ݺ�...[�Ͻ��� ����]
	stu.in_pen(&red_pen);
	stu.write_pen();
	stu.out_pen();

	stu.in_pen(&black_pen);
	stu.write_pen();
	stu.out_pen();

	return 0;
}

