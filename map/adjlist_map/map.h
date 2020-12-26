#ifndef MAP_H
#define MAP_H
#include "stdlib.h"
#include "stdio.h"
#define MAX_VERTEX_NUM 20
typedef int InfoType;
typedef int VertexType;
typedef struct ArcNode{
	int adjvex;
	InfoType info;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode* firstarc;
}VNode,AdjList[MAX_VERTEX_NUM+1];

typedef struct {
	AdjList vertices;
	int vexnnum,arcnum;
}ALGraph;

void CreateALGraph(ALGraph &G);
void DFSTraverse(const ALGraph G);
void DFS(const ALGraph G,int v,int* visited);
void BFSTraverse(const ALGraph G);


#endif
