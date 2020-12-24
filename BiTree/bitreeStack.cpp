#include "bitreeStack.h"

TStack* TPush(TStack* TS,BiTreeNode* node){
	TStack* N = (TStack*)malloc(sizeof(TStack));
	N->node = node;
	N->next = TS;
	TS = N;
	return TS;
}

TStack* TPop(TStack* TS){
	if(TS){
		TStack* tmp = TS;
		TS=TS->next;
		// printf("out %d\n",tmp->node->value);
		free(tmp);
	}else
		printf("ST is empty\n");
	return TS;
}
