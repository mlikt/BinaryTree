#include "Tree.h"


int IamLeftOrRight(Tree *node) {
	if (node && !node->Parent)
		return (ROOT);
	if (node && node->Parent && node->Parent->Left == node)
		return (LEFT);
	if (node && node->Parent && node->Parent->Right == node)
		return (RIGHT);
	return (NOTCHILD);
}

void ToAdopt(Tree *parent, Tree *child, int direction) {
	if (direction == LEFT) {
		parent->Left = child;
		if (child)
			child->Parent = parent;
	} else if (direction == RIGHT) {
		parent->Right = child;
		if(child)
			child->Parent = parent;
	}
}

void PutInRoot(Tree *root, Tree *node, Tree *replace ) {
		if (IamLeftOrRight(replace) == LEFT)
			ToAdopt(root, node, LEFT);
		else if (IamLeftOrRight(replace) == RIGHT)
			ToAdopt(root, node, RIGHT);
}

void DeleteNode(Tree **root, int key) {
	Tree *node = FoundNode(*root, key);
	Tree *parent = NULL;

	if (!node)
		return ;
	if (node->Right == NULL) {
		if (IamLeftOrRight(node) != ROOT) {
			if (node->Left)
				PutInRoot(node->Parent, node->Left, node);
			else
				PutInRoot(node->Parent, NULL, node);
		} else {
			*root = node->Left;
			if (*root)
				(*root)->Parent = NULL;
		}
		FreeNode(node);
	} else if (IamLeftOrRight(node) == ROOT) {
		
		Tree *tmp = NULL;
		Tree *min = Min(node->Right);
		Tree *parent_min = min->Parent;

		parent = node;

		if (IamLeftOrRight(parent_min) != ROOT)
			parent_min->Left = min->Right;
		
		tmp = min->Right;
		min->Left = node->Left;

		if(min->Left)
			min->Left->Parent = min;

		if (node->Right != min) {
			min->Right = node->Right;
			if (min->Right)
				min->Right->Parent = min;
		}
		
		if (IamLeftOrRight(parent_min) != ROOT && tmp)
			tmp->Parent = parent_min;
		
		min->Parent = NULL;
		*root = min;
		
		FreeNode(node);
	} else if (node->Right) {
		Tree *min = Min(node->Right);
		Tree *parent_min = min->Parent;
		parent = node->Parent;

		if (parent_min == node && !parent_min->Left) {
			PutInRoot(parent, min, node);
			FreeNode(node);
			return ;
		}

		if (parent_min != node)
			parent_min->Left = min->Right;


		if (parent_min->Left) {
			if(parent_min != node)
				parent_min->Left->Parent = parent_min;
		}
	
		min->Left = node->Left;
		if (min->Left)
			min->Left->Parent = min;

		if (node->Right != min) {
			min->Right = node->Right;
			if (min->Right)
				min->Right->Parent = min;
		}

		PutInRoot(parent, min, node);
		FreeNode(node);
	}
}

size_t WhatLevelNode(Tree *root, Tree *node) {
	size_t lvl = 0;
	Tree *end = root;

	while (end) {
		if (end->value > node->value) {
			end = end->Left;
			lvl++;
		}
		else if (end->value < node->value) {
			end = end->Right;
			lvl++;
		}
		else
			return (lvl);
	}
	return (lvl);
}
