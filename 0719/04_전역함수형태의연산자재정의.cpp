//04_전역함수형태의 연산자 재정의
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
	Sample s3 = s1 + s2;	//맴버함수형태 : s1.operator+(s2);   권장!!!
						    //전역함수형태 : operator+(s1, s2);
	Sample s4 = s1 - s2;
	return 0;
}