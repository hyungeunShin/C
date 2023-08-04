//08_cin과 묵시적 형변환
#include <iostream>
using namespace std;

int getInt(const char* msg)
{
	int number;

	while (true)
	{
		cout << msg << " : ";
		cin >> number;
		if (cin)	//상태정보<---------------------------
			break;
		else
		{				
			cin.clear(); ////cin객체를 초기화
			cin.ignore(); //버퍼 비워주기
		}
	}
	return number;
}

int main()
{
	int number = getInt("정수 입력");
	cout << number << endl;
	return 0;
}