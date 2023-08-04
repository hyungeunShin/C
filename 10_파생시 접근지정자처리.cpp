//10_파생시 접근 지정자 처리

#include <iostream>
using namespace std;

class Parent
{
private:
	void private_foo() {}
protected:
	void protected_foo() {}
public:
	void public_foo()  {}
};

class Child : public Parent
{
	//부모의 privet -> private
	//부모의 protected -> protected
	//부모의 public ->public 으로 상속된다.
};

//부모로 부터 물려받을 때 허용범위를 protected내로
class Child1 : protected Parent		 
{
	//부모의 privet		-> private
	//부모의 protected  -> protected
	//부모의 public		-> protected 으로 상속된다.
};

//부모로 부터 물려받을 때 허용범위를 private내로
class Child2 : private Parent
{
	//부모의 privet		-> private
	//부모의 protected  -> private
	//부모의 public		-> private 으로 상속된다.
};

int main()
{
	//public 상속하게 되면 상속된 3개의 메서드 중 public_foo()만 외부에서 사용가능
	Child c1;
	c1.public_foo();	

	//모두 호출 불가능.
	Child1 c2;

	//모두 호출 불가능
	Child2 c3;

}