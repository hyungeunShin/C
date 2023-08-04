////stumanager.cpp

#include <iostream>
using namespace std;
#include "ehglobal.h"
#include "StuManager.h"

StuManager::StuManager() : max_stu(SetMaxStu())
{
	base.resize(max_stu, 0);
}

StuManager::~StuManager()
{
	for (int i = 0; i<max_stu; i++)		//base.size()
	{
		if (base[i] != NULL) //실제 학생이 보관된 곳인지 확인
		{
			delete base[i];		//힙메모리에 생성된 객체를 소멸
			base[i] = NULL;		//배열의 주소를 NULL로 변경
		}
	}
}

int StuManager::SetMaxStu()
{
	cout << "최대 관리할 회원 수를 입력하세요 : ";
	return ehglobal::getnum();
}


int StuManager::InputNumber()
{
	cout << "추가할 회원 번호를 입력하세요(0 ~ " << max_stu-1 << ") : ";
	int num = ehglobal::getnum();
	if ((num < 0) || (num >= max_stu))
		throw "범위를 벗어났습니다."; 

	if (base[num]) //실제 학생이 보관되었는지 확인
		throw "이미 보관된 회원이 있습니다.";

	return num;
}

int StuManager::InputNumber(string type)
{
	cout << "[" << type.c_str() << "]" << "학생 번호를 입력하세요(0 ~" << max_stu - 1 << ") : ";
	int num = ehglobal::getnum();
	if ((num < 0) || (num >= max_stu))
		throw "범위를 벗어났습니다.";

	if (base[num] == NULL) //실제 학생이 보관되었는지 확인
		throw "보관된 학생이 없습니다.";

	return num;
}

//입력 정보 수정
void StuManager::AddMember()
{
	try
	{
		int number = InputNumber();

		cout << "이름을 입력하세요 : ";
		string name = ehglobal::getstr();

		cout << "전화번호를 입력하세요 : ";
		string phone = ehglobal::getstr();

		cout << "나이를 입력하세요 : ";
		int age = ehglobal::getnum();

		cout << "성별을 입력하세요 : ";
		char gender = ehglobal::getchar();

		Member* pstu = new Member(number, name, phone, age, gender);

		base[number] = pstu;

		cout << "저장 성공" << endl;
	}
	catch (const char* msg)
	{
		cout << ">> 입력 에러 : " << msg << endl;
	}
}

//1.순회 후 객체 출력
void StuManager::ListAll()
{
	for (int i = 0; i<max_stu; i++)
	{
		Member *pmem = base[i];
		if (pmem != NULL) //실제 학생이 보관되었는지 확인
			cout << pmem << endl;
	}
}

//1. 삭제할 번호 입력(삭제할 인덱스와 동일)  [2. 힙메모리 삭제   3. 자신의 메모리를 NULL초기화]
void StuManager::RemoveMember()
{
	try
	{
		int num = InputNumber("삭제");

		delete base[num];
		base[num] = NULL; //초기값 0으로 다시 설정

		cout << "삭제 되었습니다." << endl; 
	}
	catch (const char* msg)
	{
		cout << "삭제 에러 : " << msg << endl; 
	}
}

void StuManager::SearchMemberByNum()
{
	try
	{
		int num = InputNumber("검색");

		Member* pmem = base[num];
		pmem->println();
	}
	catch (const char* msg)
	{
		cout << "검색 에러 : " << msg << endl;
	}	
}

//순차 검색
Member* StuManager::NameToMember(string name)
{
	for (int i = 0; i<max_stu; i++)
	{
		Member* pmem = base[i];

		if (pmem != NULL) //실제 학생이 보관되었는지 확인
		{
			if (pmem->getname() == name)
				return pmem;
		}
	}
	throw "보관되지 않은 학생입니다.";
}

void StuManager::SearchMemberByName()
{
	try
	{
		cout << "검색할 학생 이름을 입력하세요 : ";
		string name = ehglobal::getstr();

		Member *pmem = NameToMember(name);
		pmem->println();
	}
	catch (const char* msg)
	{
		cout << "검색 에러 : " << msg << endl; 
	}
}

void StuManager::UpdateMember()
{
	try
	{
		int num		  =	InputNumber("수정");   //객체가 저장되어 있는 인덱스를 찾는 과정!

		cout << "수정할 학생의 전화번호를 입력하세요 : ";
		string phone = ehglobal::getstr();

		cout << "수정할 학생의 나이를 입력하세요 : ";
		int age = ehglobal::getnum();

		Member* pmem = base[num];
		pmem->setphone(phone);
		pmem->setage(age); 

		cout << "수정되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "수정 에러 : " << msg << endl;
	}
}
