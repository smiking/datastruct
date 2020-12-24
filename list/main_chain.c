#include "stdio.h"
#include "chainlist.h"

void print(LinkList L);
int main()
{
	LinkList LL;
	InitList(LL);
	LL = CreateList(LL);
	print(LL);
	printf("insert 100 in 4\n");
	LL = ListInsert(LL, 4, 100);
	print(LL);
	printf("insert 100 in 0\n");
	LL = ListInsert(LL, 0, 100);
	print(LL);
	printf("insert 1011 in 1\n");
	LL = ListInsert(LL, 1, 1011);
	print(LL);
	printf("insert 10 in 16\n");
	LL = ListInsert(LL, 16, 10);
	print(LL);
	printf("insert 1244 in 100\n");
	LL = ListInsert(LL, 100, 1244);
	print(LL);
	printf("delete element in 0\n");
	LL = ListDlete(LL, 0);
	print(LL);
	printf("delete element in 1\n");
	LL = ListDlete(LL, 1);
	print(LL);
	printf("delete element in 3\n");
	LL = ListDlete(LL, 3);
	print(LL);
	printf("delete element in 100\n");
	LL = ListDlete(LL, 100);
	print(LL);
	printf("the first 34 is %d \n",ListSearch(LL,34));
	printf("the first 101 is %d \n",ListSearch(LL,101));
	ListDestory(LL);
	printf("free memory LL\n");

	return 0;
}


void print(LinkList L){
	LinkList p = L;
	while(p != NULL && p->next != NULL)
	{
		printf("%d-",p->value);
		p = p->next;
	}
	printf("%d-$$\n",p->value);
}
