//04_�����Լ������� ������ ������
#include <iostream>
using namespace std;

class Sample
{
public:
	Sample operator+(const Sample & r) { }
};

Sample operator-(const Sample & r1, const Sample & r2) {}

int main()
{
	Sample s1;
	Sample s2;
	Sample s3 = s1 + s2;	//�ɹ��Լ����� : s1.operator+(s2);   ����!!!
						    //�����Լ����� : operator+(s1, s2);
	Sample s4 = s1 - s2;
	return 0;
}