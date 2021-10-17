#include "Tree.h"

void FreeNode(Tree *node) {
	delete node;
}

void FreeTree(Tree *root) {

	if (!root)
		return ;
	FreeTree(root->Left);
	FreeTree(root->Right);
	FreeNode(root);
}
