//03_�Լ� ���ø�����
// ���ø�Ư��ȭ(���ø�����ȭ)

// - [���ø�]������ �˰����� ������ �ִٸ� Ʋ�� �����Ͽ� �����Ϸ��� �Լ��� ���鵵�� �Ѵ�.
// - ����, �˰����� �ٸ��ٸ�????

#include <iostream>
using namespace std;

template<typename T>
bool myequals(T value1, T value2)
{
	return (value1 == value2);
}

//���ø�����ȭ
template<>
bool myequals(char* s1, char* s2)
{
	cout << "TEST" << endl;
	return (strcmp(s1, s2) == 0);
}

int main()
{
	cout << myequals(10, 20) << endl;			// 0
	cout << myequals<char>('A', 'A') << endl;	// 1

	float f1 = 10.1f;
	float f2 = 10.1f;
	cout << myequals(f1, f2) << endl;			// 1

	
	char str1[] = "aaa";
	char str2[] = "aaa";
	cout << myequals(str1,str2) << endl;		// 0
	return 0;
}
