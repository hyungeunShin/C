//소스4.c
/*
학생의 C언어 과목 성적 관리 프로그램
학생[이름, 과목명, 출석점수, 필기점수, 실기점수, 과제점수, 합산점수, 'P' or 'F']
*/
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

int main()
{
	struct student stu1 = { "홍길동", "C언어"  };

	//사용자 입력을 통해서 성적을 저장
	int num;
	printf("출석(20점 만점) : ");
	scanf_s("%d", &num); 
	stu1.attend = num; 

	printf("필기(20점 만점) : ");
	scanf_s("%d", &stu1.exam1);  //<--- 

	printf("실기(40점 만점) : ");
	scanf_s("%d", &stu1.exam2);

	printf("과제(20점 만점) : ");
	scanf_s("%d", &stu1.report);

	//성적 산출 ( 합, P, F )
	stu1.total = stu1.attend + stu1.exam1 + stu1.exam2 + stu1.report;

	if ( stu1.total >= 60)
		stu1.result = 'P';
	else
		stu1.result = 'F';

	printf("학생 정보 출력\n");
	printf("이름 : %s\n", stu1.name);
	printf("과목명 : %s\n", stu1.subject);
	printf("출석점수 : %d점\n", stu1.attend);
	printf("필기점수 : %d점\n", stu1.exam1);
	printf("실기점수 : %d점\n", stu1.exam2);
	printf("과제점수 : %d점\n", stu1.report);
	printf("합계 : %d점\n", stu1.total);
	printf("결과 : %c\n", stu1.result);

	return 0;
}
