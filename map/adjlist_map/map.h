#ifndef MAP_H
#define MAP_H
#include "stdlib.h"
#include "stdio.h"
#define MAX_VERTEX_NUM 20
typedef int InfoType;
typedef int VertexType;
typedef struct ArcNode{
	int adjvex;         // the edge the begin node number
	InfoType info;      //  the weight of edge
	struct ArcNode* nextarc;    // next node
}ArcNode;    // the adjacent list node

typedef struct VNode{
	VertexType data;           // the weight of the vertex
	ArcNode* firstarc;          // the first arcNode of very vertex
}VNode,AdjList[MAX_VERTEX_NUM+1];      // the vertex  node

typedef struct {
	AdjList vertices;              // the adjacent list of this Graph
	int vexnnum,arcnum;            // vertex number and edge number
}ALGraph;             // the Graph

void CreateALGraph(ALGraph &G);
void printALGraph(const ALGraph &G);
void DFSTraverse(const ALGraph G);
void DFS(const ALGraph G,int v,int* visited);
void BFSTraverse(const ALGraph G);


#endif
