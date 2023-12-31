//member.h

#pragma once

class Member
{
	///맴버 필드
private:
	int number;	//회원 번호(배열의 인덱스 번호를 저장)
	string name;	//이름( 중복되지 않는다.) <---
	string phone;	//전화번호 <--
	int age;		//나이 <--
	char gender;	//성별 <--

	///생성자 & 소멸자
public:
	Member(int _number, string _name, string _phone, int _age, char _gender);
	~Member();

	///get & set 메서드 ( 필요에 의해서 )
public:
	int getnumber() const	{ return number;	}
	string getname()  const	{ return name;		}
	string getphone() const	{ return phone;		}
	int getage() const		{ return age;		}
	char getgender() const	{ return gender;	}

	//void setname(string value)	{ name = value;		}
	void setphone(string value) { phone = value;	}
	void setage(int value)		{ age = value;		}
	//void setgender(char value)	{ gender = value;	}

	///기능 메서드
public:
	void print() const;
	void println() const;

	//전역함수를 친구화 한 코드.
	friend ostream &operator<<(ostream &os, Member *pm)
	{
		os << "[번호] " << pm->number << "\t[이름] " << pm->name.c_str() << "\t[전화번호] " << pm->phone.c_str()
			<< "\t[나이] " << pm->age << "\t[성별] " << pm->gender;
		return os;
	}

};