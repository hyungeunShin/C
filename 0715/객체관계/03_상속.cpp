//03_���.cpp
/*
���(�̸�, ����)
�л�(�̸�, ����, �б�, �а�)
*/

#include <iostream>
using namespace std;

//����� ������� ���� ����
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
	string univer;		//�б�
	string subject;		//�а�
};
*/

//��ӱ��� : �θ�(Person)�� �ڽ�(Student) �� ����
//           �θ��� �ɹ����� �ڽĿ��� ����!
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
	string univer;		//�б�
	string subject;		//�а�
};
int main()
{
	return 0;
}