//05_��¿�����������
#include <iostream>
using namespace std;

class Member
{
private:
	string name;
	int age;
public:
	Member(string _name, int _age) : name(_name), age(_age) {}

public://���� ���� ����(friend : ģ�� ���踦 ������ �� ������ �ٺ����ش�.(private))
	friend ostream& operator<<(ostream & cout, const Member & m);
};

ostream& operator<<(ostream & cout, const Member & m)
{
	cout << m.name.c_str() << ", " << m.age;
	return cout;
}

int main()
{
	Member mem("ȫ�浿", 10);
	cout << mem;		// cout.operator<<(mem);	 //1					
						// operator<<(cout, mem)
}
