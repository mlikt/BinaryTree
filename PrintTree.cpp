#include "Tree.h"


void PrintTree(Tree *tree) {
	if (!tree)
		return ;
	PrintTree(tree->Left);
	printf("%d ", tree->value);
	PrintTree(tree->Right);
}
