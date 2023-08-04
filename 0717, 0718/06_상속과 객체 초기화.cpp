//06_��Ӱ� ��ü �ʱ�ȭ
/*
[����]
��ü �ʱ�ȭ : �ڽ��� �����ڿ��� �ڽ��� ��ü(�ɹ�����) ������ �ʱ�ȭ �Ѵ�.
        ��ӱ��������� �θ��� �ɹ������� �ڽİ�ü�� �����޴´�.
		�������� �ɹ������� �ʱ�ȭ�� ���� �ؾ� �ɰ��ΰ�? (�θ�)

�ڽ��� �θ�κ��� ��������  private�� ������ �� ����.
-> �ذ�1) ���� ������ ���
          get�޼��� & set�޼��� Ȱ��
-> �ذ�2) �ڽĿ��Ա��� ������ ����ϴ� ���� �����ڷ� ���� ó�� : protected
*/
#include <iostream>
using namespace std;

class Person
{
protected:				//��ӱ������� ������ ���� ������(�ڽ� + �ڽ�)
	string name;
	int age;
public:
	Person(string _name, int _age)
	{
		name = _name;
		age = _age;
	}
public:
	void Print() const
	{
		cout << name.c_str() << endl;
		cout << age << endl; 
	}
};

class Student : public Person
{
private:
	string univer;
	string subject;
public:
	Student(string _name, int _age, string _uni, string _sub)
		: Person(_name, _age)			//<--------------------------------------
	{
		univer = _uni;
		subject = _sub;
	}

public:
	void Print1() const
	{
		//�̸�?
		//����?
		//�������� �޼��带 ȣ��!
		//Print();
		cout << name.c_str() << endl;
		cout << age << endl; 
		cout << univer.c_str() << endl;
		cout << subject.c_str() << endl; 
	}
};

int main()
{
	Student stu("ȫ�浿", 20, "��۴�", "��ǻ��");

//	stu.Print();  //�θ�κ��� �������� �޼���
	stu.Print1(); //�ڽ��� �޼���

	return 0;
}