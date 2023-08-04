//�ҽ�1.cpp
//���Ḯ��Ʈ�� �̿��� ���� ���

#include <iostream>
using namespace std;
#include "wbtlist.h"


//---------------------- CPP��� Ŭ��������(ĸ��ȭ + template) -------------------------
//���� ������ ���� ���� const �� ����Ѵ�.
void exam1_print(WbTList<int*> & pstack)
{
	printf("[%2d] ", pstack.getSize() );

	WbTList<int*>::node *begin = pstack.getHead();
	while (begin != NULL )
	{
		int *value = begin->data;
		cout << *value << "\t";
		begin = begin->next;			//���Ḯ��Ʈ�� ���� ��������... begin++;
	}
	cout << endl;
}

void exam1()
{
	WbTList<int*> stack;		//��ü ����-> ������ ȣ��(�ʱ�ȭ)
	exam1_print(stack);			//�������� �ʿ��� ���  ������ �������·� ���� ��� ��

	//���� 5��
	for (int i = 0; i < 5; i++)
	{
		int *value = new int(i + 1);  //new int(i+1) :  int���� ����� ���ް����� �ʱ�ȭ
		stack.rearinsert(value);
		exam1_print(stack);
	}

	//���� 2��
	for (int i = 0; i < 2; i++)
	{
		stack.reardelete();
		exam1_print(stack);
	}

	stack.rearinsert(new int(6));
	exam1_print(stack);

	WbTList<int*>::node * cur = stack.getTail();

	cout << "��� ������ : " << *cur->data << endl;
}
//----------------------------------------------------------------------------


#include "WbListStack.h"
//---------------------- CPP��� Ŭ��������(ĸ��ȭ + template) -------------------------
//���� ������ ���� ���� const �� ����Ѵ�.
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
	WbListStack<int*> stack;		//��ü ����-> ������ ȣ��(�ʱ�ȭ)
	exam2_print(stack);			//�������� �ʿ��� ���  ������ �������·� ���� ��� ��

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

	int* value = stack.peek();
	cout << "��� ������ : " << *value << endl;
}
//----------------------------------------------------------------------------



int main()
{
	exam2();

	return 0;
}