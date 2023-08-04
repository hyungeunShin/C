//06_생성자
/*
주 역할 : 객체 초기화(생성과 동시에 맴버변수의 값을 초기화)

특징 : 특수한 형태의 맴버 함수
       객체가 생성될 때 자동으로 호출된다.(내가 직접 호출할 수 없는 함수)

형태 : 리턴이 없다.
       함수의 이름이 약속되어 있다. : 클래스명과 동일 
	   매개변수 리스트는 일반 함수처럼 사용할 수 있다. 

-> 생성자는 약속된 모양을 갖고 있다. 
   객체 생성시 [반드시] 자동으로 호출되어 객체를 초기화하는 역할을 수행한다.
*/
#include <iostream>
using namespace std;

class sample
{
	//맴버 변수(필드)
private:
	int number;
	char ch;
	char str[20];

	//생성자
public:
	sample(int n, char c, const char* s)
	{
		cout << "sample(int, char, const char*)" << endl; 
		number = n;
		ch = c;
		strcpy_s(str, sizeof(str), s);
	}
};

int main()
{
	//객체 생성 -> [반드시] 생성자 호출 발생!!!!!!
	sample s1(10, 'A', "test");

	return 0;
}