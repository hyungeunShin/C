//04_데이터 은닉_접근지정자
//맴버변수를 외부로 노출시켰더니 불안전하다.
//따라서 데이터 은닉이 필요하다...
//[문법]
//접근 지정자
//- public		: 공용, 누구나 사용가능
//- protected	
//- private		: 은닉, 외부에서는 접근 불가능!
#include <iostream>
using namespace std;

struct TV
{
private:
	int channel;	//1~50

public:
	void inputchannel(int c)
	{
		if (c < 1 || c > 50)
			return;

		channel = c;
	}
};

int main()
{
	TV  tv1;
//	tv1.channel = 100;		//데이터 접근
	tv1.inputchannel(100);	//메서드 접근

	return 0;
}