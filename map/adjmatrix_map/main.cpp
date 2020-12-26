#include "adjmatrix_map.h"

int main(){
	MGraph G;
	CreateMGraph(G);
	printMGraph(G);
	PRIM(G,1);
	Kruskal(G);
}
