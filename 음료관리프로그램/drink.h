//drink.h

typedef struct drink drink;
struct drink
{
	char name[20];  //�̸�( �ߺ����� �ʴ´�.)
	int  price;	    //����
};

//���ٿ� ��� ������ ���
void drink_print(const drink *pdrink);

//���ٿ� �ϳ��� ������ ��� 
void drink_println(const drink *pdrink);

drink drink_createdrink(const char* name, int price);
