//06_상속과 객체 초기화
/*
[문법]
객체 초기화 : 자신의 생성자에서 자신의 객체(맴버변수) 정보를 초기화 한다.
        상속구조에서는 부모의 맴버변수를 자식객체가 물려받는다.
		물려받은 맴버변수의 초기화는 누가 해야 될것인가? (부모)

자식은 부모로부터 물려받은  private에 접근할 수 없다.
-> 해결1) 남과 동일한 방식
          get메서드 & set메서드 활용
-> 해결2) 자식에게까지 접근을 허용하는 접근 지정자로 변경 처리 : protected
*/
#include <iostream>
using namespace std;

class Person
{
protected:				//상속구조에서 나오는 접근 지정자(자신 + 자식)
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
	void Print1() const
	{
		//이름?
		//나이?
		//물려받은 메서드를 호출!
		//Print();
		cout << name.c_str() << endl;
		cout << age << endl; 
		cout << univer.c_str() << endl;
		cout << subject.c_str() << endl; 
	}
};

int main()
{
	Student stu("홍길동", 20, "우송대", "컴퓨터");

//	stu.Print();  //부모로부터 물려받은 메서드
	stu.Print1(); //자신의 메서드

	return 0;
}