#ifndef __TREE_H_
#define __TREE_H_
#include <stdlib.h>
#include <iostream>

#define LEFT		1
#define RIGHT		2
#define ROOT		3
#define NOTCHILD	4

#define BLACK  "\033[22;30m"
#define YELLOW    "\033[22;33m"
#define RED  "\033[22;31m"
#define GREEN "\e[0;32m"
#define BLUE  "\033[40;34m"
#define RESETCOLOR "\033[0m"

typedef struct MyTree
{
	int value;
	struct MyTree * Left;
	struct MyTree *	Parent;
	struct MyTree * Right;
} Tree;

class Counter {
	private:
		size_t count_node;
		size_t count_leaves;
		size_t levels;
		size_t tmp;
	public:
	
	Counter();
	void CountNode(Tree *root, size_t i);
	size_t get_count() const;
	void print_info() const ;

};

void InsertNode(Tree **root, Tree *node);
Tree *NewNode(int value);
void CreateTree(Tree **root, int *arr, size_t amount);

void FreeNode(Tree *node);
void FreeTree(Tree *root);

void PrintTree(Tree *tree);
void PrintGraph(Tree* root);
size_t ViewInfoAboutTree(Tree *root, int Key);

Tree *FoundNode(Tree *root, int key);
Tree *Max(Tree *root);
Tree *Min(Tree *root);

void DeleteNode(Tree **root, int key);
void ToAdopt(Tree *parent, Tree *child, int direction);
int  IamLeftOrRight(Tree *node);

size_t WhatLevelNode(Tree *root, Tree *node);
#endif