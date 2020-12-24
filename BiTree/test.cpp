#include "stdio.h"
#include "bitreeStack.h"

int main(){
	void p(TStack* TS);
	TStack* TS = NULL;
	TS = TPush(TS, 1);
	p(TS);
	TS = TPush(TS, 0);
	p(TS);
	TS = TPush(TS, 101);
	p(TS);
	TS = TPush(TS, 12);
	p(TS);
	TS = TPop(TS);
	p(TS);
}

void p(TStack* TS){
	TStack* p = TS;
	while(p){
		printf("%d-",p->value);
		p=p->next;
	}
	printf("$\n");
}

