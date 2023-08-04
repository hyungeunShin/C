//stumanager.h
#pragma once

#include <vector>
using namespace std;
#include "Stu.h"

class StuManager
{
	vector<Stu*> base;		//Stu*�� �����ϴ� �迭�� ����(ca:0, size:0)
public:
	StuManager();
	~StuManager();

private:
	void Exist(int number);
	Stu* NameToStu(string name);  //������ �˻� ���

public:
	void AddStu();
	void ListAll();
	void RemoveStu();
	void SearchStuByNum();
	void SearchStuByName();
	void UpdateName();
};

