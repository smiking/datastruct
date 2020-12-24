#ifndef STACK_H
#define STACK_H

#include "stdio.h"
#include "stdlib.h"

#define STACK_SIZE 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEARIBLE -1
#define OVERFLOW -2

typedef int StackEleType;
typedef int Status;

typedef struct {
	StackEleType* top;
	StackEleType* base;
	int Stacksize;
} SqStack;

Status InitStack(SqStack& S);
Status push(SqStack& S,StackEleType &e);
Status pop(SqStack& S,StackEleType &e);
Status clearStack(SqStack& S);
Status destroyStack(SqStack& S);
int StackIsEmpty(SqStack& S);
int StackIsFull(SqStack& S);
Status StackLength(SqStack& S);
Status Stackprint(SqStack& S);






#endif
