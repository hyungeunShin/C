//02_�Լ� ���ø� ����

#include <iostream>
using namespace std;

template<typename T>
T myadd(T n1, T n2, T n3)
{
	return n1 + n2 + n3;
}

template<typename T1, typename T2>
T1 mysub(T1 n1, T2 n2, T2 n3)
{
	return n1 - n2 - n3;
}

int main()
{
	//�Լ� ���ø��� ȣ��!!!
	//1. �Ͻ��� ȣ����
	cout << myadd(10, 20, 30) << endl;			// T -> int
	cout << myadd(10.1, 20.2, 30.3) << endl;	// T -> double

	cout << mysub(10.1, 20, 10) << endl;		// T1 -> doube, T2 -> int

	//2. ����� ȣ����
	cout << myadd<int>(10, 20, 30) << endl;					// T -> int
	cout << myadd<double>(10.1, 20.2, 30.3) << endl;		// T -> double

	cout << mysub<double, int>(10.1, 20, 10) << endl;		// T1 -> doube, T2 -> int
}