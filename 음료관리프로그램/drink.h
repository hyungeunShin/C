//drink.h

typedef struct drink drink;
struct drink
{
	char name[20];  //이름( 중복되지 않는다.)
	int  price;	    //가격
};

//한줄에 모든 정보를 출력
void drink_print(const drink *pdrink);

//한줄에 하나의 정보를 출력 
void drink_println(const drink *pdrink);

drink drink_createdrink(const char* name, int price);
