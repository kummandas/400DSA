// C++ program to print left view of
// Binary Tree

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of
// binary tree
void printLeftView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		// number of nodes at current level
		int n = q.size();
		
		// Traverse all nodes of current level
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
				
			// Print the left most element
			// at the level
			if (i == 1)
				cout<<temp->data<<" ";
			
			// Add left node to queue
			if (temp->left != NULL)
				q.push(temp->left);

			// Add right node to queue
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	

// Driver code
int main()
{
	// Let's construct the tree as
	// shown in example

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}

// This code is contributed by
// Manne SreeCharan














/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the number of nodes in the Binary Tree.
*/

//    Function for doing preorder traversal of a binary tree.
void preorderTraversal(TreeNode<int> *root, int level, int &maxLevel, vector<int> &leftView)
{
    if (root == NULL)
    {
        return;
    }

    //    If the current level is greater than the maxlevel then store the current node.
    if (level > maxLevel)
    {
        leftView.push_back(root->data);
        maxLevel = level;
    }

    //    Recur for the left subtree.
    preorderTraversal(root->left, level + 1, maxLevel, leftView);

    //    Recur for the right subtree.
    preorderTraversal(root->right, level + 1, maxLevel, leftView);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    
    //    For storing the left view of the binary tree.
    vector<int> leftView;

    int maxLevel = -1;

    //    Do a preorder traversal of the binary tree.
    preorderTraversal(root, 0, maxLevel, leftView);

    //    Return the left view of the binary tree.
    return leftView;
}