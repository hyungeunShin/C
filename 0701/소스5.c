//소스5.c
//구조체 변수를 인자로 전달!!!!!!
#include <stdio.h>

struct student
{
	char name[20];
	char subject[20];
	int attend;
	int exam1;
	int exam2;
	int report;
	int total;
	char result;
};

void input_stu(struct student *pstu)
{
	int num;
	printf("출석(20점 만점) : ");
	scanf_s("%d", &num);
	(*pstu).attend = num;

	printf("필기(20점 만점) : ");
	scanf_s("%d", &((*pstu).exam1));  //<--- 

	printf("실기(40점 만점) : ");
	scanf_s("%d", &(*pstu).exam2);

	printf("과제(20점 만점) : ");
	scanf_s("%d", &(*pstu).report);
}

void cal_stu(struct student *pstu)
{
	(*pstu).total = (*pstu).attend + (*pstu).exam1 + (*pstu).exam2 + (*pstu).report;

	if ((*pstu).total >= 60)
		(*pstu).result = 'P';
	else
		(*pstu).result = 'F';
}

void print_stu(const struct student *pstu)
{
	printf("학생 정보 출력\n");
	printf("이름 : %s\n", (*pstu).name);
	printf("과목명 : %s\n", (*pstu).subject);
	printf("출석점수 : %d점\n", (*pstu).attend);
	printf("필기점수 : %d점\n", (*pstu).exam1);
	printf("실기점수 : %d점\n", (*pstu).exam2);
	printf("과제점수 : %d점\n", (*pstu).report);
	printf("합계 : %d점\n", (*pstu).total);
	printf("결과 : %c\n", (*pstu).result);
}

int main()
{
	struct student stu1 = { "홍길동", "C언어" };
	struct student stu2 = { "이길동", "C언어" };

	//사용자 입력을 통해서 성적을 저장
	input_stu(&stu1);	
	input_stu(&stu2); 

	//성적 산출 ( 합, P, F )
	cal_stu(&stu1);
	cal_stu(&stu2);

	printf("\n\n");
	print_stu(&stu1); //구조체는 주소 전달을 활용!(값전달보다 메모리 효율성)
	printf("\n\n");
	print_stu(&stu2);
		
	return 0;
}
