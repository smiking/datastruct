#include "huffmancode.h"


void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char* sign){
	if(n<=1) return;
	int m=2*n-1;
	HT = (HuffmanTree) malloc((m+1)*sizeof(HTNode)); //0 useless
	HuffmanTree p;
	int i,s1,s2;
	for (i=1,p=HT+1;i <= n; ++i,++p,++w) *p = {*w,0,0,0,*(sign-1+i)}; // init bottom node and save the sign
	// printf("%d;",*w);
	for(;i<=m;++i,++p) *p = {0,0,0,0,'^'}; // init other father node
	printf("the huffman tree:\n");
	for(i=n+1;i<=m;++i){ // generate Tree
		Select(HT,i,s1,s2); // find the two minist weight
		HT[s1].parent = i;HT[s2].parent = i;
		HT[i].left = s1;HT[i].right = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		// printf("%d %d %d %d \n",i,HT[i].left,HT[i].right,HT[i].weight);
	}
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	char* cd = (char *)malloc(n*sizeof(char));  // a temp variety,save the very code after generate huffman code
	int start,c,f; //start:the number beginning of the huffman code,c:the son node,f:the father node
	for(i=1;i<=n;++i){
		start = n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].left==c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc(n-start*sizeof(char));
		// printf("%s\n",cd+start);
		strcpy(HC[i],&cd[start]);
		// printf("%s\n",HC[i]);
	}
	free(cd);
}

void Select(const HuffmanTree &HT,const int i,int &s1,int &s2){  // get the two minist value
	// printf("%d;",HT[1].weight);
	int j;
	for(j=1;j<i;j++){
		if(HT[j].parent ==0){
			s1=j++;
			// printf("%d-",s1);
			break;
		}
	}
	for(;j<i;j++){
		if(HT[j].parent ==0){
			s2=j++;
			// printf("%d\n",s2);
			break;
		}
	}
	if(HT[s1].weight>HT[s2].weight){   // s1 s2 initiated value,which has been the two minist value between of 2st
		int tmp;
		tmp=s1;s1=s2;s2=tmp;
	}
	while(j<i){    // from the 3st ,start to find the two minist value
		if(HT[j].parent==0 &&  HT[j].weight < HT[s1].weight){
			s2=s1;s1=j;
		}
		else if(HT[j].parent==0 && HT[j].weight>=HT[s1].weight && HT[j].weight<HT[s2].weight){
			s2=j;
		}
		j++;
	}
	printf("%d<-%d->%d\n",s1,i,s2);
}



void enCode(char* str,int n,const char* sign,const HuffmanCode &HC){
	// char* code = (char *)malloc(n*MAXTEXTLEN*sizeof(char)),* p=code;
	printf("the |%s| encode is:",str);
	int i=0,j;
	while(i < strlen(str)){
		j=0;
		while(j<n){
			if(str[i] == sign[j]){ // if equal the sign, then output the code
				printf("%s",HC[j+1]); // count form 1
				// p = HC[j];
				// p+=strlen(HC[j]);
				break;
			}
			j++;
		}
		if(j>=n){   // judge if the input content is wrong
			printf(" ERROR:!!!!!!!input error sign!!!!!!!\n");
			return;
		}
		i++;
	}
	printf("\n");
	// free(code);
}

void deCode(char* str,int n,const HuffmanTree &HT){ // get the origin text form the huffman tree,
	printf("the |%s| decode is:",str);
	int i,j;
	for (i = 0; i < int(strlen(str));) {  
		j = 2*n-1; // root node
		while(HT[j].left!=0){   // if arrive at the bottom  , exit then circulmulation
			// printf("%d",i);
			if(i >= int(strlen(str))){ // judge if the input code is wrong
				printf(" ERROR:!!!!!!!input error code!!!!!!!\n");
				return;
			}
			if(str[i]=='0') j=HT[j].left;
			else j=HT[j].right;
			i++;
		}
			// printf("\n%d\n",j);
		printf("%c",HT[j].sign);  // output the decode
	}
	printf("\n");
}






