//08_최종코드
/*
상속 구조
생성자를 이용한 객체 초기화
재정의(오버라이드)
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
	void Print() const  //오버로드 구조 
	{
		Person::Print();
		cout << univer.c_str() << endl;
		cout << subject.c_str() << endl;
	}
};

int main()
{
	Student stu("홍길동", 20, "우송대", "컴퓨터");
	stu.Print(); //자신의 메서드

	return 0;
}