#include "Tree.h"

size_t ViewInfoAboutTree(Tree *root, int Key) {
	Counter counter;
	counter.CountNode(root, 0);

	std::cout << "Information about Tree:" << std::endl;
	counter.print_info();

	std::cout << "Information about Node: " << std::endl;
	Tree *Node = FoundNode(root, Key);
	if (Node) {
		std::cout << "Node         -> " << Node->value << std::endl;
		if (Node->Parent)
			std::cout << "Parent Node  -> " <<  Node->Parent->value  << std::endl;
		else
			std::cout << "This root" << std::endl;
	} else { std::cout << "Not Found Node" << std::endl; }
	return (counter.get_count());
}
