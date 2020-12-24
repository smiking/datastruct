#ifndef ORDERLIST_H
#define ORDERLIST_H

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

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} list;

Status InitList(list* L);
Status CreateList(list* L);
Status ListInsert(list* L,int i,int e);
Status ListDlete(list* L,int i);
int ListSearch(list* L,ElemType e);
Status ListDestroy(list* L);


#endif
