#include "chainlist.h"

Status InitList(LinkList L){
	L = NULL;
	return OK;
};

LinkList CreateList(LinkList L){
	printf("please input or q for end!\n");
	LNode* tmpl;
	int tmp;
	while((scanf("%d",&tmp))==1){
		LNode* p = (LNode*) malloc(sizeof(LNode));
		p->value = tmp;
		if(L==NULL)
		{
			L = p;
			tmpl = L;
		}
		else{
			tmpl->next = p;
			tmpl = tmpl->next;
		}
	}
	return L;
}


LinkList ListInsert(LinkList L,int i,int e){
	LNode* p = L;
	LNode* pt = (LNode*) malloc(sizeof(LNode));
	pt->value = e;
	if(i==0){
		pt->next = L;
		L = pt;
		return L;
	}
	i--;
	while(i-->0){
		if(p->next==NULL)
		{
			/* printf("pt->value%d %d\n",pt->value,i); */
			p->next = pt;
			return L;
		}
		p=p->next;
			/* printf("p->value%d\n",p->value); */
	}
	pt->next = p->next;
	p->next = pt;
	return L;
}


LinkList ListDlete(LinkList L,int i){
	LNode* p = L;
	if(i==0){
		L = L->next;
		free(p);
		return L;
	}
	i--;
	while(i-->0){
		if(p->next == NULL){
			printf("the node is null\n");
			return L;
		}
		p=p->next;
	}
	LNode* pt = p->next;
	p->next = p->next->next;
	free(pt);
	return L;
}

int ListSearch(LinkList L,ElemType e){
	LNode* p = L;
	int i = 0;
	while(p != NULL && p->value != e){
		p=p->next;
		i++;
	}
	if(p==NULL)
		return -1;
	return i;
}


void ListDestory(LinkList L){
	LinkList p = L;
	while(L!=NULL){
		L=L->next;
		free(p);
		p=L;
	}
};




