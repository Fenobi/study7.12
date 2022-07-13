#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"


//��̬��ʼ��
void InitContact(PhoneBook* pc)
{
	pc->data = (Contact*)malloc(sizeof(Contact) * DEFAULT_SZ);
	if (pc->data == NULL)
	{
		perror("IntiContact");
		exit(-1);
	}

	pc->capacity = DEFAULT_SZ;
	pc->num = 0;
}


//��ӡ
void PrintContact(PhoneBook* pc)
{
	int i = 0;
	//��ͷ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
	for (i = 0; i < pc->num; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
	}
}

//�������
void ChactCapacity(PhoneBook* pc)
{
	if (pc->capacity == pc->num)
	{
		Contact* ptr = (Contact*)realloc(pc->data, sizeof(Contact) * (INT_SZ + pc->capacity));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INT_SZ;
			printf("���ݳɹ���\n");
		}
		else
		{
			perror("AddContact");
			printf("����ʧ��!\n");
			exit(-1);
		}
	}
}

//������ϵ��
void AddContact(PhoneBook* pc)
{
	ChactCapacity(pc);

	printf("������������");
	scanf("%s", &pc->data[pc->num].name);
	printf("�������Ա�");
	scanf("%s", &pc->data[pc->num].sex);
	printf("���������䣺");
	scanf("%d", &pc->data[pc->num].age);
	printf("������绰���룺");
	scanf("%s", &pc->data[pc->num].tele);
	printf("�������ַ��");
	scanf("%s", &pc->data[pc->num].add);
	pc->num++;
	printf("�����ϵ�˳ɹ���\n");
}

size_t FindNum(PhoneBook* pc, char name[MAX_NAME])
{
	for (int i = 0; i < pc->num; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void DelContact(PhoneBook* pc)
{
	if (pc->num == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", &name);
	int n = FindNum(pc, name);
	if (n == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		int i = 0;
		for (i = n; i < pc->num - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->num--;
		printf("ɾ���ɹ�\n");
	}
}

//������ϵ��
void FindContact(PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", &name);
	int i = FindNum(pc, name);
	printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
}

void RevContact(PhoneBook* pc)
{
	printf("������Ҫ�޸���ϵ��������");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int n = FindNum(pc, name);
	if (n == -1)
	{
		printf("��Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("������������");
		scanf("%s", &pc->data[n].name);
		printf("�������Ա�");
		scanf("%s", &pc->data[n].sex);
		printf("���������䣺");
		scanf("%d", &pc->data[n].age);
		printf("������绰���룺");
		scanf("%s", &pc->data[n].tele);
		printf("�������ַ��");
		scanf("%s", &pc->data[n].add);

		printf("�޸���ϵ�˳ɹ���\n");
	}
}

void CmpByName(void* e1, void* e2)
{
	assert(e1 && e2);
	return strcmp(*(Contact*)e1, *(Contact*)e2);
}

//����
void SortContact(PhoneBook* pc)
{
	assert(pc);
	qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByName);
	printf("����ɹ���\n");
}

//���ͨѶ¼
void FreeContact(PhoneBook* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->num = pc->capacity = 0;
}
