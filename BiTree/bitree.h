#ifndef BITREE_H
#define BITREE_H
#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int value;
	struct node* left = NULL;
	struct node* right = NULL;
}BiTreeNode,*BiTree;

void createBiTree(BiTree &T);
void iterPreTraversal(BiTree &root);
void preTraversal(BiTree &root);

#endif
