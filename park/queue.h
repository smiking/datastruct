#ifndef QUEUE_H
#define QUEUE_H

#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEARIBLE -1
#define OVERFLOW -2

typedef int QueueEleType ;
typedef int Status ;
typedef struct QNode{
	QueueEleType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
	int QueueLength;
} LinkQueue;

Status InitQueue(LinkQueue& Q);
Status DestroyQueue(LinkQueue& Q);
// Status clearQueue(LinkQueue& Q);
int QueueIsEmpty(LinkQueue& Q);
// Status GetQueue(LinkQueue& Q,QueueEleType& e);
Status EnQueue(LinkQueue& Q,QueueEleType& e);
Status DeQueue(LinkQueue& Q,QueueEleType& e);
Status printQueue(LinkQueue& Q);









#endif
