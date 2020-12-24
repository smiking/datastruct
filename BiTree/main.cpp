#include "bitree.h"
/*
 * for text.txt input: 1 7 6 0 5 0 0 0 6 8 0 10 0 0 9 11 0 0 12 0 0
 * bitTree:                    1
 *                         /      \
 *                        7        6
 *                      /  \     /    \
 *                     6    0   8        9
 *                    / \      / \      /   \
 *                   0   5    0   10    11   12
 *                      / \      /  \  / \   / \
 *                      0  0     0   0 0  0  0  0
 */

int main(){
	BiTree root;
	printf("Create Bitree,the preTraversal is:");
	createBiTree(root);
	printf("$\n");
	printf("traversal bitree by iter:");
	iterPreTraversal(root);printf("$\n");
	printf("traversal bitree by stack and circle:");
	preTraversal(root);
}
