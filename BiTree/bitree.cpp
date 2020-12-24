#include "bitree.h"
#include "bitreeStack.h"

void createBiTree(BiTree &T){   //create by midTraversal iter
	int value;
	scanf(" %d",&value);
	if(value == 0) // 0 is null node
		T = NULL;
	else{
		T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		T->value = value;
		printf("%d-",value);
		createBiTree(T->left);
		createBiTree(T->right);
	}

}

void iterPreTraversal(BiTree &root){    // Traversal by iter
	if(root){
		iterPreTraversal(root->left);
		printf("%d-",root->value);
		iterPreTraversal(root->right);
	}
}

void preTraversal(BiTree &root){
	TStack* TS = NULL;
	BiTreeNode* p = root;
	while(TS!=NULL || p!=NULL){   // when Stack is empty and p is NULL ,exit
		while(p!=NULL){           // push all the left node in stack
			TS = TPush(TS,p);p=p->left;
		}
		p=TS->node;
		printf("%d-",p->value);
		TS = TPop(TS);           // pop, this node will be output
		p=p->right;              // p point p->ritht
	}
	printf("$\n");
}
