//stumanager.h
#pragma once

#include <vector>
using namespace std;
#include "Stu.h"

class StuManager
{
	vector<Stu*> base;		//Stu*를 저장하는 배열이 생성(ca:0, size:0)
	const int max_stu;		//최대 보관할 수 있는 학생 수(최대 학생 번호이기도 함)
public:
	StuManager();
	~StuManager();

private:
	int SetMaxStu();
	int InputNumber();					//저장시 번호 입력
	int InputNumber(string type);		//삭제시,번호 검색시 번호 입력
	Stu* NameToStu(string name);

public:
	void AddStu();
	void ListAll();
	void RemoveStu();
	void SearchStuByNum();
	void SearchStuByName();
	void UpdateName();
};

