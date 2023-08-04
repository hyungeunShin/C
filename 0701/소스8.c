//�ҽ�8.c
/*
ȸ�� N���� �����ϴ� ���α׷�
ȸ��(ȸ����ȣ, �̸�, ��ȭ��ȣ, ����, ����)
- ����(insert) / �˻�(select) / ����(delete) / ����(update) - 
*/

#include <stdio.h>
#include <string.h> 

typedef struct member member;		//typedef �����ϴ�Ÿ�� ���ο�Ÿ�Խĺ���;	 member
struct member						//����ü Ÿ�� : struct member
{
	int number;		//ȸ�� ��ȣ
	char name[20];  //�̸�	
	char phone[20]; //��ȭ��ȣ
	int age;		//����
	char gender;	//����
};

#define DATA_MAX	10

void insert(member members[]);
void insert_member(member members[], int idx, int number, const char* name, const char*phone, int age, char gender);

void select(member members[]);
void select_member(member members[], const char* name);

void delete1(member members[]);
void delete_member(member members[], const char* name);

void update(member members[]);
void update_member(member members[], const char* name);

void print_member(member member);

void printall(member members[]);

int main()
{
	//struct member members[DATA_MAX];
	member members[DATA_MAX] = 
	{
		{111, "�̱浿", "010-1111-1111", 10, 'm'},
		{222, "����", "010-2222-2222", 20, 'f'},
	};

//	insert(members);
//	select(members);
//	printall(members);

//	delete1(members);  //�˻� �帧 ����.
//	printall(members);

	update(members);	//�˻� �帧 ����
	printall(members);

	return 0;
}


void insert(member members[])
{
	printf("[ȸ�� ���� ����]\n\n");

	int number, age, idx;
	char name[20], phone[20];
	char gender;

	printf("������ �ε���(0~%d) : ", DATA_MAX - 1);		scanf_s("%d", &idx);
	printf("ȸ����ȣ : ");			scanf_s("%d", &number);
	char dummy = getchar();		//<------------------------------------------
	printf("�̸� : ");				gets_s(name, sizeof(name));
	printf("��ȭ��ȣ : ");			gets_s(phone, sizeof(phone));
	printf("���� : ");				scanf_s("%d", &age);
	dummy = getchar();		//<------------------------------------------
	printf("���� : ");				scanf_s("%c", &gender, sizeof(gender));

	insert_member(members, idx, number, name, phone, age, gender);
}

void insert_member(member members[], int idx, int number, const char* name, const char*phone,int age, char gender)
{
	members[idx].number = number;
	strcpy_s(members[idx].name, sizeof(members[idx].name), name);	//	members[idx].name = name;
	strcpy_s(members[idx].phone, sizeof(members[idx].phone), phone);//	members[idx].phone = phone;
	members[idx].age = age;
	members[idx].gender = gender; 
}

void select(member members[])
{
	printf("[ȸ�� ���� �˻�]\n\n");

	char name[20];	
	printf("�˻��� �̸� : ");				gets_s(name, sizeof(name));

	select_member(members, name); 
}

void select_member(member members[], const char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if( strcmp(members[i].name, name) ==0 )         //if (members[i].name == name)
		{
			print_member(members[i]);
			return;
		}
	}
	printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
}

void delete1(member members[])
{
	printf("[ȸ�� ���� ����]\n\n");

	char name[20];
	printf("������ �̸� : ");				gets_s(name, sizeof(name));

	delete_member(members, name);
}

void delete_member(member members[], const char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(members[i].name, name) == 0)         //if (members[i].name == name)
		{
			//����
			members[i].age =0;
			members[i].gender = ' '; 
			strcpy_s(members[i].name, sizeof(members[i].name), ""); 
			strcpy_s(members[i].phone, sizeof(members[i].phone), "");
			members[i].number = 0;

			return;
		}
	}
	printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
}

void update(member members[])
{
	printf("[ȸ�� ���� ����]\n\n");

	char name[20];
	printf("������ ��� �̸� : ");				gets_s(name, sizeof(name));

	update_member(members, name);
}

void update_member(member members[], const char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(members[i].name, name) == 0)         //if (members[i].name == name)
		{
			//����, ��ȭ��ȣ
			printf("������ ���� : ");
			scanf_s("%d", &members[i].age);
			char dummy = getchar();			//<---------------------------------
			printf("��ȭ��ȣ : ");
			gets_s(members[i].phone, sizeof(members[i].phone));
			return;
		}
	}
	printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
}

void print_member(member member)
{
	printf("ȸ����ȣ : %d\n", member.number);		
	printf("��    �� : %s\n", member.name);				
	printf("��ȭ��ȣ : %s\n", member.phone);			
	printf("��    �� : %d\n", member.age);			
	printf("��    �� : %c\n", member.gender);
}

void printall(member members[])
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		print_member(members[i]);
		printf("----------------------------------------------\n");
	}
}