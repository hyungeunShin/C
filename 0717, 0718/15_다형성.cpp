//15_������
/*
�����ڰ� ���� -> �پ��� ���������� ������ ����ִ�()-������ ��¸������ �پ��ϴ�.
 : ��ü���� ������ �޽����� ���� �ٸ� ������ �Ѵ�.
 : ��ü�� �ɹ��Լ�ȣ�� ---> �ɹ��Լ��� ȣ������
*/
/*
1. ���
2. �������̵�
3. ��ĳ����(up casting)
4. ����ɹ��Լ�
*/
//����κ��� ���� ���ο� ��ü�� ����(Animal)
//������(Dog) : Sound()
//�����(Cat) : Sound()
#include <iostream>
using namespace std;


//step1) ��ӱ���(�θ�:�ڽĵ��� ����κ�), 
//       �������̵�(�θ�κ��� �ɹ��Լ��� �����޾Ҵµ� -> ����:������)
/*
class Animal
{
public:
	void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal 
{
public:
	void Sound() { cout << "�۸�!!!" << endl; }  //?
};

class Cat : public Animal
{
public:
//	void Sound() { cout << "�߿˾߿�!!!" << endl; }  //?
};

int main()
{
	//dog�� DogŸ���̴�. ���� Sound�� DogŬ��������
	Dog dog;			dog.Sound();	
	//cat�� CatŸ���̴�. ���� Sound�� CatŬ�������� ã�´�.
	//���� CatŬ������ Sound�� ���ٸ� �θ�Ŭ�������� ã�´�.
	Cat cat;			cat.Sound();
	return 0;
}
*/


//step2) ��ĳ����(��Ӱ���)
//       �ڽ��� �ּҸ� �θ��� ������ ������ ������ �����ϴ�.
//       �θ�* = &�ڽ�;
//       ������2����, ����� 2������ ����!
/*
class Animal
{
public:
	void Sound() { cout << "........" << endl; }  //?
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
	//���� Animal�� �ڽĵ��� ��� �߰��ȴٸ�...??
	//��� �迭 ������ �߰��� ���̴�.
	Dog* d1[2];	//������ ��ü�� �ּҸ� ���� �� �ִ� �迭 ����
	Cat* c1[2]; //����� ��ü�� �ּҸ� ���� �� �ִ� �迭 ����
	d1[0] = new Dog;
	d1[1] = new Dog;
	c1[0] = new Cat;
	c1[1] = new Cat; 

	//��ĳ����: �ڽ� ��ü���� �ϳ��� �迭�� ������ �� �ִ�.
	//Animal* *ani = new Animal*[4];//Animal�� �ּҸ� ������ �� �ִ� �迭�� ����
									//Animal�Ӹ� �ƴ϶� Animal�� �ڽİ�ü�� �ּҵ� ���� ����
	Animal* ani[4];
	ani[0] = new Dog;
	ani[1] = new Cat;
	ani[2] = new Cat;
	ani[3] = new Dog;

//	ani[0]->Sound();		//Animal*�� �����ϴ� �迭->Sound�� Animal���� ã�´�.
	for (int i = 0; i < 4; i++)
		ani[i]->Sound();

	return 0;
}
*/

//step3) ����ɹ��Լ�(��Ӱ���)
//       ��ĳ������ ���ؼ� �ٸ� �������� Animal Ÿ�� �迭�� ������ ���Ҵ�.
//       - Sound()�� ȣ���ߴ��� Animal �� Sound�� ȣ��Ǿ���.
//       ->����ɹ��Լ��� �θ��� �ɹ��Լ��� �ƴ϶� �����ǵ� �ڽ��� �ɹ��Լ���
//         ȣ���� �� �ִ� ����!
class Animal
{
public:
	virtual void Sound() { cout << "........" << endl; }  //����ɹ��Լ�<-----------
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
	Animal* ani[4];
	ani[0] = new Dog;
	ani[1] = new Cat;
	ani[2] = new Cat;
	ani[3] = new Dog;

	for (int i = 0; i < 4; i++)
		ani[i]->Sound();  //ani�� Animal Ÿ���̱� ������ AnimalŬ������ ���ǵ�Sound
						  //�޼��带 ã�� ȣ���Ѵ�.
						  //Sound�� ����ɹ��Լ��̴�.
						  //�ڽ�Ŭ������ ������������ �ڽ��� �������Լ��� ȣ��!
						  //�ڽ�Ŭ������ �����Ǿ������� �θ��� �Լ��� ȣ��!
	return 0;
}