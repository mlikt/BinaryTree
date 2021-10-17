#include "Tree.h"
#include <string>


void printSubtree(Tree* root, const std::string& prefix);

void PrintGraph(Tree* root)
{
        if (root == NULL)
        {
                return;
        }

        std::cout << root->value << std::endl;
        printSubtree(root, "");
        std::cout << std::endl;
}

void printSubtree(Tree* root, const std::string& prefix)
{
        if (root == NULL)
        {
                return;
        }

        bool hasLeft = (root->Left != NULL);
        bool hasRight = (root->Right != NULL);

        if (!hasLeft && !hasRight)
        {
                return;
        }

        std::cout << RED << prefix << RESETCOLOR << std::flush;
        std::cout << BLUE << ((hasLeft  && hasRight) ? "├── " : "") << RESETCOLOR << std::flush;
        std::cout << BLUE <<  ((!hasLeft && hasRight) ? "└── " : "") << RESETCOLOR << std::flush;

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (root->Right->Right != NULL || root->Right->Left != NULL));
                std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                std::cout << root->Right->value << std::endl;
                printSubtree(root->Right, newPrefix);
        }

        if (hasLeft)
        {
                std::cout << RED << (hasRight ? prefix : "") << "└── " << RESETCOLOR << root->Left->value  << std::endl;
                printSubtree(root->Left, prefix + "    ");
        }
}