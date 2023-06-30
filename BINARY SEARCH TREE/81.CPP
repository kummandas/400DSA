/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N is the number of nodes in BST.



// Inorder traversal of the tree.
void inorder(TreeNode<int>* root, vector<int>& inorderArray) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, inorderArray);
    inorderArray.push_back(root -> data);
    inorder(root->right, inorderArray);
}

TreeNode<int>* bst(vector<int>& inorderArray, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Get the middle of the array and make it as the new root.
    int mid = (start + end) / 2;

    TreeNode<int>* root = new TreeNode<int> (inorderArray[mid]);

    // Make the left half of array as the left subtree.
    root -> left = bst(inorderArray, start, mid - 1);

    // Make the right half of array as the right subtree.
    root -> right = bst(inorderArray, mid + 1, end);

    return root;

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Array to store the nodes in the order of inorder traversal.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int n = inorderArray.size();

    return bst(inorderArray, 0, n-1);
}*/












// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

/* This function traverse the skewed binary tree and
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (root==NULL)
		return;

	// Store nodes in Inorder (which is sorted
	// order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
				int end)
{
	// base case
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	/* Using index in Inorder traversal, construct
	left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
	// Store nodes of given BST in sorted order
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	printf("Preorder traversal of balanced "
			"BST is : \n");
	preOrder(root);

	return 0;
}
