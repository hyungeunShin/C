//05_출력연산자재정의
#include <iostream>
using namespace std;

class Member
{
private:
	string name;
	int age;
public:
	Member(string _name, int _age) : name(_name), age(_age) {}

public://좋지 않은 문법(friend : 친구 관계를 맺으면 내 모든것을 다보여준다.(private))
	friend ostream& operator<<(ostream & cout, const Member & m);
};

ostream& operator<<(ostream & cout, const Member & m)
{
	cout << m.name.c_str() << ", " << m.age;
	return cout;
}

int main()
{
	Member mem("홍길동", 10);
	cout << mem;		// cout.operator<<(mem);	 //1					
						// operator<<(cout, mem)
}
