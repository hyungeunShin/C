//sample.cpp
#include <iostream>
using namespace std;
#include "Sample.h"
#include "mystack2.h"		//template ���� stack

Sample::Sample()
{
}

Sample::~Sample()
{
}

//������ �̿��� ���ڿ� ������
void Sample::reversestring(char* str, const char* src)
{
	//1. ���� ����
	mystack2<char> stack;

	//2. �ݺ���[ *src != ��\0��]
	//2.1 ���ÿ� �ش� ���ڸ� ����!
	//2.2 src++;
	for( ; *src != '\0';  src++)
	{
		stack.push(*src);
	}

	//3. �ݺ���( ������ ������� �������)
	//3.1 ���ÿ��� ���� �ϳ��� ��ȯ�޾� str ��ġ�� ����
	//3.2 str++;
	while (stack.empty() == false)
	{
		char value = stack.pop();
		*str = value;
		str++;
	}
	*str = '\0';
}

//������ �̿��� 10������ 2���� ǥ�� ���
void Sample::dectobinary(int data)
{
	//1. ���� ����
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

//����ǥ��� -> ���� ǥ������� ���
void Sample::postfix(const char* src)  // "(A+(B*C))"
{
	//1. ���� ����
	mystack2<char> stack;

	for (; *src != '\0'; src++)
	{
		//		1) ��(�� ����	
		if (*src >= 'A' && *src <= 'Z')										//�ǿ����� -> ���
			cout << *src;
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')	//������ -> push
			stack.push(*src);
		
		else if (*src == ')')												//')�� pop->����� ���
		{
			char ch = stack.pop();
			cout << ch;
		}
	}
	cout << endl;
}

//����ǥ��� -> ���� ǥ������� ��ȯ�ؼ� ��ȯ
//���� ó�� ��� �߰�
//�Է� ��) ( 3 +  ( 4 * 5 ))
void Sample::postfix1(/*[out]*/char* str, /*[in]*/const char* src)
{
	//1. ���� ����
	mystack2<char> stack;

	for (; *src != '\0'; src++)
	{
		//		1) ��(�� ����	
		if (*src >= '0' && *src <= '9')									//�ǿ����� -> ���
		{
			*str = *src;   //��� -> ����
			str++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')	//������ -> push
			stack.push(*src);

		else if (*src == ')')												//')�� pop->����� ���
		{
			char ch = stack.pop();
			*str =  ch;		//��� -> ����
			str++;
		}
	}
	cout << endl;
}

//���� ǥ��� -> ���� ǥ������� ��ȯ�ؼ� ��ȯ
//10�� �ڸ� �̻� ó������
//�Է� ��) (23+(4*235))
void Sample::postfix2(/*[out]*/char* str, /*[in]*/const char* src)
{
	//1. ���� ����
	mystack2<char> stack;

	while(*src != '\0')
	{
		//		1) ��(�� ����	
		if (*src >= '0' && *src <= '9')									//�ǿ����� -> ���
		{
			//�ǿ��縦 ���� �� �ݺ��ؼ� �ǿ��갡�� ������ ���
			do
			{
				*str = *src;   //��� -> ����
				src++;
				str++;
			} while (*src >= '0' && *src <= '9');
			*str = ' ';
			*str++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*'){	//������ -> push
			stack.push(*src);
			src++;
		}
		else if (*src == ')')												//')�� pop->����� ���
		{
			char ch = stack.pop();
			*str = ch;		//��� -> ����
			str++;
			*str = ' ';		//����ó��
			*src++;
		}
		else
			src++;
	}
	cout << endl;
}

//���� ǥ��� ����
int Sample::my_cal(const char* src) //1 2 3 * 4 3 - - 3 + +
{
	//1. ���� ����
	mystack2<int> stack;
	int temp;
	while (*src != '\0')
	{		
		if (*src >= '0' && *src <= '9')		//1) �ǿ��ڶ��->push
		{
			temp = *src - '0';		//'0' - '0' -> 0,    '1' - '0'  -> 1
			stack.push(temp);
			src++;
		}
		//2) �����ڶ��  a) pop() �������� ������	b) pop() �������� ���� c) �������� push
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
	return stack.pop();  //�ݺ��� ���� �� pop() : //pop�� result�� ����
}