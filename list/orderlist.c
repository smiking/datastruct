#include "stdio.h"
#include "stdlib.h"
#include "orderlist.h"

Status InitList(list* L){
	L->elem = (ElemType*) malloc(LIST_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_SIZE;
	return OK;
}

Status CreateList(list* L){
	printf("please input or q for end!\n");
	ElemType tmp;
	while(L->length <= L->listsize && (scanf("%d",&tmp))==1){
		L->elem[L->length++]=tmp;
	}
	L->length--;
	if(L->length <= L->listsize)
		return OK;
	else
		return OVERFLOW;
}

Status ListInsert(list* L,int i,int e){
	if(i>=L->listsize){
		return OVERFLOW;
	}
	if(i>L->length){
		L->elem[L->length+1] = e;
	}
	int j = L->length;
	int flag = (L->length == (L->listsize-1));
	while(j>=i){
		if(flag == 1){
			L->elem[j] = L->elem[j-1];
		}else{
			L->elem[j+1] = L->elem[j];
		}
		j--;
	}
	L->elem[i] = e;
	L->length++;
	return OK;
}

Status ListDlete(list* L,int i){
	if(i>L->length)
	{
		printf("out of index\n");
		return OVERFLOW;
	}
	while (i < L->length) {
		L->elem[i] = L->elem[i+1];
		i++;
	}
	L->length--;
	return OK;
}

int ListSearch(list* L,ElemType e){
	int i = 0;
	while (i<=L->length && L->elem[i++]!=e) {}
	if(i>L->length)
		return -1;
	else
		return i-1;
}


Status ListDestroy(list* L){
	free(L->elem);
	return OK;
}
















