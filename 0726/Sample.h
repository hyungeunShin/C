//sample.h
#pragma once
class Sample
{
public:
	Sample();
	~Sample();

public:
	static void reversestring(char* str, const char* src);
	static void dectobinary(int data);

	//중위표기법->후위표기법
public:
	//출력
	static void postfix(const char* src);
	//반환
	static void postfix1(/*[out]*/char* str, /*[in]*/const char* src);
	//십의자리 이상 처리
	static void postfix2(/*[out]*/char* str, /*[in]*/const char* src);

	//후위표기법 연산
public:
	static int my_cal(const char* src);
};

