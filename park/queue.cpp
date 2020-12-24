#include "queue.h"

Status InitQueue(LinkQueue& Q){
	Q.front = Q.rear = (QueuePtr) malloc(sizeof(QueueEleType));
	if(!Q.front) return OVERFLOW;
	Q.front->next = NULL;
	Q.QueueLength = 0;
	return OK;
}

Status DestroyQueue(LinkQueue& Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

int QueueIsEmpty(LinkQueue& Q){
	return Q.front==Q.rear;
}


Status EnQueue(LinkQueue& Q,QueueEleType& e){
	QueuePtr p = (QueuePtr) malloc(sizeof(QueueEleType));
	if(!p) return OVERFLOW;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.QueueLength++;
	return OK;
}


Status DeQueue(LinkQueue& Q,QueueEleType& e){
	if(QueueIsEmpty(Q)) return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	Q.QueueLength--;
	return OK;
}


Status printQueue(LinkQueue& Q){
	QueuePtr p = Q.front->next;
	if(QueueIsEmpty(Q)){
	printf("Queue is empty!\n");
	return OK;
	}
	printf("sum:|%d|  <-",Q.QueueLength);
	while(p){
		printf("%d-",p->data);
		p=p->next;
	}
	printf("<\n");
	return OK;
}











