#include "stdio.h"
#include "stack.h"
#include "queue.h"

int main()
{
	// SqStack S;
	// InitStack(S);
	// S.Stacksize =2 ;
	// int s_ele = 10,c=1,q_ele=100;
	// push(S,s_ele);
	// printf("%d,%d,%d\n",StackLength(S),c,StackIsFull(S));
	// s_ele =111;
	// push(S,s_ele);
	// printf("%d,%d,%d\n",StackLength(S),c,StackIsFull(S));
	// push(S,s_ele);
	// Stackprint(S);
	// pop(S,c);
	// printf("%d,%d,%d\n",StackLength(S),c,StackIsFull(S));
	// Stackprint(S);
	// destroyStack(S);
	// printf("-------------------------\n");
	// LinkQueue Q;
	// InitQueue(Q);
	// EnQueue(Q,q_ele);
	// q_ele=10;
	// EnQueue(Q,q_ele);
	// printQueue(Q);
	// printQueue(Q);
	// DeQueue(Q,c);
	// printf("enqueue :%d\n",c);
	// printQueue(Q);
	// DestroyQueue(Q);
	
	
	
	SqStack park,tmpLoae;
	LinkQueue sideLoae;
	/*
	 * park : the park
	 * tmpLoae: the loae while one car stay here leave park
	 * sideLoae: park car while the parkint is full
	 * assume the capacity of park is 10,and the tmpLoae is 100
	 */
	InitStack(park);
	park.Stacksize = 10;
	InitStack(tmpLoae);
	InitQueue(sideLoae);
	int sel;
	int number; // the tmp for storage value

	while(1){
		printf("********** INPUT 1: drive a car     2: leave a car  q: quit   *************\n");
		if(scanf("%d",&sel)!=1) break;
		switch(sel){
			case 1:{ // drive in a car
					   printf(">>>1: drive a car:");
					   if(scanf("%d",&number)!=1){
						   printf("!!!!!please the right number!!!!!\n");
						   break;
					   }
					   if(StackIsFull(park)){
						   EnQueue(sideLoae, number);
						   printf("----the car %d has leave in sideLoae\n",number);
					   }else{
						   push(park, number);
						   printf("----the car %d has leave in park\n",number);
					   }
					   break;
				   }
			case 2:{ // leave a car from the benginning of park
					   printf(">>>2: leave a car\n");
					   if(StackIsEmpty(park)){
						   printf("----the park is empty\n");
						   break;
					   }
					   printf("input the number between 1 ~ %d :",StackLength(park));
					   if(scanf("%d",&number)!=1 || number>StackLength(park)){ // the number is the distance between the car and the first car
						printf("!!!!!please the right number!!!!!\n");break;
						   break;
					   }
					   int tmpCar; // for exchange from park and tmpLoae
					   int tmpNum = 10 - number;
					   while(tmpNum-->0){
						   pop(park, tmpCar);
						   push(tmpLoae,tmpCar);
					   }
					   pop(park, number);
					   printf("----the car %d has leave\n",number);
					   while(!StackIsEmpty(tmpLoae)){
						   pop(tmpLoae, number);
						   push(park, number);
					   }
					   if(!QueueIsEmpty(sideLoae)){
						   DeQueue(sideLoae, number);
						   push(park, number);
					   }
					   break;
				   }
			default:printf("!!!!!please the right number!!!!!\n");break;
		}
		printf("==   park   == ");
		Stackprint(park);
		printf("== sideLoae == ");
		printQueue(sideLoae);
		printf("\n");
	}
	destroyStack(park);
	destroyStack(tmpLoae);
	DestroyQueue(sideLoae);
	printf("Over!");


	return 0;
}


