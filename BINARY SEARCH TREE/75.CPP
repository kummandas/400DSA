// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	// Base case
	if (root == NULL) return ;

	// If key is present at root
	if (root->key == key)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			Node* tmp = root->left;
			while (tmp->right)
				tmp = tmp->right;
			pre = tmp ;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			Node* tmp = root->right ;
			while (tmp->left)
				tmp = tmp->left ;
			suc = tmp ;
		}
		return ;
	}

	// If key is smaller than root's key, go to left subtree
	if (root->key > key)
	{
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	else // go to right subtree
	{
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
}

// A utility function to create a new BST node
Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

// Driver program to test above function
int main()
{
	int key = 65; //Key to be searched in BST

/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);


	Node* pre = NULL, *suc = NULL;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << "Predecessor is " << pre->key << endl;
	else
	cout << "No Predecessor";

	if (suc != NULL)
	cout << "Successor is " << suc->key;
	else
	cout << "No Successor";
	return 0;
}













/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the number of nodes in the BST.
*/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Reach to the key.
    while (root -> data != key)
    {
        if (key > root -> data)
        {
            predecessor = root -> data;
            root = root -> right;
        }
        else
        {
            successor = root -> data;
            root = root -> left;
        }
    }

    
    BinaryTreeNode<int>* rightSubtree = root -> right;

    while (rightSubtree != NULL)
    {
        successor = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }


    BinaryTreeNode<int>* leftSubtree = root -> left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }

    return {predecessor, successor};
}














// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node {
	int key;
	struct Node *left, *right;
};

// This function finds predecessor and successor of key in
// BST. It sets pre and suc as predecessor and successor
// respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	// set pre and suc as NULL initially
	pre = NULL;
	suc = NULL;

	// set temp node as root
	Node* temp1 = root;
	while (temp1) {
		// the maximum value in left subtree is successor
		if (temp1->key > key) {
			suc = temp1;
			temp1 = temp1->left;
		}
		else
			temp1 = temp1->right;
	}
	Node* temp2 = root;
	while (temp2) {
		// the minimum value in right subtree is predecessor
		if (temp2->key < key) {
			pre = temp2;
			temp2 = temp2->right;
		}
		else
			temp2 = temp2->left;
	}
	return;
}

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in
* BST */
Node* insert(Node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

// Driver program to test above function
int main()
{
	int key = 65; // Key to be searched in BST

	/* Let us create following BST
							50
					/	 \
					30	 70
					/ \ / \
			20 40 60 80 */
	Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	Node *pre = NULL, *suc = NULL;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
		cout << "Predecessor is " << pre->key << endl;
	else
		cout << "No Predecessor";

	if (suc != NULL)
		cout << "Successor is " << suc->key;
	else
		cout << "No Successor";
	return 0;
}
//this code is contributed by Harsh Raghav
