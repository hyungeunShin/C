//03_상속.cpp
/*
사람(이름, 나이)
학생(이름, 나이, 학교, 학과)
*/

#include <iostream>
using namespace std;

//상속을 사용하지 않은 구조
/*
class Person
{
private:
	string name;
	int age;
};

class Student
{
private:
	string name;
	int age;
	string univer;		//학교
	string subject;		//학과
};
*/

//상속구조 : 부모(Person)와 자식(Student) 간 관계
//           부모의 맴버들이 자식에게 전달!
class Person
{
private:
	string name;
	int age;
};

class Student : public Person
{
private:
//	string name;
//	int age;
	string univer;		//학교
	string subject;		//학과
};
int main()
{
	return 0;
}