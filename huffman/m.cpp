#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
	int weight;
	int parent,left,right;
	int visit=-1;
}HTNode,*HuffmanTree; 
typedef char ** HuffmanCode;


int main()
{
	// void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);
	// void Select(const HuffmanTree &HT,const int i,int &s1,int &s2);
	// HuffmanTree HT;
	// HuffmanCode HC;
	int n,* w;
	scanf("please input n:%d",&n);
	printf("pleas input w:");
	for (int i = 0; i < n; ++i) {
		// scanf("pleas input w:%d",w);
	}
	// CreateHuffmanCode(HT, HC, w,n);
	for (int i = 0; i < n; ++i) {
		// printf("%c",*(*HC+i));
	}
	

	return 0;
}




void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	void Select(const HuffmanTree &HT,const int i,int &s1,int &s2);
	if(n<=1) return;
	int m=2*n-1;
	HT = (HuffmanTree) malloc((m+1)*sizeof(HTNode)); //0 useless
	HuffmanTree p;
	int i,s1,s2;
	for (i=1,p=HT+1;i <= n; ++i,++p,++w) {} *p = {*w,0,0,0}; // generate first 
	for(;i<=m;++i,++p) *p = {0,0,0,0}; // generate other
	for(i=n+1;i<=m;++i){ // generate Tree
		Select(HT,i,s1,s2);
		HT[s1].parent = i;HT[s2].parent = i;
		HT[i].left = s1;HT[i].right = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	char* cd = (char *)malloc(n*sizeof(char));
	int start,c,f;
	for(i=1;i<=n;++i){
		start = n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].left==c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc(n-start*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

void Select(const HuffmanTree &HT,const int i,int &s1,int &s2){
	int j=3;
	s1 = HT[1].weight>HT[2].weight ? 2 : 1;
	s2 = HT[1].weight<HT[2].weight ? 1 : 2;
	while(j<i){
		if(HT[j].weight<HT[s1].weight){
			s2=s1;s1=j;
			return;
		}
		if(HT[j].weight>HT[s1].weight && HT[j].weight<HT[s2].weight){
			s2=j;
			return;
		}
	}
}




