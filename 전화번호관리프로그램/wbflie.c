//wbfile.c

#include "std.h"

void file_read(wbarr *parr)
{
	//���Ͽ���
	FILE *fin;
	fopen_s(&fin, "��ȭ��ȣ��.txt", "r");
	if (fin == NULL)
	{
		printf("������ �������� �ʽ��ϴ�\n");
		return;
	}

	//���� read
	int size;
	fscanf_s(fin, "%d", &size); 

	member mem;
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fin, "%s %s",mem.name, sizeof(mem.name), mem.phone, sizeof(mem.phone));

		arr_insert(parr, mem);
	}

	//���� ����
	fclose(fin);
}

void file_write(wbarr *parr)
{
	//���Ͽ���
	FILE *fout;
	fopen_s(&fout, "��ȭ��ȣ��.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	for (int i = 0; i < parr->size; i++)
	{
		member mem = parr->base[i];
		fprintf(fout, "%10s %10s\n", mem.name, mem.phone);
	}

	//���� ����
	fclose(fout);

}