#include "stack.h"


Status InitStack(SqStack& S){
	S.base = (StackEleType*) malloc(STACK_SIZE*sizeof(StackEleType));
	if(!S.base) return OVERFLOW;
	S.top = S.base;
	S.Stacksize = STACK_SIZE;
	return OK;
}

Status push(SqStack& S,StackEleType& e){
	if(StackIsFull(S)){
		printf("Stack has full!\n");
		return OVERFLOW;
	}
	*S.top = e;
	S.top++;
	return OK;
}

int StackIsEmpty(SqStack& S){
	return S.top == S.base;
}

int StackIsFull(SqStack& S){
	return S.top-S.base==S.Stacksize;
}

Status pop(SqStack& S,StackEleType& e){
	if(StackIsEmpty(S)){
		printf("Stack is empt!");
		return OVERFLOW;
	}
	e = *--S.top;
	// S.top--;
	return OK;
}

Status clearStack(SqStack& S){
	S.top = S.base;
	return OK;
}

Status destroyStack(SqStack& S){
	free(S.base);
	return OK;
}

Status StackLength(SqStack& S){
	return S.top-S.base;
}

Status Stackprint(SqStack& S){
	StackEleType* p = S.base;
	if(StackIsEmpty(S)){
	printf("Stack is empty!\n");
	return OK;
	}
	printf("sum:|%d|  >-",StackLength(S));
	while(p!=S.top){
		printf("%d-",*p++);
	}
	printf(">\n");
	return OK;
}



