//09_생성자예제1
/*
main 함수 코드를 참조하여 객체를 정의할 것!
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
	Student stu("111", "홍길동", "컴퓨터"); //학번(id), 이름(name), 학과(subject)
	stu.Print();  //111, 홍길동, 컴퓨터
	stu.setSubject("IT");
	stu.Print();  //111, 홍길동, IT

	return 0;
}