#include "queue.h"
#include "map.h"



void CreateALGraph(ALGraph &G){
	printf("please input the weight of very vertex:\n");
	scanf("%d%d",&G.vexnnum,&G.arcnum);
	int i,j,k,w;
	ArcNode* node;
	for (i = 1; i < G.vexnnum+1; ++i) {         // iuput the weight of very vertex
		scanf("%d",&G.vertices[i].data);
		// printf("%d\n",G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		
	}
	printf("input arc (vi->vj) number and weight FORMAT:(begin node,end node,weight of this edge):\n");
	for(k=0;k<G.arcnum;++k){
		scanf("%d%d%d",&i,&j,&w);           // iuput (begin node,end node,weight of this edge)
		// printf("%d %d %d\n",i,j,w);
		node = (ArcNode*)malloc(sizeof(ArcNode));
		node->adjvex = j;
		node->info = w;
		node->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = node;           // insert the new node before the first arcnode
	}
}

void printALGraph(const ALGraph &G){
	printf("the adjcent list is below:\n");
	int k;
	ArcNode* node;
	for(k=1;k<G.vexnnum+1;++k){
		printf("%d(%d) :",k,G.vertices[k].data);
		node = G.vertices[k].firstarc;
		while(node){
			printf("[%d|%d]->",node->adjvex,node->info);
			node = node->nextarc;
		};
		printf("[NULL]\n");
	}

}

void DFSTraverse(const ALGraph G){
	int visited[MAX_VERTEX_NUM+1] = {0};
	for(int i=1;i<G.vexnnum+1;i++){
		 // printf("%d %d\n",i,visited[i]);
		 if(visited[i]==0) {        // DFS if the vertex hasn't been visited
			visited[i]=1;
			printf("%d:%d->",i,G.vertices[i].data);
			DFS(G,i,visited);
		 }
	 }
	 printf("$\n");
}

void DFS(ALGraph G,int v,int* visited){
	ArcNode* tmp = G.vertices[v].firstarc;
	while(tmp){
		if(visited[tmp->adjvex]==0){    // DFS the vertex's very adjcent node
			printf("%d:%d->",tmp->adjvex,G.vertices[tmp->adjvex].data);
			visited[tmp->adjvex]=1;
			DFS(G,tmp->adjvex,visited);
		}
		tmp=tmp->nextarc;    // to next node
	}
}


void BFSTraverse(const ALGraph G){
	int visited[MAX_VERTEX_NUM+1] = {0};
	int u;
	LinkQueue Q;
	InitQueue(Q);  // init Queue
	ArcNode* tmp;
	for(int i=1;i<G.vexnnum+1;i++){
		 if(visited[i]==0) {
			visited[i]=1;
			printf("%d:%d->",i,G.vertices[i].data);
			EnQueue(Q,i);         // if this vertex hasn't been visited, EnQueue this vertex
			while(!QueueIsEmpty(Q)){   // when queue is empty, goto next circulation
				DeQueue(Q,u);        // DeQueue this the first vertex in queue 
				tmp = G.vertices[u].firstarc;
				while(tmp){     // EnQueue this vertex very adjcent node and set visited
					if(visited[tmp->adjvex]==0){
						printf("%d:%d->",tmp->adjvex,G.vertices[tmp->adjvex].data);
						visited[tmp->adjvex] = 1;
						EnQueue(Q,tmp->adjvex);
					}
					tmp=tmp->nextarc;
				}
			 }
		 }
	 }
	 printf("$\n");

}


















