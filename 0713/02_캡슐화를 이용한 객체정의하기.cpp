//02_캡슐화를 이용한 객체 정의하기.
/*
- TV 객체 정의(맴버변수, 맴버함수==기능 정의)
--------------------------------------
TV
--------------------------------------
bool onoff; 
int  channel;   // 1 ~ 50
int  volume;	// 0 ~ 20
--------------------------------------
void OnOff();			// onoff을 변경처리(토글)
void VolumeUp()			// volume을 ++
void VolumeDown()		// volume을 --
void ChannelUp()
void ChannelDown()
void ChannelInput(int c)
----------------------------------------
*/

#include <iostream>
using namespace std;
#include <conio.h>

struct TV
{
	bool onoff;
	int  channel;   // 1 ~ 50
	int  volume;	// 0 ~ 20

	void OnOff()
	{
		onoff = !onoff; // 
	}
	void VolumeUp()
	{
		if (onoff == false)
			return;

		if (volume == 20)
			return;
		volume++;
	}
	void VolumeDown()
	{
		if (onoff == false)
			return;

		if (volume == 0)
			return;
		volume--;
	}
	void ChannelUp()
	{		
		if (onoff == false)
			return;

		channel++;
		if (channel == 51)
			channel = 1;
	}
	void ChannelDown()
	{
		if (onoff == false)
			return;

		channel--;
		if (channel == -1)
			channel = 50;
	}
	void ChannelInput(int c)
	{
		if (onoff == false)
			return;

		if (c <0 || c>50)
			return;

		channel = c;
	}

	void Print()
	{
		cout << "--------------------------------------------------" << endl;
		cout << "  [ 전원 ] " << (onoff==true? "ON" : "OFF") << endl;
		cout << "  [ 채널 ] " << channel << "번" << endl;
		cout << "  [ 볼륨 ] " << volume << endl; 
		cout << "--------------------------------------------------" << endl;
	}
};

int main()
{
	TV  tv1 = { false, 1, 5};

	while (true)
	{
		system("cls");
		tv1.Print();
		cout << "*******************************************************" << endl;
		cout << "[0] 프로그램 종료" << endl; 
		cout << "[1] 전원 [2] 볼륨UP [3] 볼륨DOWN [4]채널UP [5]채널DOWN [6]채널선택" << endl;
		cout << "*******************************************************" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '0':  return 0;
		case '1':  tv1.OnOff();			break;
		case '2':  tv1.VolumeUp();		break;
		case '3':  tv1.VolumeDown();	break;
		case '4':  tv1.ChannelUp();		break;
		case '5':  tv1.ChannelDown();	break;
		case '6':
				{
					int input;
					cout << "채널 입력 : ";
					cin >> input;
					tv1.ChannelInput(input);
					break;
				}
		}
		//system("pause");
	}

	return 0;
}