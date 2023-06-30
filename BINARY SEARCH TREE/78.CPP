/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the total number of nodes of the BST.



TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while (root != NULL)
	{
		if (root -> data < P -> data && root -> data < Q -> data)
		{
			root = root -> right;
		}
		else if (root -> data > P -> data && root -> data > Q -> data)
		{
			root = root -> left;
		}
		else
		{
			return root;
		}
	}
}
*/


// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left, *right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both n1 and n2
are present in BST */
node* lca(node* root, int n1, int n2)
{
	while (root != NULL) {
		// If both n1 and n2 are smaller than root,
		// then LCA lies in left
		if (root->data > n1 && root->data > n2)
			root = root->left;

		// If both n1 and n2 are greater than root,
		// then LCA lies in right
		else if (root->data < n1 && root->data < n2)
			root = root->right;

		else
			break;
	}
	return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

/* Driver code*/
int main()
{
	// Let us construct the BST
	// shown in the above figure
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	// Function calls
	int n1 = 10, n2 = 14;
	node* t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;
	return 0;
}

// This code is contributed by rathbhupendra













//Function to find the lowest common ancestor in a BST.
Node* LCA(Node *root, int n1, int n2)
{
    // base case
    if(root==NULL)
        return NULL;
    
    //If both n1 and n2 are smaller than data at current node, we call 
    //the function recursively for finding LCA in the left subtree. 
    if(n1<root->data and n2<root->data)
    {
        return LCA(root->left,n1,n2);
    }
    //If both n1 and n2 are greater than data at current node, we call 
    //the function recursively for finding LCA in the right subtree. 
    if(n1>root->data and n2 > root->data)
    {
        return LCA(root->right,n1,n2);
    }
    
    //returning the lowest common ancestor.
    return root;
}