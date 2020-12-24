#include "stdio.h"
#include "orderlist.h"

void print(ElemType *p,int len);

int main(){
	list LL;
	printf("init List\n");
	InitList(&LL);
	printf("Create List\n");
	CreateList(&LL);
	print(LL.elem,LL.length);
	printf("insert 100 in 3 \n");
	ListInsert(&LL,3, 100);
	print(LL.elem,LL.length);
	printf("insert 0 in 0 \n");
	ListInsert(&LL,0, 0);
	print(LL.elem,LL.length);
	printf("insert 90 in 90 \n");
	ListInsert(&LL,90, 90);
	print(LL.elem,LL.length);
	printf("delete element in 5\n");
	ListDlete(&LL,5);
	print(LL.elem,LL.length);
	printf("delete element in 90\n");
	ListDlete(&LL,90);
	print(LL.elem,LL.length);
	printf("delete element in 0\n");
	ListDlete(&LL,0);
	print(LL.elem,LL.length);
	printf("the frist 23 is %d \n",ListSearch(&LL,23));
	printf("the frist 1001 is %d \n",ListSearch(&LL,1001));
	ListDestroy(&LL);
}



void print(ElemType *p,int len){
	for (int i = 0; i <= len; i++) {
		printf("%d-",p[i]);
	}
	printf("$\n");
}
