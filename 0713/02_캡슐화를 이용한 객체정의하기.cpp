//02_ĸ��ȭ�� �̿��� ��ü �����ϱ�.
/*
- TV ��ü ����(�ɹ�����, �ɹ��Լ�==��� ����)
--------------------------------------
TV
--------------------------------------
bool onoff; 
int  channel;   // 1 ~ 50
int  volume;	// 0 ~ 20
--------------------------------------
void OnOff();			// onoff�� ����ó��(���)
void VolumeUp()			// volume�� ++
void VolumeDown()		// volume�� --
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
		cout << "  [ ���� ] " << (onoff==true? "ON" : "OFF") << endl;
		cout << "  [ ä�� ] " << channel << "��" << endl;
		cout << "  [ ���� ] " << volume << endl; 
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
		cout << "[0] ���α׷� ����" << endl; 
		cout << "[1] ���� [2] ����UP [3] ����DOWN [4]ä��UP [5]ä��DOWN [6]ä�μ���" << endl;
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
					cout << "ä�� �Է� : ";
					cin >> input;
					tv1.ChannelInput(input);
					break;
				}
		}
		//system("pause");
	}

	return 0;
}