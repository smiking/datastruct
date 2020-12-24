#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXTEXTLEN 1024    // the max length of input encode content
#define MAXCODELEN 1024    // the max length of input decode code


typedef struct {
	int weight;
	int parent,left,right;
	char sign;
}HTNode,*HuffmanTree; 
typedef char ** HuffmanCode;

void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char* sign);

void Select(const HuffmanTree &HT,const int i,int &s1,int &s2);

void enCode(char* str,int n,const char* sign,const HuffmanCode &HC);

void deCode(char* str,int n,const HuffmanTree &HT);
