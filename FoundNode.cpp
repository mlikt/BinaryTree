#include "Tree.h"

Tree *FoundNode(Tree *root, int key) {
	Tree *end = root;

	while (end) {
		if (end->value > key)
			end = end->Left;
		else if (end->value < key)
			end = end->Right;
		else
			return (end);
	}
	return (NULL);
}

Tree *Max(Tree *root) {
	if (!root)
		return (root);
	while (root->Right)
		root = root->Right;
	return (root);
}

Tree *Min(Tree *root) {
	if (!root)
		return (root);
	while (root->Left)
		root = root->Left;
	return (root);
}