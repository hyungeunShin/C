//sample.cpp
#include <iostream>
using namespace std;
#include "Sample.h"
#include "mystack2.h"		//template 형태 stack

Sample::Sample()
{
}

Sample::~Sample()
{
}

//스택을 이용한 문자열 뒤집기
void Sample::reversestring(char* str, const char* src)
{
	//1. 스택 생성
	mystack2<char> stack;

	//2. 반복문[ *src != ‘\0’]
	//2.1 스택에 해당 문자를 저장!
	//2.2 src++;
	for( ; *src != '\0';  src++)
	{
		stack.push(*src);
	}

	//3. 반복문( 스택이 비어있지 않은경우)
	//3.1 스택에서 문자 하나를 반환받아 str 위치에 저장
	//3.2 str++;
	while (stack.empty() == false)
	{
		char value = stack.pop();
		*str = value;
		str++;
	}
	*str = '\0';
}

//스택을 이용한 10진수의 2진수 표현 출력
void Sample::dectobinary(int data)
{
	//1. 스택 생성
	mystack2<int> stack;	
	while (data >  2)
	{
		stack.push(data % 2);
		data = data / 2;
	}
	stack.push(data);
	//------------------------------------------

	while (stack.empty() != true)
	{
		int value = stack.pop();
		cout << value << " ";
	}
	cout << endl;
}

//중위표기법 -> 후위 표기법으로 출력
void Sample::postfix(const char* src)  // "(A+(B*C))"
{
	//1. 스택 생성
	mystack2<char> stack;

	for (; *src != '\0'; src++)
	{
		//		1) ‘(‘ 무시	
		if (*src >= 'A' && *src <= 'Z')										//피연산자 -> 출력
			cout << *src;
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')	//연산자 -> push
			stack.push(*src);
		
		else if (*src == ')')												//')’ pop->결과를 출력
		{
			char ch = stack.pop();
			cout << ch;
		}
	}
	cout << endl;
}

//중위표기법 -> 후위 표기법으로 변환해서 반환
//공백 처리 기능 추가
//입력 예) ( 3 +  ( 4 * 5 ))
void Sample::postfix1(/*[out]*/char* str, /*[in]*/const char* src)
{
	//1. 스택 생성
	mystack2<char> stack;

	for (; *src != '\0'; src++)
	{
		//		1) ‘(‘ 무시	
		if (*src >= '0' && *src <= '9')									//피연산자 -> 출력
		{
			*str = *src;   //출력 -> 저장
			str++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')	//연산자 -> push
			stack.push(*src);

		else if (*src == ')')												//')’ pop->결과를 출력
		{
			char ch = stack.pop();
			*str =  ch;		//출력 -> 저장
			str++;
		}
	}
	cout << endl;
}

//중위 표기법 -> 후위 표기법으로 변환해서 반환
//10의 자리 이상도 처리가능
//입력 예) (23+(4*235))
void Sample::postfix2(/*[out]*/char* str, /*[in]*/const char* src)
{
	//1. 스택 생성
	mystack2<char> stack;

	while(*src != '\0')
	{
		//		1) ‘(‘ 무시	
		if (*src >= '0' && *src <= '9')									//피연산자 -> 출력
		{
			//피연사를 만난 후 반복해서 피연산가나 나오면 출력
			do
			{
				*str = *src;   //출력 -> 저장
				src++;
				str++;
			} while (*src >= '0' && *src <= '9');
			*str = ' ';
			*str++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*'){	//연산자 -> push
			stack.push(*src);
			src++;
		}
		else if (*src == ')')												//')’ pop->결과를 출력
		{
			char ch = stack.pop();
			*str = ch;		//출력 -> 저장
			str++;
			*str = ' ';		//공백처리
			*src++;
		}
		else
			src++;
	}
	cout << endl;
}

//후위 표기법 연산
int Sample::my_cal(const char* src) //1 2 3 * 4 3 - - 3 + +
{
	//1. 스택 생성
	mystack2<int> stack;
	int temp;
	while (*src != '\0')
	{		
		if (*src >= '0' && *src <= '9')		//1) 피연자라면->push
		{
			temp = *src - '0';		//'0' - '0' -> 0,    '1' - '0'  -> 1
			stack.push(temp);
			src++;
		}
		//2) 연산자라면  a) pop() 연산자의 오른쪽	b) pop() 연산자의 왼쪽 c) 연산결과를 push
		else if (*src == '+' || *src == '-' || *src == '*' || *src == '/')
		{
			int num2 = stack.pop();  
			int num1 = stack.pop();
			int value;
			switch (*src)
			{
			case '+':  value = num1 + num2; break;
			case '-':  value = num1 - num2; break;
			case '*':  value = num1 * num2; break;
			case '/':  value = num1 / num2; break;
			}
			stack.push(value);
			src++;
		}
		else
			src++;
	}	
	return stack.pop();  //반복문 종료 후 pop() : //pop을 result에 저장
}