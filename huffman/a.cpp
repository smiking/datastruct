#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",n);
	int *w = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d",w+i);
	}
	for (int i = 0; i < n; ++i) {
		printf("pleas input w:%d\n",*(w+i));
	}
	// CreateHuffmanCode(HT, HC, w,n);
	char c;
	scanf("1%c",&c);
	printf("stnraietnsi%c",c);
	char** s;

	cout << "tsatsr";;
	return 0;
}
