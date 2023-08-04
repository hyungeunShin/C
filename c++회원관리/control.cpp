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
			delete(members[i]);  //주소전달 -> 그 주소에 있는 객체를 소멸처리
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
	cout << "[회원 정보 저장]\n" << endl;

	int idx, age;
	string name, phone;
	char gender;
	
	char temp[50];
	sprintf_s(temp, sizeof(temp), "저장할 인덱스(0~%d)", DATA_MAX - 1);
	idx = Wblib::getint(temp);
	if (members[idx] != NULL)
	{
		cout << "데이터가 존재하는 인덱스 입니다" << endl;
		return;
	}

	name	= Wblib::getstring("이름");
	phone	= Wblib::getstring("전화번호");	
	age		= Wblib::getint("나이");
	gender	= Wblib::getchar("성별(m/f)");

	Member *pmem = new Member(name, phone, age, gender);
	members[idx] = pmem;
	printf("저장되었습니다\n");
}

void Control::select() const
{
	cout << "[회원 정보 검색]\n" << endl;
	 
	string name = Wblib::getstring("검색할 이름");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "해당 이름은 존재하지 않습니다." << endl;
		return;
	}

	Member *pmem = members[idx];
	pmem->println();
}

void Control::update()
{
	cout << "[회원 정보 수정]\n" << endl;

	string name = Wblib::getstring("검색할 이름");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "해당 이름은 존재하지 않습니다." << endl;
		return;
	}

	//수정작업
	Member* pmem = members[idx];

	string phone = Wblib::getstring("전화번호");
	int age		 = Wblib::getint("나이");

	pmem->setphone(phone);
	pmem->setage(age);

	printf("수정되었습니다\n");

}

void Control::delete1()
{
	cout << "[회원 정보 삭제]\n" << endl;

	string name = Wblib::getstring("삭제할 이름");

	int idx = nametoidx(name);
	if (idx == -1)
	{
		cout << "해당 이름은 존재하지 않습니다." << endl;
		return;
	}

	//삭제작업
	Member* pmem = members[idx];

	delete(pmem); 
	members[idx] = NULL;

	cout << "삭제되었습니다" << endl;
}

int Control::nametoidx(string name) const
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		Member *pmem = members[i];
		//주소를 갖고 있느냐?
		//주소를 가지고 있다면 그 이름이 name이 맞느냐?
		if (pmem != NULL && pmem->getname() ==  name) 
		{
			return i;
		}
	}
	return -1;
}