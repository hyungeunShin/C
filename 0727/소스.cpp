//�ҽ�.cpp

#include <iostream>
using namespace std;
#include <conio.h>
#include "myqueue1.h"
#include "myqueue2.h"

//�Լ� �߽� �ڵ� ���(myquque1)
void exam1_print(myqueue1* pqueue)
{
	cout << "[" << myqueue_count(pqueue) << "] ";

	for (int i = pqueue->front; i != pqueue->rear; i = (i + 1) % pqueue->max) {
		int* pvalue = (int*)pqueue->base[i];
		cout << *pvalue << " ";
	}
	cout << endl;
}

void exam1()
{
	myqueue1 queue;
	myqueue_init(&queue, 10);

	while (true)
	{
		system("cls");
		exam1_print(&queue);
		cout << "----------------------------------------------------" << endl;
 		cout << "[1] PUT [2] GET [3] PEEK  [4] EXIT" << endl;
		cout << "----------------------------------------------------" << endl;
		char input = _getch();	//#include <conio.h>
		if (input == '1')
		{
			int value;
			cout << "���� �Է� : ";		cin >> value;

			int* pvalue = (int*)malloc(sizeof(int));
			if (pvalue != NULL)
			{
				*pvalue = value;
				myqueue_put(&queue, pvalue);
			}
		}
		else if (input == '2')
		{
			int *pvalue  = (int*)myqueue_get(&queue);
		}
		else if (input == '3')
		{
			int* pvalue = (int*)myqueue_peek(&queue);
			if (pvalue == NULL)
				cout << "�����Ͱ� ����ִ� ���� " << endl;
			else
				cout << *pvalue << endl;

			system("pause");
		}
		else if (input == '4')
		{
			break;
		}
		else
		{
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
		}		
	}

	myqueue_exit(&queue);
}

//Ŭ���� �ڵ� ���(myqueue2)
void exam2_print(myqueue2* pqueue)
{
	cout << "[" << pqueue->count() << "] ";

	for (int i = pqueue->get_front(); 
			i != pqueue->get_rear(); i = (i + 1) % pqueue->get_max()) {
		int* pvalue = (int*)(*pqueue)[i]; //??? 
		cout << *pvalue << " ";
	}
	cout << endl;
}

void exam2()
{
	myqueue2 queue(10);

	while (true)
	{
		system("cls");
		exam2_print(&queue);
		cout << "----------------------------------------------------" << endl;
		cout << "[1] PUT [2] GET [3] PEEK  [4] EXIT" << endl;
		cout << "----------------------------------------------------" << endl;
		char input = _getch();	//#include <conio.h>
		if (input == '1')
		{
			int value;
			cout << "���� �Է� : ";		cin >> value;

			int* pvalue = new int(value);	//<------
			if (pvalue != NULL)
			{
				*pvalue = value;
				queue.put(pvalue);	//<---------
			}
		}
		else if (input == '2')
		{
			int* pvalue = (int*)queue.get();	//<------
		}
		else if (input == '3')
		{
			int* pvalue = (int*)queue.peek();	//<--------------
			if (pvalue == NULL)
				cout << "�����Ͱ� ����ִ� ���� " << endl;
			else
				cout << *pvalue << endl;

			system("pause");
		}
		else if (input == '4')
		{
			break;
		}
		else
		{
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
		}
	}
}

int main()
{
	exam2();

	return 0;
}