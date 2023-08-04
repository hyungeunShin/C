//소스8.c
/*
회원 N명을 관리하는 프로그램
회원(회원번호, 이름, 전화번호, 나이, 성별)
- 저장(insert) / 검색(select) / 삭제(delete) / 수정(update) - 
*/

#include <stdio.h>
#include <string.h> 

typedef struct member member;		//typedef 존재하는타입 새로운타입식별자;	 member
struct member						//구조체 타입 : struct member
{
	int number;		//회원 번호
	char name[20];  //이름	
	char phone[20]; //전화번호
	int age;		//나이
	char gender;	//성별
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
		{111, "이길동", "010-1111-1111", 10, 'm'},
		{222, "고길순", "010-2222-2222", 20, 'f'},
	};

//	insert(members);
//	select(members);
//	printall(members);

//	delete1(members);  //검색 흐름 유사.
//	printall(members);

	update(members);	//검색 흐름 유사
	printall(members);

	return 0;
}


void insert(member members[])
{
	printf("[회원 정보 저장]\n\n");

	int number, age, idx;
	char name[20], phone[20];
	char gender;

	printf("저장할 인덱스(0~%d) : ", DATA_MAX - 1);		scanf_s("%d", &idx);
	printf("회원번호 : ");			scanf_s("%d", &number);
	char dummy = getchar();		//<------------------------------------------
	printf("이름 : ");				gets_s(name, sizeof(name));
	printf("전화번호 : ");			gets_s(phone, sizeof(phone));
	printf("나이 : ");				scanf_s("%d", &age);
	dummy = getchar();		//<------------------------------------------
	printf("성별 : ");				scanf_s("%c", &gender, sizeof(gender));

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
	printf("[회원 정보 검색]\n\n");

	char name[20];	
	printf("검색할 이름 : ");				gets_s(name, sizeof(name));

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
	printf("해당 이름은 존재하지 않습니다.\n");
}

void delete1(member members[])
{
	printf("[회원 정보 삭제]\n\n");

	char name[20];
	printf("삭제할 이름 : ");				gets_s(name, sizeof(name));

	delete_member(members, name);
}

void delete_member(member members[], const char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(members[i].name, name) == 0)         //if (members[i].name == name)
		{
			//삭제
			members[i].age =0;
			members[i].gender = ' '; 
			strcpy_s(members[i].name, sizeof(members[i].name), ""); 
			strcpy_s(members[i].phone, sizeof(members[i].phone), "");
			members[i].number = 0;

			return;
		}
	}
	printf("해당 이름은 존재하지 않습니다.\n");
}

void update(member members[])
{
	printf("[회원 정보 수정]\n\n");

	char name[20];
	printf("수정할 대상 이름 : ");				gets_s(name, sizeof(name));

	update_member(members, name);
}

void update_member(member members[], const char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(members[i].name, name) == 0)         //if (members[i].name == name)
		{
			//나이, 전화번호
			printf("수정할 나이 : ");
			scanf_s("%d", &members[i].age);
			char dummy = getchar();			//<---------------------------------
			printf("전화번호 : ");
			gets_s(members[i].phone, sizeof(members[i].phone));
			return;
		}
	}
	printf("해당 이름은 존재하지 않습니다.\n");
}

void print_member(member member)
{
	printf("회원번호 : %d\n", member.number);		
	printf("이    름 : %s\n", member.name);				
	printf("전화번호 : %s\n", member.phone);			
	printf("나    이 : %d\n", member.age);			
	printf("성    별 : %c\n", member.gender);
}

void printall(member members[])
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		print_member(members[i]);
		printf("----------------------------------------------\n");
	}
}