#include "adjmatrix_map.h"


void CreateMGraph(MGraph &G){
	int i,j,k,w;
	scanf("%d%d",&G.vexnum,&G.arcnum);
	for (i = 0; i < G.vexnum; ++i) scanf("%d",&G.vexs[i+1]);
	for (i = 0; i < G.vexnum; ++i)  // init matrix
		for (j = 0; j < G.vexnum; ++j) G.arcs[i+1][j+1] = {INFINITY,NULL};
	for (k = 0; k < G.arcnum ; ++k) {
		scanf("%d%d%d",&i,&j,&w);
		G.srcset[k] = {i,j,w};
		G.arcs[i][j].adj = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

void printMGraph(MGraph &G){          // output the MGraph
	int i,j,k;
	for (i = 0; i < G.vexnum; ++i) {
		for (j = 0; j < G.vexnum; ++j) {
			k = G.arcs[i+1][j+1].adj;
			if(k==INFINITY)
				printf("   ^");
			else
				printf("%4d",k);
		}
		printf("\n");
	}
}


void PRIM(const MGraph &G,VertexType u){  // u:the vex of beginning from PRIM
	int i,j,k;
	k=u;
	closedge closedge;            // closedge.lowcost always is the minist distance between very node to the mintree
	closedge[0].lowcost = INFINITY;  // use ini minimum()
	for (i = 1; i < G.vexnum+1; ++i)
		if(i!=k) closedge[i] = {u,G.arcs[k][i].adj};
	closedge[k].lowcost = 0;      // mark the first vertex
	printf("%d(%d)\n",k,0);
	for (i = 2; i < G.vexnum+1; ++i) {
		k = minimum(closedge,G.vexnum);  // find the minist edge
		printf("%d(%d)-",k,closedge[k].lowcost);
		for (j = 1; j < G.vexnum+1; ++j) {   // output the closedge
			printf("%d^",closedge[j].lowcost);
		}
		printf("\n");
		closedge[k].lowcost = 0;    // mark the minist vertex
		for(j=1;j<G.vexnum+1;j++){     // update the closedge if it ok
			if(G.arcs[k][j].adj < closedge[j].lowcost)
				closedge[j] = {G.vexs[k],G.arcs[k][j].adj};
	 	}
	}
}


int minimum(closedge closedge,int n){    // get the minist edge
	int i=1,min=0;
	for (; i < n+1; ++i) {
		if(closedge[i].lowcost != 0 && closedge[i].lowcost < closedge[min].lowcost)
			min = i;
	}
	return min;
}



void Kruskal(MGraph &G){
	SrcType* srcset = G.srcset;
	QuickSortSrc(srcset,0,G.arcnum-1);     // sort the edge
	int sign[G.vexnum+1];                 // the sign for divide different area
	int i,j,k,m,s=0,tmp1,tmp2;
	for (i = 1; i <= G.vexnum;sign[i]=i,i++);  // init  sign  :equal itself
	// for (i = 0; i < G.arcnum; ++i) {
	// 	printf("%d %d %d\n",G.srcset[i].vi,G.srcset[i].vj,G.srcset[i].weight);
	// }
	for (i = 0;s < G.vexnum-1 && i < G.arcnum ; ++i) {    // generate the minist tree
		j=srcset[i].vi;k=srcset[i].vj;
		if(sign[j] != sign[k]){                   // if this two vertex isn't in same area,output this edge ,
			s++;									//edge add 1
	 		printf("%d<-%d->%d\n",j,srcset[i].weight,k);
			tmp1 = sign[k];tmp2 = sign[j];        // the next for() will change the value of sign
			for(m=1;m<=G.vexnum;m++){
				if(sign[m]==tmp1) sign[m]=tmp2;    //make those two area merge to one
			}
		}
		
	}
}


void QuickSortSrc(SrcType* srcset,int l,int r){     // quick Sort  for sort the src
	if(l<r){
		int base = divsion(srcset,l,r);
		QuickSortSrc(srcset,l,base-1);
		QuickSortSrc(srcset,base+1,r);
	}
}


int divsion(SrcType* srcset,int left,int right) {          // recursion for quick sort
    SrcType base = srcset[left];
    while (left < right) {                                   // divsion dwo side for the left lower base and right larger than base
        while (left<right && srcset[right].weight >= base.weight) {
            right--;
        }
		srcset[left] = srcset[right];
        while (left<right && srcset[left].weight <= base.weight) {
            left++;
        }
        srcset[right] = srcset[left];
    }
    srcset[left] = base;
    return left;
}



