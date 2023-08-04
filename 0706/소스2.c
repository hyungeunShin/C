//�ҽ�2.c

#include <stdio.h>

#define DATA_MAX	5

//����ü ����
typedef struct wbarr wbarr;
struct wbarr
{
	int base[DATA_MAX];
	int max;
	int size;
};

//�������� : �ڵ� �ʱ�ȭ
wbarr arrlist;

//�ʱ�ȭ
void arr_init()
{
	for (int i = 0; i < DATA_MAX; i++)
		arrlist.base[i] = 0;

	arrlist.max  = DATA_MAX;
	arrlist.size = 0;
}

//����
int arr_insert(int value)
{
	if (arrlist.max <= arrlist.size)
		return 0;

	arrlist.base[arrlist.size] = value;
	arrlist.size++;
	return 1;
}

//��ü ���
void arr_printall() //��ȸ
{
	printf("[%2d] : ", arrlist.size);
	for (int i = 0; i < arrlist.size; i++)  //����� ��ġ����??
	{
		printf("%d ", arrlist.base[i]);
	}
	printf("\n");
}

//�˻�
int arr_select(int value)
{
	for (int i = 0; i < arrlist.size; i++)
	{
		if (arrlist.base[i] == value)
			return i;
	}
	return -1;
}

//���� - ��ȿ����.
int arr_delete(int idx)
{
	//�������� �ε��� �Ǻ�
	if (idx < 0 || idx > arrlist.size - 1)
		return 0;

	for (int i = idx; i < arrlist.size - 1; i++)
	{
		arrlist.base[i] = arrlist.base[i + 1];
	}

	arrlist.size--;
	return 1;
}

//����..(�˻�/����/��������)

int main()
{
	arr_init();

	for (int i = 0; i < 7; i++)
	{
		if (arr_insert(i + 1) == 0)
		{
			printf("���� ����\n");
			continue;
		}
		arr_printall();
	}

	arr_delete(2);
	arr_printall();

	arr_delete(2);
	arr_printall();

	if (arr_delete(5) == 0)
		printf("���� ����\n");
	arr_printall();

	return 0;
}