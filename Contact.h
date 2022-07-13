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

//动态版本
typedef struct PhoneBook
{
	Contact* data;//动态申请的空间
	int num;//记录有效信息个数
	int capacity;//记录当前最大容量
}PhoneBook;

//动态初始化
void InitContact(PhoneBook* pc);

//打印
void PrintContact(PhoneBook* pc);

//增加联系人
void AddContact(PhoneBook* pc);

//删除联系人
void DelContact(PhoneBook* pc);

//查找联系人
void FindContact(PhoneBook* pc);

//修改联系人
void RevContact(PhoneBook* pc);

//排序
void SortContact(PhoneBook* pc);

//检查扩容
void ChactCapacity(PhoneBook* pc);