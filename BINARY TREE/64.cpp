// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct Node {
	int key;
	Node *left, *right;
};

// Function to create new tree node.
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

int ans = INT_MIN;
int dfs(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL and root->right == NULL)
		return root->key;
	// check for every subtree in left
	int sumleft = dfs(root->left);
	// check for every subtree in right
	int sumright = dfs(root->right);
	// sum of all the nodes in the subtree from root node
	int sumrootnode = sumleft + sumright + root->key;
	// temp max value of left and right subtree
	int tempmax = max(sumleft, sumright);

	tempmax = max(tempmax, sumrootnode);
	// update the answer from temp, ans
	ans = max(ans, tempmax);

	return sumrootnode;
}
int findLargestSubtreeSum(Node* root)
{

	// check for the base conditions
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->key;
	// function call of dfs
	int x = dfs(root);
	// return the final answer
	return ans;
}

// Driver function
int main()
{
	/*
			1
			/ \
			/	 \
		-2	 3
		/ \	 / \
		/ \ / \
		4	 5 -6	 2
	*/

	Node* root = newNode(1);
	root->left = newNode(-2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(-6);
	root->right->right = newNode(2);

	cout << findLargestSubtreeSum(root);
	return 0;
}
//this code is contributed by Prateek Kumar Singh
