//�ҽ�7.c  �� �ҽ�5.c

/*
���°� �ְ�, 
[ struct account ]
- int number;	  //���¹�ȣ
- char name[20];  //����	
- int balance;    //�ܾ�
���¿� �Ա� ��� �ܾ� ��ȸ�ϴ� ����� �����Ͻÿ�.
*/
#include <stdio.h>

struct account
{
	int number;		//���¹�ȣ
	char name[20];  //����	
	int balance;    //�ܾ�
};

void print_acc(struct account* pacc);
void input_money(struct account* pacc, int money);
void output_money(struct account* pacc, int money);

int main()
{
	struct account acc = { 1111, "ȫ�浿", 0 };
	print_acc(&acc);   //ex) 1111   ȫ�浿    0�� 

	input_money(&acc, 1000);    //1000���� �Ա�[�ܾ׺���]
	print_acc(&acc);   //ex) 1111   ȫ�浿    1000�� 

	input_money(&acc, 500);    //500���� �Ա�[�ܾ׺���]
	print_acc(&acc);   //ex) 1111   ȫ�浿    1500��

	output_money(&acc, 1000);   //1000���� ���[�ܾ׺���]
	print_acc(&acc);   //ex) 1111   ȫ�浿    500��

	return 0;
}

//ex) 1111   ȫ�浿    0�� 
void print_acc(struct account* pacc)
{
//	printf("%d\t%s\t%d��\n", (*pacc).number, (*pacc).name, (*pacc).balance);
	printf("%d\t%s\t%d��\n", pacc->number, pacc->name, pacc->balance);
}

void input_money(struct account* pacc, int money)
{
	pacc->balance = pacc->balance + money;
}

void output_money(struct account* pacc, int money)
{
	pacc->balance = pacc->balance - money;
}