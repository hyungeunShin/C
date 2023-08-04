//�ҽ�1.c
#include <stdio.h>

#define DATA_MAX	5

//�������� : �ڵ� �ʱ�ȭ
int base[DATA_MAX];
int max;
int size;

//�ʱ�ȭ
void arr_init()
{
	for (int i = 0; i < DATA_MAX; i++)
		base[i] = 0;

	max = DATA_MAX;
	size = 0;
}

//����
int arr_insert(int value)
{
	if (max <= size)
		return 0;

	base[size] = value; 
	size++;
	return 1;
}

//��ü ���
void arr_printall() //��ȸ
{
	printf("[%2d] : ", size);
	for (int i = 0; i < size; i++)  //����� ��ġ����??
	{
		printf("%d ", base[i]);
	}
	printf("\n");
}

//�˻�
int arr_select(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (base[i] == value)
			return i;
	}
	return -1;
}

//���� - ��ȿ����.
int arr_delete(int idx)
{
	//�������� �ε��� �Ǻ�
	if (idx < 0 || idx > size - 1)
		return 0;

	for (int i = idx; i < size - 1; i++)
	{
		base[i] = base[i + 1];
	}

	size--;
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