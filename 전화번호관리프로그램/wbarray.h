//wbarray.h

//����ü ����
typedef struct wbarr wbarr;
struct wbarr
{
	member *base;	//<------------------1)  ũ�Ⱑ �������� ���� �迭 ����.
	int max;								// �� �޸𸮿� �����Ǵ� �迭�� �ּҸ� ����!
	int size;
};

//�ʱ�ȭ
void arr_init(wbarr *parr, int usermax);
//����ó��
void arr_exit(wbarr *parr);
//����
int arr_insert(wbarr *parr, member value);
//����
int arr_delete(wbarr *parr, int idx);