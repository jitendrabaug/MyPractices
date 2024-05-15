#pragma once
#include<iostream>
#include<queue>
#include<algorithm>



struct Node
{
	Node* left{ nullptr };
	Node* right{ nullptr };
	int data;

	Node(int payload) : data(payload) {}
};

using std::cout;
using std::queue;
class Tree
{

public:
	Node* root{ nullptr };

	void Inorder(Node* root)  // Left--Root--Right
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			std::cout << root->data << " ";
			Inorder(root->right);
		}
	}


	void PreOrder(Node* root) // Root--Left--Right
	{
		if (root != nullptr)
		{
			std::cout << root->data << " ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}


	void PostOrder(Node* root) // Left--Right--Root
	{
		if (root != nullptr)
		{
			PostOrder(root->left);
			PostOrder(root->right);
			std::cout << root->data << " ";
		}
	}



	void LevelOrder() //Print Each level. This is BFS traversal
	{
		if (root)
		{
			queue<Node*> q;
			q.push(root);
			while (!q.empty())
			{
				auto temp = q.front();
				cout << temp->data << " ";
				q.pop();
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
		}
		
	}

	void LevelOrderByLine()
	{
		if (root)
		{
			queue<Node*> q;
			q.push(root);
			q.push(nullptr);
			while (q.size() > 1)
			{
				Node* curr = q.front();
				q.pop();

				if (curr == nullptr)
				{
					q.push(nullptr);
					std::cout << std::endl;
					continue;
				}

				std::cout << curr->data << " ";

				if (curr->left)
					q.push(curr->left);

				if (curr->right)
					q.push(curr->right);
			}
		}
	}



	void LevelOrderByLine2()
	{
		if (root)
		{
			queue<Node*> q;
			q.push(root);

			while (!q.empty())
			{
				int count = q.size();
				for (int i = 0; i < count; i++)
				{
					Node* curr = q.front();
					std::cout << curr->data << " ";
					q.pop();

					if (curr->left) q.push(curr->left);
					if (curr->right) q.push(curr->right);
				}

				std::cout <<std::endl;
			}


		}
	}

	
	void printKDistanceLevel(Node* root, int level)
	{
		if (root == nullptr)
			return;
		if (level == 0)
			cout << root->data << " ";
		else  {
			printKDistanceLevel(root->left, level - 1);
			printKDistanceLevel(root->right, level - 1);
		}
	}

	int height(Node* node)
	{
		if (!node)
			return 0;
		else
			return std::max(height(node->left), height(node->right)) + 1;
	}
};