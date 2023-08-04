//17_다운캐스팅
#include <iostream>
using namespace std;

//다운캐스팅의 문제점
/*
class Animal
{
public:
virtual void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal
{
public:
void Sound() { cout << "멍멍!!!" << endl; }  //?
};

class Cat : public Animal
{
public:
void Sound() { cout << "야옹야옹!!!" << endl; }  //?
};

int main()
{
//업캐스팅1
Animal *ani = new Dog;
ani->Sound();

//다운캐스팅(올바른 캐스팅이 아니다)
//강제형변환
Dog *pdog = (Dog*)ani;	//자식* = &부모
pdog->Sound();

//무조건 성공한다. 따라서 문제를 발생시킬 수도 있다.
Cat *pcat = (Cat*)ani;	//?????????????????
pcat->Sound();

return 0;
}
*/


//다운캐스팅이 필요한 경우
class Animal
{
public:
	virtual void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal
{
public:
	void Sound() { cout << "멍멍!!!" << endl; }  //?
	void Run()   { cout << "강아지가 달린다." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "야옹야옹!!!" << endl; }  //?
};

int main()
{
	Dog dog;
	dog.Run();
	dog.Sound();

	Animal *p = new Dog;
	p->Sound();
	//자식에서 추가된 메서드를 호출하려면 반드시 다운캐스팅이 필요하다.
	//좀 더 안정적인 방식으로 다운캐스팅을 할수 있을까?
	//((Dog*)p)->Run();
	//p가 갖고 있는 주소가 Dog*의 주소냐?(p가 Dog객체를 갖고 있는가?)
	Dog *pdog = dynamic_cast<Dog*>(p);
	if (pdog != NULL)
	{
		pdog->Run();
	}

	Cat *pcat = dynamic_cast<Cat*>(p);
	if (pcat == NULL)
	{
		cout << "고양이가 아니다" << endl;
	}


	return 0;
}
