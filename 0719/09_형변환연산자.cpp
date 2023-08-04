//09_형변환 연산자
#include <iostream>
using namespace std;

class Member
{
private:
	string name;
	int age;
	char gender;
	float weight;
public:
	Member(string n, int a, char g, float w) : name(n), age(a), gender(g), weight(w) {}

public:
	operator int() { return age;  }
	operator char() { return gender;  }
	operator const char*() { return name.c_str();  }
};

int main()
{
	Member mem1("홍길동", 10, 'm', 20.12f);

	int age		= mem1;			cout << age << endl;  // 10
	char gender = mem1;			cout << gender << endl;  // m
	string str	= mem1;			cout << str.c_str() << endl;
}
