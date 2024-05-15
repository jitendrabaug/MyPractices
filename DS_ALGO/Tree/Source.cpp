#include"Traversal.h"
#include<iostream>
using namespace std;


int main()
{
	Tree tree;
	tree.root = new Node(10);
	tree.root->left = new Node(20);
	tree.root->right = new Node(30);

	tree.root->right->left = new Node(40);
	tree.root->right->right = new Node(50);

	std::cout << "InOrder Traversal : ";
	tree.Inorder(tree.root);
	std::cout << std::endl;

	std::cout << "PreOrder Traversal : ";
	tree.PreOrder(tree.root);
	std::cout << std::endl;

	std::cout << "PostOrder Traversal : ";
	tree.PostOrder(tree.root);
	std::cout << std::endl;

	std::cout << "LevelOrder Traversal : ";
	tree.LevelOrder();
	std::cout << std::endl;

	std::cout << "LevelOrder Traversal by Line : \n";
	tree.LevelOrderByLine();
	std::cout << std::endl;

	std::cout << "LevelOrder Traversal by Line 2 : \n";
	tree.LevelOrderByLine2();
	std::cout << std::endl;

	std::cout << "Height of the tree : " << tree.height(tree.root) <<std::endl;


	std::cout << "Nodes at 2nd level are : ";
	tree.printKDistanceLevel(tree.root, 2);
	std::cout << std::endl;
}
