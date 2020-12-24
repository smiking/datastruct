#ifndef CHAINLIST_H
#define CHAINLIST_H

#include "stdlib.h"
#include "stdio.h"
#define LIST_SIZE 100
#define INIT_LIST_SIZE 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEARIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType value;
	struct LNode* next;
} LNode, *LinkList;


Status InitList(LinkList L);
LinkList CreateList(LinkList L);
LinkList ListInsert(LinkList L,int i,int e);
LinkList ListDlete(LinkList L,int i);
int ListSearch(LinkList L,ElemType e);
void ListDestory(LinkList L);

#endif

