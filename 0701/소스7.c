//소스7.c  ㅣ 소스5.c

/*
계좌가 있고, 
[ struct account ]
- int number;	  //계좌번호
- char name[20];  //고객명	
- int balance;    //잔액
계좌에 입금 출금 잔액 조회하는 기능을 구현하시오.
*/
#include <stdio.h>

struct account
{
	int number;		//계좌번호
	char name[20];  //고객명	
	int balance;    //잔액
};

void print_acc(struct account* pacc);
void input_money(struct account* pacc, int money);
void output_money(struct account* pacc, int money);

int main()
{
	struct account acc = { 1111, "홍길동", 0 };
	print_acc(&acc);   //ex) 1111   홍길동    0원 

	input_money(&acc, 1000);    //1000원을 입금[잔액변경]
	print_acc(&acc);   //ex) 1111   홍길동    1000원 

	input_money(&acc, 500);    //500원을 입금[잔액변경]
	print_acc(&acc);   //ex) 1111   홍길동    1500원

	output_money(&acc, 1000);   //1000원을 출금[잔액변경]
	print_acc(&acc);   //ex) 1111   홍길동    500원

	return 0;
}

//ex) 1111   홍길동    0원 
void print_acc(struct account* pacc)
{
//	printf("%d\t%s\t%d원\n", (*pacc).number, (*pacc).name, (*pacc).balance);
	printf("%d\t%s\t%d원\n", pacc->number, pacc->name, pacc->balance);
}

void input_money(struct account* pacc, int money)
{
	pacc->balance = pacc->balance + money;
}

void output_money(struct account* pacc, int money)
{
	pacc->balance = pacc->balance - money;
}