#include "map.h"


int main(){
	ALGraph G;
	CreateALGraph(G);
	printALGraph(G);
	// for (int i = 1; i < G.vexnnum+1; ++i) {
	// 	printf("%d\n",G.vertices[i].data);
    //
	// }
	printf("DFS:");
	DFSTraverse(G);
	printf("BFS:");
	BFSTraverse(G);
}
