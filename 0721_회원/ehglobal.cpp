//ehglobal.cpp

#include <conio.h>			//_getch()
#include "ehglobal.h"

ehglobal::ehglobal()
{
}

ehglobal::~ehglobal()
{
}

void ehglobal::clrscr()//ȭ���� ����� �޼���
{
	system("cls");
}

void ehglobal::pausescr()
{
	system("pause");
}

int ehglobal::getnum()	//������ �Է¹޴� �޼���
{
	int num;
	char buf[255 + 1];
	cin.getline(buf, 255);		//���ۿ� �Է¹���
	cin.clear();				//cin ���� ���۸� ����
	//���ڿ� --> �⺻�� Ÿ�� ��ȯ!
	sscanf_s(buf, "%d", &num); //���˿� �°� ���ۿ� ������ ������ ��ȯ
	return num;
}

string ehglobal::getstr()//���ڿ��� �Է¹޴� �޼���
{
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	return buf;
}

char ehglobal::getchar()
{
	char ch;
	char buf[255 + 1];
	cin.getline(buf, 255);		//���ۿ� �Է¹���
	cin.clear();				//cin ���� ���۸� ����
	//���ڿ� --> �⺻�� Ÿ�� ��ȯ!
	sscanf_s(buf, "%c", &ch, sizeof(char)); //���˿� �°� ���ۿ� ������ ������ ��ȯ
	return ch;
}

keydata ehglobal::getkey()//��� Ű�� �Է¹޴� �޼���
{
	int key = _getch();
	if (key == 27) //ESC�� ���� ���� key ���� 27��
	{
		return ESC;
	}
	if (key == 0) //��� Ű�� ������ ���� getch�� ��ȯ���� 0��
	{
		//� ��� Ű�� �������� Ȯ���Ϸ��� getch�� �ٽ� ȣ���ؾ� ��
		//����ڿ��� �ٽ� Ű�� �Է¹޴� ���� �ƴ�
		key = _getch();
		switch (key) //�Է��� Ű�� ���� ��ӵ� �� ��ȯ
		{
		case 59: return F1;
		case 60: return F2;
		case 61: return F3;
		case 62: return F4; 
		case 63: return F5;
		case 64: return F6;
		case 65: return F7;
		}
	}
	return NO_DEFINED; //���ŵ��� ���� Ű�� ������ ��
}