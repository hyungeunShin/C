//04_���۷���
/*
���� ������ �ٴ� ����
*/
#include <iostream>
using std::cout;		
using std::endl;
using std::cin;

//���� ������ �ٴ� ����(�ݵ�� ����� ���ÿ� �ʱ�ȭ)
void exam1()
{
	int number;					//���� ���� 
	int& r_number = number;		//���۷���(����� ������ ���� ó��)

	number = 10;
	cout << number << endl; //10
	cout << r_number << endl; //10

	r_number = 20;
	cout << number << endl;		//20
	cout << r_number << endl;	//20

	cout << &number << endl;	//�ּ����(����)
	cout << &r_number << endl;	//�ּ����(����)
}


/*
��뿹1) �Լ��� ���� ����
C���
1) �� ����(call by value)		: ���� ���� 
2) �ּ� ����(call by address)	: ���� �ּҸ� �����ؼ� ���� ����!
C++ �ϳ��� �� �߰���
3) ������ ����(call by reference) : 2�� ��ɰ� ������ ������ ���´�.
*/
void exam2_fun(int n1, int* pn2, int & n3)
{
	n1 = 20;
	*pn2 = 30;
	n3 = 40;
}

void exam2()
{
	int number = 10;
	exam2_fun(number, &number, number); //V, A, R

	cout << number << endl;  // 30 -> 40 
}


/*
��뿹2) ������ ��ȯ
*/
int g_arr[5] = { 1, 2, 3, 4, 5 };  //��������

int getdata1_exam3(int idx)		{		return g_arr[idx];		}
int& getdata2_exam3(int idx)	{		return g_arr[idx];		}

void exam3()
{
	//�Լ��� ȣ���� ���Կ����� R value�� �־���.
	int value;
	value = getdata1_exam3(1);		// value = 2;
	cout << value << endl;			// 2

	//getdata1_exam3(2) = value;		// 3 = 2;	// ��� = ���;
	//------------------------------------------------------------------------

	//���� ȣ��� �Լ��� ��ȯŸ���� �����ڶ�� ���Կ����� L value���� ����� �����ϴ�.
	value = getdata2_exam3(1);		// value = g_arr[1]; --> value = 2;
	cout << value << endl;			// 2

	getdata2_exam3(2) = value;		// g_arr[2] = 2;	// �����ǰ��� = ���;
	cout << g_arr[2] << endl;		// 2
}


int main()
{
	exam3();
	return 0;
}