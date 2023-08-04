//member.h

#pragma once

class Member
{
	///�ɹ� �ʵ�
private:
	static int  s_number;
	int number;		//ȸ�� ��ȣ
	string name;	//�̸�( �ߺ����� �ʴ´�.) <---
	string phone;	//��ȭ��ȣ <--
	int age;		//���� <--
	char gender;	//���� <--

	///������ & �Ҹ���
public:
	Member(string _name, string _phone, int _age, char _gender);
	~Member();

	///get & set �޼��� ( �ʿ信 ���ؼ� )
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

	///��� �޼���
public:
	void print() const;
	void println() const;
};