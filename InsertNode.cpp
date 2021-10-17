#include "Tree.h"

void InsertNode(Tree **root, Tree *node){

	Tree *tmp = *root;

	if (!tmp) {
		*root = node;
		return ;
	}

	while (tmp) {
		
		if (tmp->value > node->value)
		{
			if (!tmp->Left) {
				tmp->Left = node;
				node->Parent = tmp;
				break;
			}
			tmp = tmp->Left;
		}
		else if (tmp->value < node->value)
		{
			if (!tmp->Right) {
				tmp->Right = node;
				node->Parent = tmp;
				break;
			}
			tmp = tmp->Right;
		}
		else {
			FreeNode(node);
			break;
		}
	}
}

Tree *NewNode(int value){
	Tree * tree = new Tree();

	tree->value = value;
	tree->Left = NULL;
	tree->Right = NULL;
	tree->Parent = NULL;

	return (tree);
}

void CreateTree(Tree **root, int *arr, size_t amount) {
	int i = 0;
	Tree *node;

	while (i < amount)
	{
		node = NewNode(arr[i]);
		InsertNode(root, node);
		i++;
	}
}