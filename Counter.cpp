#include "Tree.h"


Counter::Counter():count_node(0L), count_leaves(0L), levels(0), tmp(0) {}
void Counter::CountNode(Tree *root, size_t i){
	
	if (!root) {
		
		if (i > levels)
			levels = i;
		return ;
	}
	count_node++;
	CountNode(root->Left, i + 1);
	CountNode(root->Right, i + 1);
	if (tmp < count_node) {
	tmp = count_node;
	count_leaves = count_node + 1;
	}
}
size_t Counter::get_count() const {
	return (count_node);
}
void Counter::print_info() const {
	std::cout << "count_node   -> " << count_node << std::endl;
	std::cout << "count_leaves -> " << count_leaves << std::endl;
	std::cout << "levels       -> " << levels << std::endl;
}

