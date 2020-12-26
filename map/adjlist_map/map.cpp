#include "queue.h"
#include "map.h"



void CreateALGraph(ALGraph &G){
	scanf("%d%d",&G.vexnnum,&G.arcnum);
	int i,j,k,w;
	ArcNode* node,*tmp;
	for (i = 1; i < G.vexnnum+1; ++i) {
		scanf("%d",&G.vertices[i].data);
		// printf("%d\n",G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		
	}
	printf("input arc (vi->vj) number and weight:\n");
	for(k=0;k<G.arcnum;++k){
		scanf("%d%d%d",&i,&j,&w);
		// printf("%d %d %d\n",i,j,w);
		node = (ArcNode*)malloc(sizeof(ArcNode));
		node->adjvex = j;
		node->info = w;
		node->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = node;
	}
}

void DFSTraverse(const ALGraph G){
	int visited[MAX_VERTEX_NUM+1] = {0};
	for(int i=1;i<G.vexnnum+1;i++){
		 // printf("%d %d\n",i,visited[i]);
		 if(visited[i]==0) {
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
		if(visited[tmp->adjvex]==0){
			printf("%d:%d->",tmp->adjvex,G.vertices[tmp->adjvex].data);
			visited[tmp->adjvex]=1;
			DFS(G,tmp->adjvex,visited);
		}
		tmp=tmp->nextarc;
	}
}


void BFSTraverse(const ALGraph G){
	int visited[MAX_VERTEX_NUM+1] = {0};
	int u;
	LinkQueue Q;
	InitQueue(Q);
	ArcNode* tmp;
	for(int i=1;i<G.vexnnum+1;i++){
		 if(visited[i]==0) {
			visited[i]=1;
			printf("%d:%d->",i,G.vertices[i].data);
			EnQueue(Q,i);
			while(!QueueIsEmpty(Q)){
				DeQueue(Q,u);
				tmp = G.vertices[u].firstarc;
				while(tmp){
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


















