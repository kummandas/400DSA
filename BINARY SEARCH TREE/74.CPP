// Function to find the minimum element in the given BST.
/*int minValue(Node* root) {
    // base case
    if (root == NULL) return -1;

    struct Node* current = root;

    // leftmost node is minimum so we move in BST till left node is not NULL.
    while (current->left != NULL) {
        current = current->left;
    }
    // returning the data at leftmost node.
    return (current->data);
}
*/


// C++ program to find minimum value node in binary search
// Tree.

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). */
struct node* insert(struct node* node, int data)
{
	/* 1. If the tree is empty, return a new,
		single node */
	if (node == NULL)
		return (newNode(data));
	else {
		/* 2. Otherwise, recur down the tree */
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		/* return the (unchanged) node pointer */
		return node;
	}
}

/* Given a non-empty binary search tree,
inorder traversal for the tree is stored in
the vector sortedInorder.
Inorder is LEFT,ROOT,RIGHT*/
void inorder(struct node* node, vector<int>& sortedInorder)
{
	if (node == NULL)
		return;
	/* first recur on left child */
	inorder(node->left, sortedInorder);

	/* then insert the data of node */
	sortedInorder.push_back(node->data);

	/* now recur on right child */
	inorder(node->right, sortedInorder);
}

/* Driver code*/
int main()
{
	struct node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 4);
	insert(root, 5);

	vector<int> sortedInorder;
	inorder(
		root,
		sortedInorder); // calling the recursive function
	// values of all nodes will appear in sorted order in
	// the vector sortedInorder
	// Function call
	printf("\n Minimum value in BST is %d",
		sortedInorder[0]);
	getchar();
	return 0;
}

















EFFIRCIENT 
O(n)
O(1)





// C++ program to find minimum value node in binary search
// Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). */
struct node* insert(struct node* node, int data)
{
	/* 1. If the tree is empty, return a new,
		single node */
	if (node == NULL)
		return (newNode(data));
	else {
		/* 2. Otherwise, recur down the tree */
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		/* return the (unchanged) node pointer */
		return node;
	}
}

/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int minValue(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left;
	}
	return (current->data);
}

/* Driver Code*/
int main()
{
	struct node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 5);

	// Function call
	cout << "\n Minimum value in BST is " << minValue(root);
	getchar();
	return 0;
}

// This code is contributed by Mukul Singh.
