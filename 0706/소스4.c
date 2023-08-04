//�ҽ�4.c

//�����޸�
#include <stdio.h>
#include <malloc.h> //�����޸�

//mallc(byte), calloc(������Ÿ��ũ��, ����) ==> byte(������Ÿ��ũ�� * ����)
//free
//realloc
void exam1()
{
	//heap(�����޸�) ��û -> �ּ� ��ȯ
	int *p1 = (int*)malloc(sizeof(int));		//4byte
	char*p2 = (char*)malloc(sizeof(char));		//1byte
	int *p3 = (int*)calloc(sizeof(int), 1);		//4 * 1byte
	char*p4 = (char*)calloc(sizeof(char), 1);	//1 * 1byte

	//-------------���(������ ������ ����)----------------
	*p1 = 10;
	*p2 = 'A';
	*p3 = 20;
	*p4 = *p2;
	//-----------------------------------------------------
	
	//�޸� ���� ��û!
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}

//����ó��
//�����޸� ��û�� ������ ���� �ִ�.(���н� NULL�� ��ȯ, ������ �ּ� ��ȯ)
void exam2()
{
	int *p1;
	p1 = (int*)malloc(sizeof(int)); 
	if (p1 == NULL)
	{
		printf("�޸� ���� ����\n");
		return;
	}

	//���

	free(p1);
}


//Ȱ��1) �����޸𸮸� Ȱ���� ���� �迭 ����
//int num = 10;
//int arr[num];  //����
void exam3()
{
	int arr[10];  // ������ ũ���� �迭
	int* arr1;    // ������~ (1���� �迭�� �ּҸ� ������ �� �ִ�.)
	arr1 = arr;

	int* arr2;
	int max;
	printf("���� ���� : ");			scanf_s("%d", &max);
	arr2 = malloc(sizeof(int)* max); //���� �迭 ����

	for (int i = 0; i < max; i++)
		arr2[i] = i;

	for (int i = 0; i < max; i++)
		printf("%d ", arr2[i]);


	free(arr2);
}

//Ȱ��2) ��������
int* g_arr[5];  //int�� �ּҸ� �����ϴ� ���� 5�� ����

void exam4()
{
	int num = 10;
	g_arr[0] = &num;	//ok.( ������� ������ �ּҸ� ����...)?

	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	g_arr[0] = p;
}

void exam4_1()
{
	printf("%d\n", *g_arr[0]); // ������(��򰡷� ����)
}

//realloc : �����޸� ���Ҵ�,
void exam5()
{
	int max = 5;
	int *arr = (int*)malloc(sizeof(int)* max);

	for (int i = 0; i < 5; i++)
		arr[i] = i;

	//�߰��� 5���� ������ �� Ȯ��( ���� 5 + �߰� 5 )
	max = 10;
	arr= realloc(arr, sizeof(int)* 10);   // arr�� ���� �����޸� ���� �ּ�. 10���� �������� Ȯ��

	for (int i = 5; i < 10; i++)
		arr[i] = i;

	//���Ȯ��
	for (int i = 0; i < max; i++)
		printf("%d ", arr[i]);

	free(arr);
}

int main()
{
	//exam4();
	//exam4_1();
	exam5();

	return 0;
}