//control.cpp
#include "std.h"

Control::Control()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		members[i] = NULL;
	}
}

Control::~Control()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (members[i] != NULL)
		{
			delete(members[i]);  //�ּ����� -> �� �ּҿ� �ִ� ��ü�� �Ҹ�ó��
			members[i] = NULL;
		}
	}
}

void Control::printall() const
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		Member* pmem = members[i];
		if (pmem != NULL)
		{
			printf("%d : ", i);
			pmem->print();
		}
	}
}

void Control::insert()
{
	cout << "[ȸ�� ���� ����]\n" << endl;

	int idx, age;
	string name, phone;
	char gender;
	
	char temp[50];
	sprintf_s(temp, sizeof(temp), "������ �ε���(0~%d)", DATA_MAX - 1);
	idx = Wblib::getint(temp);
	if (members[idx] != NULL)
	{
		cout << "�����Ͱ� �����ϴ� �ε��� �Դϴ�" << endl;
		return;
	}

	name	= Wblib::getstring("�̸�");
	phone	= Wblib::getstring("��ȭ��ȣ");	
	age		= Wblib::getint("����");
	gender	= Wblib::getchar("����(m/f)");

	Member *pmem = new Member(name, phone, age, gender);
	members[idx] = pmem;
	printf("����Ǿ����ϴ�\n");
}

void Control::select() const
{
	cout << "[ȸ�� ���� �˻�]\n" << endl;
	 
	string name = Wblib::getstring("�˻��� �̸�");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "�ش� �̸��� �������� �ʽ��ϴ�." << endl;
		return;
	}

	Member *pmem = members[idx];
	pmem->println();
}

void Control::update()
{
	cout << "[ȸ�� ���� ����]\n" << endl;

	string name = Wblib::getstring("�˻��� �̸�");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "�ش� �̸��� �������� �ʽ��ϴ�." << endl;
		return;
	}

	//�����۾�
	Member* pmem = members[idx];

	string phone = Wblib::getstring("��ȭ��ȣ");
	int age		 = Wblib::getint("����");

	pmem->setphone(phone);
	pmem->setage(age);

	printf("�����Ǿ����ϴ�\n");

}

void Control::delete1()
{
	cout << "[ȸ�� ���� ����]\n" << endl;

	string name = Wblib::getstring("������ �̸�");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "�ش� �̸��� �������� �ʽ��ϴ�." << endl;
		return;
	}

	//�����۾�
	Member* pmem = members[idx];

	delete(pmem); 
	members[idx] = NULL;

	cout << "�����Ǿ����ϴ�" << endl;
}

int Control::nametoidx(string name) const
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		Member *pmem = members[i];
		//�ּҸ� ���� �ִ���?
		//�ּҸ� ������ �ִٸ� �� �̸��� name�� �´���?
		if (pmem != NULL && pmem->getname() ==  name) 
		{
			return i;
		}
	}
	return -1;
}