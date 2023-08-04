//17_�ٿ�ĳ����
#include <iostream>
using namespace std;

//�ٿ�ĳ������ ������
/*
class Animal
{
public:
virtual void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal
{
public:
void Sound() { cout << "�۸�!!!" << endl; }  //?
};

class Cat : public Animal
{
public:
void Sound() { cout << "�߿˾߿�!!!" << endl; }  //?
};

int main()
{
//��ĳ����1
Animal *ani = new Dog;
ani->Sound();

//�ٿ�ĳ����(�ùٸ� ĳ������ �ƴϴ�)
//��������ȯ
Dog *pdog = (Dog*)ani;	//�ڽ�* = &�θ�
pdog->Sound();

//������ �����Ѵ�. ���� ������ �߻���ų ���� �ִ�.
Cat *pcat = (Cat*)ani;	//?????????????????
pcat->Sound();

return 0;
}
*/


//�ٿ�ĳ������ �ʿ��� ���
class Animal
{
public:
	virtual void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal
{
public:
	void Sound() { cout << "�۸�!!!" << endl; }  //?
	void Run()   { cout << "�������� �޸���." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "�߿˾߿�!!!" << endl; }  //?
};

int main()
{
	Dog dog;
	dog.Run();
	dog.Sound();

	Animal *p = new Dog;
	p->Sound();
	//�ڽĿ��� �߰��� �޼��带 ȣ���Ϸ��� �ݵ�� �ٿ�ĳ������ �ʿ��ϴ�.
	//�� �� �������� ������� �ٿ�ĳ������ �Ҽ� ������?
	//((Dog*)p)->Run();
	//p�� ���� �ִ� �ּҰ� Dog*�� �ּҳ�?(p�� Dog��ü�� ���� �ִ°�?)
	Dog *pdog = dynamic_cast<Dog*>(p);
	if (pdog != NULL)
	{
		pdog->Run();
	}

	Cat *pcat = dynamic_cast<Cat*>(p);
	if (pcat == NULL)
	{
		cout << "����̰� �ƴϴ�" << endl;
	}


	return 0;
}
