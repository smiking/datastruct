#include "stdlib.h"
#include "stdio.h"
#include "bitree.h"
#ifndef BITTREESTAK_H
#define BITTREESTAK_H

typedef struct StackNode{
	BiTreeNode* node;
	struct StackNode* next;
	struct StackNode* pre;
}TStack;

TStack* TPush(TStack* Top,BiTreeNode* node);
TStack* TPop(TStack* Top);

#endif
