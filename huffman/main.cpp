#include "huffmancode.h"
/*
 * please input the format like the file test.txt,or there will be error
 *
 *
 */

int main()
{
	printf("************** BEGIN INIT ANT GENERATE HUFFMANCOTE ***********\n");
	HuffmanTree HT;
	HuffmanCode HC;
	int n,* w=(int*)malloc(n*(sizeof(int)));
	char * sign=(char*)malloc(n*(sizeof(char)));
	int flag,i,j;
	printf("pleast input the number of sign:\n");
	scanf("%d",&n);
	// printf("%d\n",n);
	// printf("pleas input n:%d",n);
	printf("please input %d those signs and weight: (FORMAT:s 10)\n",n);
	for (i = 0; i < n; ++i) {
		j=i-1;
		while(1){    // check it if repeated
			scanf(" %c %d",sign+i,w+i);
			while(j>=0){if(sign[i]==sign[j]) break;else j--;}
			if(j<0)
				break;
			else
				printf("!!!!exist same sign,please input again!");
		}
	}
	for (i = 0; i < n; ++i) {
		printf("%c:%d\n",*(sign+i),*(w+i));
	}
	CreateHuffmanCode(HT, HC, w,n,sign);
	for (i = 1; i <= n; ++i) {
		printf("the %c's huffman Code is %s\n",*(sign+i-1),HC[i]);
	}
	printf("Generate huffmancode finish!!\n");
	char* encodes = (char *)malloc(MAXTEXTLEN*sizeof(char));
	char* decodes = (char *)malloc(MAXCODELEN*sizeof(char));
	// fflush(stdin);
	// scanf("%s",encodes);
	// // printf("%s %d \n",encodes,int(strlen(encodes)));
	// enCode(encodes,n,sign,HC);
	// fflush(stdin);
	// scanf("%s",decodes);
	// // printf("%s",decodes);
	// // char a[] = "1010111011111001010";
	// deCode(decodes, n, HT);
	fflush(stdin);
	while(1){
		printf("*********** INPUT 1:encode  2:decode  -1:quit***************\n");
		scanf("%d",&flag);
		if(flag == -1) break;
		switch(flag){
			case 1:{
					   printf(">>>encode<<<\n");
					   scanf("%s",encodes);
					   enCode(encodes, n, sign,HC);
					   break;
				   }
			case 2:{
					   printf(">>>decode<<<\n");
					   scanf("%s",decodes);
					   deCode(decodes, n, HT);
					   break;
				   }
			default:printf("!!!!!please input the right code !!!!!!\n");
		}
	}
	printf("Quit!\n");
	free(sign);free(w);free(encodes);free(decodes);free(HT);free(HC); // free memory
	printf("free memory finish!\n");
	return 0;
}





