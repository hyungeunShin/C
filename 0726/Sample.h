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

	//����ǥ���->����ǥ���
public:
	//���
	static void postfix(const char* src);
	//��ȯ
	static void postfix1(/*[out]*/char* str, /*[in]*/const char* src);
	//�����ڸ� �̻� ó��
	static void postfix2(/*[out]*/char* str, /*[in]*/const char* src);

	//����ǥ��� ����
public:
	static int my_cal(const char* src);
};

