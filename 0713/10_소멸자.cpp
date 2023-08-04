//10_�Ҹ���
/*
[��ü ������]
1. �޸� ����(�ɹ� ����)
2. ������ ȣ��
   �����Ϸ��� ����� �ִ� ������ -> Ŭ������() { } 

[��ü �Ҹ��]
1. �Ҹ��� ȣ��
   �����Ϸ��� ����� �ִ� �Ҹ��� -> ~Ŭ������() { }
2. �޸� ����

* �Ҹ��ڴ� ����� 1��.
  ��ȯŸ�� X
  �̸�    ~Ŭ������
  �Ű����� X
*/
#include <iostream>
using namespace std;

class Sample
{
public:
	Sample()		{ cout << "Sample()" << endl;			}		//1
	Sample(int n)	{ cout << "Sample(int)" << endl;	}		//2

	~Sample()		{ cout << "~Sample()" << endl;		}		//3
};

int main()
{
//	Sample s1;			//1 -> 3
//	Sample s2(10);		//2 -> 3 

//	Sample s3[3];    //1, 1, 1 -> 3, 3, 3 
//	Sample s4[3] = { Sample(10), Sample(2) };	// 2, 2, 1 -> 3, 3, 3 

	//---------------------------------
//	Sample *p1;	//��ü ������ �ƴ϶� ��ü�� �ּҸ� �����ϴ� 4byte �޸𸮸� ����
//	p1 = new Sample;  //heap�޸𸮿� Sample 1���� ����.		// 1

//	delete p1;		//heap �޸� �Ҹ�ó��					// 3

	//-------------------------------------------
//	Sample *p2;
//	p2 = new Sample(10);	// 2

//	delete p2;				//3

	//----------------------------------------------------------
	Sample * arr[5];	// ��ü�� �ּҸ� 5�� �����ϴ� ������ ����!

	arr[0] = new Sample;			//1
	arr[1] = new Sample(10);		//2
	arr[2] = new Sample(30);		//2

	delete arr[0];					//3
	delete arr[1];					//3
	delete arr[2];					//3

	return 0;
}