//stumanager.h
#pragma once

#include <vector>
using namespace std;
#include "Member.h"			//<--------------------------------------------------------

class StuManager
{
	vector<Member*> base;		//Stu*�� �����ϴ� �迭�� ����(ca:0, size:0)	 //<---------------------------------------
	const int max_stu;		//�ִ� ������ �� �ִ� �л� ��(�ִ� �л� ��ȣ�̱⵵ ��)
public:
	StuManager();
	~StuManager();

private:
	int SetMaxStu();
	int InputNumber();					//����� ��ȣ �Է�
	int InputNumber(string type);		//������,��ȣ �˻��� ��ȣ �Է�
	Member* NameToMember(string name);			//<-------------------------------------------------

public:
	void AddMember();
	void ListAll();
	void RemoveMember();
	void SearchMemberByNum();
	void SearchMemberByName();
	void UpdateMember();
};

