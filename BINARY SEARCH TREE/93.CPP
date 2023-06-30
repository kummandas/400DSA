/*/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the total number of nodes in the givrn BST.


#include<vector>

void inorder(TreeNode<int>* root, vector<int> &inorderArray){
	if(root == NULL){
		return;
	}

	inorder(root->left, inorderArray);
	inorderArray.push_back(root->data);
	inorder(root->right, inorderArray);
}

TreeNode<int> *flatten(TreeNode<int>* root) {

	if(root == NULL){
		return root;
	}

	vector<int> inorderArray;
	inorder(root, inorderArray);

	// Create a pointer called newRoot, and store the first value of the array in it.
	TreeNode<int> *newRoot = new TreeNode<int>(inorderArray[0]);

	// Create a pointer called curr and store the newRoot in it.
	TreeNode<int> *curr = newRoot;

	for(int i = 1; i < inorderArray.size(); i++){

		// Create a new node.
		TreeNode<int> *temp = new TreeNode<int>(inorderArray[i]);

		// Make the left child of curr as NULL and right child as the temp. And make curr = temp.
		curr->left = NULL;
		curr->right = temp;
		curr = temp;
	}

	// Make both the left and the right child of the last node as NULL.
	curr->left = NULL;
	curr->right = NULL;

	return newRoot;
}*/



/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the total number of nodes in the givrn BST.
*/

#include<vector>

void inorder(TreeNode<int>* root, vector<int> &inorderArray){
	if(root == NULL){
		return;
	}

	inorder(root->left, inorderArray);
	inorderArray.push_back(root->data);
	inorder(root->right, inorderArray);
}

TreeNode<int> *flatten(TreeNode<int>* root) {

	if(root == NULL){
		return root;
	}

	vector<int> inorderArray;
	inorder(root, inorderArray);

	// Create a pointer called newRoot, and store the first value of the array in it.
	TreeNode<int> *newRoot = new TreeNode<int>(inorderArray[0]);

	// Create a pointer called curr and store the newRoot in it.
	TreeNode<int> *curr = newRoot;

	for(int i = 1; i < inorderArray.size(); i++){

		// Create a new node.
		TreeNode<int> *temp = new TreeNode<int>(inorderArray[i]);

		// Make the left child of curr as NULL and right child as the temp. And make curr = temp.
		curr->left = NULL;
		curr->right = temp;
		curr = temp;
	}

	// Make both the left and the right child of the last node as NULL.
	curr->left = NULL;
	curr->right = NULL;

	return newRoot;
}





















// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " ", curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void inorder(node* curr, node*& prev)
{
	// Base case
	if (curr == NULL)
		return;
	inorder(curr->left, prev);
	prev->left = NULL;
	prev->right = curr;
	prev = curr;
	inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
	// Dummy node
	node* dummy = new node(-1);

	// Pointer to previous element
	node* prev = dummy;

	// Calling in-order traversal
	inorder(parent, prev);

	prev->left = NULL;
	prev->right = NULL;
	node* ret = dummy->right;

	// Delete dummy node
	delete dummy;
	return ret;
}

// Driver code
int main()
{
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
	print(flatten(root));

	return 0;
}
