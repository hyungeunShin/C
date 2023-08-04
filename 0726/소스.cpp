//소스.cpp
#include <iostream>
using namespace std;
#include "myarr.h"
#include "mystack1.h"
#include "mystack2.h"

//----------------------- C기반 전역함수 --------------------------------
void exam1_print(const mystack *pstack)
{
	printf("[%d] ", pstack->top + 1);
	for (int i = 0; i <= pstack->top; i++)
	{
		int *value = (int*)pstack->base[i];
		printf("%d\t", *value);
	}
	printf("\n");
}

void exam1()
{
	mystack stack;
	mystack_init(&stack, 10);
	exam1_print(&stack);

	//저장 5개
	for (int i = 0; i < 5; i++)
	{
		int *value = (int*)malloc(sizeof(int));
		*value = i + 1;
		mystack_push(&stack, value);
		exam1_print(&stack);
	}

	//삭제 2개
	for (int i = 0; i < 2; i++)
	{
		mystack_pop(&stack);
		exam1_print(&stack);
	}

	int *value1 = (int*)malloc(sizeof(int));
	*value1 = 6;
	mystack_push(&stack, value1);
	exam1_print(&stack);

	mystack_exit(&stack);

}


//---------------------- CPP언어 클래스문법(캡슐화) -------------------------
//원본 변경을 막기 위해 const 를 사용한다.
void exam2_print(const mystack1 & pstack)
{
	//cout.width(2);
	printf("[%2d] ", pstack.gettop() + 1);
	for (int i = 0; i <= pstack.gettop(); i++)
	{
		int *value = (int*)pstack[i];
		cout << *value << "\t";
	}
	cout << endl;
}

void exam2()
{
	mystack1 stack;			//객체 생성-> 생성자 호출(초기화)
	exam2_print(stack);		//값전달이 필요할 경우  참조자 전달형태로 많이 사용 함


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

	int* value = (int*)stack.peek();
	cout << "상단 데이터 : " << *value << endl; 
}

//---------------------- CPP언어 클래스문법(캡슐화 + template) -------------------------
//원본 변경을 막기 위해 const 를 사용한다.
void exam3_print(const mystack2<int*> & pstack)
{
	//cout.width(2);
	printf("[%2d] ", pstack.gettop() + 1);
	for (int i = 0; i <= pstack.gettop(); i++)
	{
		int *value = (int*)pstack[i];
		cout << *value << "\t";
	}
	cout << endl;
}

void exam3()
{
	mystack2<int*> stack;		//객체 생성-> 생성자 호출(초기화)
	exam3_print(stack);			//값전달이 필요할 경우  참조자 전달형태로 많이 사용 함
	
	//저장 5개
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int공간 만들고 전달값으로 초기화
		stack.push(value);
		exam3_print(stack);
	}

	//삭제 2개
	for (int i = 0; i < 2; i++)
	{
		stack.pop();
		exam3_print(stack);
	}

	stack.push(new int(6));
	exam3_print(stack);

	int* value = (int*)stack.peek();
	cout << "상단 데이터 : " << *value << endl;
}

//----------------------------------------------------------------------------
#include "Sample.h"
//문자열 뒤집기
void exam4()
{
	char str[] = "abcdefg";
	char str1[50] = "";
	Sample::reversestring(str1, str);
	cout << "원  본 : " << str << endl; 
	cout << "복사본 : " << str1 << endl;
}

//10진수를 2진수로
void exam5()
{
	Sample::dectobinary(26);
	Sample::dectobinary(15);
}

//중위표기법 -> 후위 표기법
void exam6()
{
	Sample::postfix("(A+(B*C))");

	char str[256] = "";
	Sample::postfix1(str, "( 3 +  ( 4 * 5 ))");
	cout << "중위 표기법 : ( 3 +  ( 4 * 5 ))" << " -> ";
	cout << "후위 표기법 : " << str << endl;

	char str1[256] = "";
	Sample::postfix2(str1, "(23+(4*235))");
	cout << "중위 표기법 : (23 + (4 * 235))" << " -> ";
	cout << "후위 표기법 : " << str1 << endl;

	//후위 표기법 연산
	int result = Sample::my_cal("1 2 3 * 4 3 - - 3 + +");  // 
	printf("결과값 : %d\n", result);  // 9

	//중위 표기법 연산
	char str2[256] = "";
	Sample::postfix1(str2, "( 3 +  ( 4 * 5 ))");	//23
	int result1 = Sample::my_cal(str2);  // 
	printf("결과값 : %d\n", result1);	// 23
}

//문자열형태의 숫자를 int로 변환
void exam7()
{
	char str[20] = "32"; 
	char *p = str;
	int i = 0;
	if (*p >= '0' && *p <= '9')   // 숫자일때(피연산자)
	{		
		do
		{
			i = i * 10 + *p - '0';
			p++;
		} while (*p >= '0' && *p <= '9');
	}
	cout << i << endl; 
}

int main()
{
	exam7();

	return 0;
}