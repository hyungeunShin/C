//09_�����ڿ���1
/*
main �Լ� �ڵ带 �����Ͽ� ��ü�� ������ ��!
*/

#include <iostream>
using namespace std;

class Student
{
private:
	char id[20];
	char name[20];
	char subject[20];

public:
	Student(const char*_id, const char*_name, const char* _subject)
	{
		strcpy_s(id, sizeof(id), _id);
		strcpy_s(name, sizeof(name), _name);
		strcpy_s(subject, sizeof(subject), _subject);
	}

public:
	void Print()
	{
		cout << id << "\t";
		cout << name << "\t";
		cout << subject << endl; 
	}

	void setSubject(const char* _subject)
	{
		strcpy_s(subject, sizeof(subject), _subject);
	}
};

int main()
{
	Student stu("111", "ȫ�浿", "��ǻ��"); //�й�(id), �̸�(name), �а�(subject)
	stu.Print();  //111, ȫ�浿, ��ǻ��
	stu.setSubject("IT");
	stu.Print();  //111, ȫ�浿, IT

	return 0;
}