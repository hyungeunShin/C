//03_�⺻�����

#include <iostream>
using std::cout;		//cout : ��°�ü(console out, printf()) ���α׷� -> �����
using std::endl;
using std::cin;			//cin  : �Է°�ü( console in, scanf()) Ű���� -> ���α׷�

int main()
{
	char name[20];
	int age;
	char gender;
	float weight;

	cout << "�̸� : ";				cin >> name;	//scanf_s("%s", name, sizeof(name));
	cout << "���� : ";				cin >> age;		//scanf_s("%d", &age);
	cout << "����(m or f) : ";		cin >> gender;	//scanf_s("%c", &gender, sizeof(gender));
	cout << "������ : ";			cin >> weight;	//scanf_s("%f", &weight);

	cout << "�����\n" << endl;
	cout << "�̸� : " << name << endl;		//printf("�̸� : %s\n", name);
	cout << "���� : " << age << endl;		//printf("���� : %d\n", age);
	cout << "���� : " << gender << endl;	//printf("���� : %c\n", gender);
	cout << "������ : " << weight << endl;	//printf("������ : %f\n", weight);

	return 0;
}