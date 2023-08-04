//소스1.cpp
//연결리스트를 이용한 스택 사용

#include <iostream>
using namespace std;
#include "wbtlist.h"


//---------------------- CPP언어 클래스문법(캡슐화 + template) -------------------------
//원본 변경을 막기 위해 const 를 사용한다.
void exam1_print(WbTList<int*> & pstack)
{
	printf("[%2d] ", pstack.getSize() );

	WbTList<int*>::node *begin = pstack.getHead();
	while (begin != NULL )
	{
		int *value = begin->data;
		cout << *value << "\t";
		begin = begin->next;			//연결리스트는 논리적 선형구조... begin++;
	}
	cout << endl;
}

void exam1()
{
	WbTList<int*> stack;		//객체 생성-> 생성자 호출(초기화)
	exam1_print(stack);			//값전달이 필요할 경우  참조자 전달형태로 많이 사용 함

	//저장 5개
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int공간 만들고 전달값으로 초기화
		stack.rearinsert(value);
		exam1_print(stack);
	}

	//삭제 2개
	for (int i = 0; i < 2; i++)
	{
		stack.reardelete();
		exam1_print(stack);
	}

	stack.rearinsert(new int(6));
	exam1_print(stack);

	WbTList<int*>::node * cur = stack.getTail();

	cout << "상단 데이터 : " << *cur->data << endl;
}
//----------------------------------------------------------------------------


#include "WbListStack.h"
//---------------------- CPP언어 클래스문법(캡슐화 + template) -------------------------
//원본 변경을 막기 위해 const 를 사용한다.
void exam2_print(WbListStack<int*> & pstack)
{
	//cout.width(2);
	printf("[%2d] ", pstack.gettop());
	for (int i = 0; i <pstack.gettop(); i++)
	{
		int *value = (int*)pstack[i];
		cout << *value << "\t";
	}
	cout << endl;
}

void exam2()
{
	WbListStack<int*> stack;		//객체 생성-> 생성자 호출(초기화)
	exam2_print(stack);			//값전달이 필요할 경우  참조자 전달형태로 많이 사용 함

	//저장 5개
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int공간 만들고 전달값으로 초기화
		stack.push(value);
		exam2_print(stack);
	}

	//삭제 2개
	for (int i = 0; i < 2; i++)
	{
		stack.pop();
		exam2_print(stack);
	}

	stack.push(new int(6));
	exam2_print(stack);

	int* value = stack.peek();
	cout << "상단 데이터 : " << *value << endl;
}
//----------------------------------------------------------------------------



int main()
{
	exam2();

	return 0;
}