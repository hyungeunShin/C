////stumanager.cpp

#include <iostream>
#include <algorithm>
using namespace std;
#include "ehglobal.h"
#include "StuManager.h"

StuManager::StuManager() 
{
}

StuManager::~StuManager()
{

	for (int i = 0; i< (int)base.size(); i++)		//base.size()
	{
		delete base[i];		//힙메모리에 생성된 객체를 소멸
		base[i] = NULL;		//배열의 주소를 NULL로 변경	
	}
}


void StuManager::Exist(int number)
{
	vector<Stu*>::iterator seek = base.begin();
	vector<Stu*>::iterator end = base.end();

	for (; seek != end; seek++)
	{
		Stu* pstu = *seek;
		if (pstu->GetNum() == number)
			throw "동일한 번호가 존재합니다.";
	}
}

//전통적 검색 방식(순차 검색)
Stu* StuManager::NameToStu(string name)
{
	for (int i = 0; i< (int)base.size(); i++)
	{
		Stu* pstu = base[i];

		if (pstu != NULL) //실제 학생이 보관되었는지 확인
		{
			if (pstu->GetName() == name)
				return pstu;
		}
	}
	throw "보관되지 않은 학생입니다.";
}


//1. 임시변수선언 2.초기화  3.임시변수를이용해 저장객체를 생성  4. 저장
void StuManager::AddStu()
{
	try
	{
		cout << "학생 번호를 입력하세요: ";
		int number = ehglobal::getnum();
		Exist(number);		//존재한다면 예외를 발생!

		cout << "이름을 입력하세요 : ";
		string name = ehglobal::getstr();	

		Stu* pstu = new Stu(number, name);

		base.push_back(pstu);			//<-- 0번째부터 순차적으로 저장!

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
	for (int i = 0; i< (int)base.size(); i++)
	{
		Stu *pstu = base[i];
		if (pstu != NULL) //실제 학생이 보관되었는지 확인
			cout << pstu << endl;
	}
}

//1. 삭제할 번호 입력(삭제할 인덱스와 동일)  [2. 힙메모리 삭제   3. 자신의 메모리를 NULL초기화]
void StuManager::RemoveStu()
{
	try
	{
		cout << "학생 번호를 입력하세요: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr = 
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>

		//힙에 생성된 STU객체는 직접 소멸처리
		Stu* pdel = *itr;
		delete pdel;

		base.erase(itr);	//백터컨테이너에서 주소가 사라짐.!

		cout << "삭제 되었습니다." << endl; 
	}
	catch (const char* msg)
	{
		cout << "삭제 에러 : " << msg << endl; 
	}
}


void StuManager::SearchStuByNum()
{
	try
	{
		cout << "검색할 학생 번호를 입력하세요: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "해당 번호는 존재하지 않습니다.";

		Stu* pstu = *itr;
		pstu->Print();		
	}
	catch (const char* msg)
	{
		cout << "검색 에러 : " << msg << endl;
	}	
}


void StuManager::SearchStuByName()
{
	try
	{
		cout << "검색할 학생의 이름을 입력하세요: ";
		string name = ehglobal::getstr();

		CompareByName sbn(name);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "해당 번호는 존재하지 않습니다.";

		Stu* pstu = *itr;
		pstu->Print();
	}
	catch (const char* msg)
	{
		cout << "검색 에러 : " << msg << endl;
	}
}


void StuManager::UpdateName()
{
	try
	{
		cout << "검색할 학생 번호를 입력하세요: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "해당 번호는 존재하지 않습니다.";

		cout << "수정할 학생 이름을 입력하세요 : ";
		string name = ehglobal::getstr();

		Stu* pstu = *itr;
		pstu->setName(name);

		cout << "수정되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "수정 에러 : " << msg << endl;
	}
}
