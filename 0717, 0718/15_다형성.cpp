//15_다형성
/*
강의자가 강의 -> 다양한 수강생들이 수업을 듣고있다()-수업을 듣는모습들은 다양하다.
 : 객체들은 동일한 메시지에 서로 다른 반응을 한다.
 : 객체의 맴버함수호출 ---> 맴버함수의 호출결과물
*/
/*
1. 상속
2. 오버라이드
3. 업캐스팅(up casting)
4. 가상맴버함수
*/
//공통부분을 갖는 새로운 객체를 정의(Animal)
//강아지(Dog) : Sound()
//고양이(Cat) : Sound()
#include <iostream>
using namespace std;


//step1) 상속구조(부모:자식들의 공통부분), 
//       오버라이드(부모로부터 맴버함수를 물려받았는데 -> 수정:재정의)
/*
class Animal
{
public:
	void Sound() { cout << "........" << endl; }  //?
};

class Dog : public Animal 
{
public:
	void Sound() { cout << "멍멍!!!" << endl; }  //?
};

class Cat : public Animal
{
public:
//	void Sound() { cout << "야옹야옹!!!" << endl; }  //?
};

int main()
{
	//dog는 Dog타입이다. 따라서 Sound를 Dog클래스에서
	Dog dog;			dog.Sound();	
	//cat은 Cat타입이다. 따라서 Sound를 Cat클래스에서 찾는다.
	//만약 Cat클래스에 Sound가 없다면 부모클래스에서 찾는다.
	Cat cat;			cat.Sound();
	return 0;
}
*/


//step2) 업캐스팅(상속관계)
//       자식의 주소를 부모의 포인터 변수에 대입이 가능하다.
//       부모* = &자식;
//       강아지2마리, 고양이 2마리를 생성!
/*
class Animal
{
public:
	void Sound() { cout << "........" << endl; }  //?
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
	//만약 Animal의 자식들이 계속 추가된다면...??
	//계속 배열 변수가 추가될 것이다.
	Dog* d1[2];	//강아지 객체의 주소를 담을 수 있는 배열 선언
	Cat* c1[2]; //고양이 객체의 주소를 담을 수 있는 배열 선언
	d1[0] = new Dog;
	d1[1] = new Dog;
	c1[0] = new Cat;
	c1[1] = new Cat; 

	//업캐스팅: 자식 객체들을 하나의 배열에 관리할 수 있다.
	//Animal* *ani = new Animal*[4];//Animal의 주소를 저장할 수 있는 배열을 선언
									//Animal뿐만 아니라 Animal의 자식객체의 주소도 저장 가능
	Animal* ani[4];
	ani[0] = new Dog;
	ani[1] = new Cat;
	ani[2] = new Cat;
	ani[3] = new Dog;

//	ani[0]->Sound();		//Animal*를 저장하는 배열->Sound를 Animal에서 찾는다.
	for (int i = 0; i < 4; i++)
		ani[i]->Sound();

	return 0;
}
*/

//step3) 가상맴버함수(상속관계)
//       업캐스팅을 통해서 다른 동물들을 Animal 타입 배열에 저장해 놓았다.
//       - Sound()를 호출했더니 Animal 의 Sound가 호출되었다.
//       ->가상맴버함수는 부모의 맴버함수가 아니라 재정의된 자식의 맴버함수를
//         호출할 수 있는 문법!
class Animal
{
public:
	virtual void Sound() { cout << "........" << endl; }  //가상맴버함수<-----------
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
	Animal* ani[4];
	ani[0] = new Dog;
	ani[1] = new Cat;
	ani[2] = new Cat;
	ani[3] = new Dog;

	for (int i = 0; i < 4; i++)
		ani[i]->Sound();  //ani는 Animal 타입이기 때문에 Animal클래스에 정의된Sound
						  //메서드를 찾아 호출한다.
						  //Sound가 가상맴버함수이다.
						  //자식클래스가 재정의했으면 자식의 재정의함수를 호출!
						  //자식클래스가 재정의안했으면 부모의 함수를 호출!
	return 0;
}