//03_기본입출력

#include <iostream>
using std::cout;		//cout : 출력객체(console out, printf()) 프로그램 -> 모니터
using std::endl;
using std::cin;			//cin  : 입력객체( console in, scanf()) 키보드 -> 프로그램

int main()
{
	char name[20];
	int age;
	char gender;
	float weight;

	cout << "이름 : ";				cin >> name;	//scanf_s("%s", name, sizeof(name));
	cout << "나이 : ";				cin >> age;		//scanf_s("%d", &age);
	cout << "성별(m or f) : ";		cin >> gender;	//scanf_s("%c", &gender, sizeof(gender));
	cout << "몸무게 : ";			cin >> weight;	//scanf_s("%f", &weight);

	cout << "결과값\n" << endl;
	cout << "이름 : " << name << endl;		//printf("이름 : %s\n", name);
	cout << "나이 : " << age << endl;		//printf("나이 : %d\n", age);
	cout << "성별 : " << gender << endl;	//printf("성별 : %c\n", gender);
	cout << "몸무게 : " << weight << endl;	//printf("몸무게 : %f\n", weight);

	return 0;
}