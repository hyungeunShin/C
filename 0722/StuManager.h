//stumanager.h
#pragma once

#include <vector>
using namespace std;
#include "Stu.h"

class StuManager
{
	vector<Stu*> base;		//Stu*를 저장하는 배열이 생성(ca:0, size:0)
public:
	StuManager();
	~StuManager();

private:
	void Exist(int number);
	Stu* NameToStu(string name);  //전통적 검색 방식

public:
	void AddStu();
	void ListAll();
	void RemoveStu();
	void SearchStuByNum();
	void SearchStuByName();
	void UpdateName();
};

