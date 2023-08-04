//wbfile.c

#include "std.h"

void file_read(linkedlist *parr)
{
	//���Ͽ���
	FILE *fin;
	fopen_s(&fin, "drinklist1.txt", "r");
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
		list_frontinsert(parr, dr);
	}

	//���� ����
	fclose(fin);
}

void file_write(linkedlist *parr)
{
	//���Ͽ���
	FILE *fout;
	fopen_s(&fout, "drinklist1.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	node* cur = parr->head;
	while (cur != NULL)
	{
		drink dr = cur->data;
		fprintf(fout, "%10s %10d\n", dr.name, dr.price);
		cur = cur->next;
	}	

	//���� ����
	fclose(fout);
}