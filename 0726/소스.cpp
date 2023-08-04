//�ҽ�.cpp
#include <iostream>
using namespace std;
#include "myarr.h"
#include "mystack1.h"
#include "mystack2.h"

//----------------------- C��� �����Լ� --------------------------------
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

	//���� 5��
	for (int i = 0; i < 5; i++)
	{
		int *value = (int*)malloc(sizeof(int));
		*value = i + 1;
		mystack_push(&stack, value);
		exam1_print(&stack);
	}

	//���� 2��
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


//---------------------- CPP��� Ŭ��������(ĸ��ȭ) -------------------------
//���� ������ ���� ���� const �� ����Ѵ�.
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
	mystack1 stack;			//��ü ����-> ������ ȣ��(�ʱ�ȭ)
	exam2_print(stack);		//�������� �ʿ��� ���  ������ �������·� ���� ��� ��


	//���� 5��
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int���� ����� ���ް����� �ʱ�ȭ
		stack.push(value);
		exam2_print(stack);
	}

	//���� 2��
	for (int i = 0; i < 2; i++)
	{
		stack.pop();
		exam2_print(stack);
	}

	stack.push(new int(6)); 
	exam2_print(stack);

	int* value = (int*)stack.peek();
	cout << "��� ������ : " << *value << endl; 
}

//---------------------- CPP��� Ŭ��������(ĸ��ȭ + template) -------------------------
//���� ������ ���� ���� const �� ����Ѵ�.
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
	mystack2<int*> stack;		//��ü ����-> ������ ȣ��(�ʱ�ȭ)
	exam3_print(stack);			//�������� �ʿ��� ���  ������ �������·� ���� ��� ��
	
	//���� 5��
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int���� ����� ���ް����� �ʱ�ȭ
		stack.push(value);
		exam3_print(stack);
	}

	//���� 2��
	for (int i = 0; i < 2; i++)
	{
		stack.pop();
		exam3_print(stack);
	}

	stack.push(new int(6));
	exam3_print(stack);

	int* value = (int*)stack.peek();
	cout << "��� ������ : " << *value << endl;
}

//----------------------------------------------------------------------------
#include "Sample.h"
//���ڿ� ������
void exam4()
{
	char str[] = "abcdefg";
	char str1[50] = "";
	Sample::reversestring(str1, str);
	cout << "��  �� : " << str << endl; 
	cout << "���纻 : " << str1 << endl;
}

//10������ 2������
void exam5()
{
	Sample::dectobinary(26);
	Sample::dectobinary(15);
}

//����ǥ��� -> ���� ǥ���
void exam6()
{
	Sample::postfix("(A+(B*C))");

	char str[256] = "";
	Sample::postfix1(str, "( 3 +  ( 4 * 5 ))");
	cout << "���� ǥ��� : ( 3 +  ( 4 * 5 ))" << " -> ";
	cout << "���� ǥ��� : " << str << endl;

	char str1[256] = "";
	Sample::postfix2(str1, "(23+(4*235))");
	cout << "���� ǥ��� : (23 + (4 * 235))" << " -> ";
	cout << "���� ǥ��� : " << str1 << endl;

	//���� ǥ��� ����
	int result = Sample::my_cal("1 2 3 * 4 3 - - 3 + +");  // 
	printf("����� : %d\n", result);  // 9

	//���� ǥ��� ����
	char str2[256] = "";
	Sample::postfix1(str2, "( 3 +  ( 4 * 5 ))");	//23
	int result1 = Sample::my_cal(str2);  // 
	printf("����� : %d\n", result1);	// 23
}

//���ڿ������� ���ڸ� int�� ��ȯ
void exam7()
{
	char str[20] = "32"; 
	char *p = str;
	int i = 0;
	if (*p >= '0' && *p <= '9')   // �����϶�(�ǿ�����)
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