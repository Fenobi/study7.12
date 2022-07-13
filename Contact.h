#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADD 30

#define DEFAULT_SZ 3
#define INT_SZ 2

typedef struct Contact
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char add[MAX_ADD];
}Contact;

//��̬�汾
typedef struct PhoneBook
{
	Contact* data;//��̬����Ŀռ�
	int num;//��¼��Ч��Ϣ����
	int capacity;//��¼��ǰ�������
}PhoneBook;

//��̬��ʼ��
void InitContact(PhoneBook* pc);

//��ӡ
void PrintContact(PhoneBook* pc);

//������ϵ��
void AddContact(PhoneBook* pc);

//ɾ����ϵ��
void DelContact(PhoneBook* pc);

//������ϵ��
void FindContact(PhoneBook* pc);

//�޸���ϵ��
void RevContact(PhoneBook* pc);

//����
void SortContact(PhoneBook* pc);

//�������
void ChactCapacity(PhoneBook* pc);