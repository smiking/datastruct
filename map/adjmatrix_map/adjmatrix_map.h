#ifndef ADJMATRIX_MAP_H
#define ADJMATRIX_MAP_H

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 21
typedef int VRType;
typedef char* InfoType;
typedef int VertexType;
typedef struct ArcCell{
	VRType adj;  // the weight or 1 and 0
	InfoType *info; // the infomation of this arc
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	int vi,vj,weight;
} SrcType;     // for Kruskal

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];    // the weight of vertex
	AdjMatrix arcs;                // the edge
	int vexnum,arcnum;
	// GraphKind kind;
	SrcType srcset[MAX_VERTEX_NUM*MAX_VERTEX_NUM];
}MGraph;

typedef struct {
	VertexType adjvex;  // the number of vex in this list
	VRType lowcost;  // the weight of src
} closedge[MAX_VERTEX_NUM];



void CreateMGraph(MGraph &G);
void printMGraph(MGraph &G);
void PRIM(const MGraph &G,VertexType u);
int minimum(closedge closedge,int n);
void Kruskal(MGraph &G);
void QuickSortSrc(SrcType* srcset,int l,int r);
int divsion(SrcType* srcset,int left,int right);

#endif
