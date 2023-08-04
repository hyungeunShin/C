//member.h

#pragma once

class Member
{
	///�ɹ� �ʵ�
private:
	int number;	//ȸ�� ��ȣ(�迭�� �ε��� ��ȣ�� ����)
	string name;	//�̸�( �ߺ����� �ʴ´�.) <---
	string phone;	//��ȭ��ȣ <--
	int age;		//���� <--
	char gender;	//���� <--

	///������ & �Ҹ���
public:
	Member(int _number, string _name, string _phone, int _age, char _gender);
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

	//�����Լ��� ģ��ȭ �� �ڵ�.
	friend ostream &operator<<(ostream &os, Member *pm)
	{
		os << "[��ȣ] " << pm->number << "\t[�̸�] " << pm->name.c_str() << "\t[��ȭ��ȣ] " << pm->phone.c_str()
			<< "\t[����] " << pm->age << "\t[����] " << pm->gender;
		return os;
	}

};