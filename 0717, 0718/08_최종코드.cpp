//08_�����ڵ�
/*
��� ����
�����ڸ� �̿��� ��ü �ʱ�ȭ
������(�������̵�)
*/
#include <iostream>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(string _name, int _age)
	{
		name = _name;
		age = _age;
	}
public:
	void Print() const
	{
		cout << name.c_str() << endl;
		cout << age << endl;
	}
};

class Student : public Person
{
private:
	string univer;
	string subject;
public:
	Student(string _name, int _age, string _uni, string _sub)
		: Person(_name, _age)			//<--------------------------------------
	{
		univer = _uni;
		subject = _sub;
	}

public:
	void Print() const  //�����ε� ���� 
	{
		Person::Print();
		cout << univer.c_str() << endl;
		cout << subject.c_str() << endl;
	}
};

int main()
{
	Student stu("ȫ�浿", 20, "��۴�", "��ǻ��");
	stu.Print(); //�ڽ��� �޼���

	return 0;
}