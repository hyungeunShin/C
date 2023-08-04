//stumanager.h
#pragma once

#include <vector>
using namespace std;
#include "Stu.h"

class StuManager
{
	vector<Stu*> base;		//Stu*�� �����ϴ� �迭�� ����(ca:0, size:0)
	const int max_stu;		//�ִ� ������ �� �ִ� �л� ��(�ִ� �л� ��ȣ�̱⵵ ��)
public:
	StuManager();
	~StuManager();

private:
	int SetMaxStu();
	int InputNumber();					//����� ��ȣ �Է�
	int InputNumber(string type);		//������,��ȣ �˻��� ��ȣ �Է�
	Stu* NameToStu(string name);

public:
	void AddStu();
	void ListAll();
	void RemoveStu();
	void SearchStuByNum();
	void SearchStuByName();
	void UpdateName();
};

