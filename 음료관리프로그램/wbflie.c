//wbfile.c

#include "std.h"

void file_read(wbarr *parr)
{
	//���Ͽ���
	FILE *fin;
	fopen_s(&fin, "drinklist.txt", "r");
	if (fin == NULL)
	{
		printf("������ �������� �ʽ��ϴ�\n");
		return;
	}

	//���� read
	int size;
	fscanf_s(fin, "%d", &size); 

	drink dr;
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fin, "%s %d", dr.name, sizeof(dr.name), &dr.price);

		arr_insert(parr, dr);
	}

	//���� ����
	fclose(fin);
}

void file_write(wbarr *parr)
{
	//���Ͽ���
	FILE *fout;
	fopen_s(&fout, "drinklist.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	for (int i = 0; i < parr->size; i++)
	{
		drink dr = parr->base[i];
		fprintf(fout, "%10s %10d\n", dr.name, dr.price);
	}

	//���� ����
	fclose(fout);

}