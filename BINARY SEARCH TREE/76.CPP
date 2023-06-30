#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;

	/* Constructor that allocates
	a new node with the given data
	and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int isBSTUtil(node* node, int min, int max);

/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(node* node)
{
	return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
	/* an empty tree is BST */
	if (node == NULL)
		return 1;

	/* false if this node violates
	the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return isBSTUtil(node->left, min, node->data - 1)
		&& // Allow only distinct values
		isBSTUtil(node->right, node->data + 1,
					max); // Allow only distinct values
}

/* Driver code*/
int main()
{
	node* root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);

	// Function call
	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}

// This code is contributed by rathbhupendra


/*class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(struct Node* node)
    {
      return(isBSTUtil(node, INT_MIN, INT_MAX));
    }
    
    public:
    int isBSTUtil(struct Node* node, int min, int max)
    {
        //an empty tree is BST so we return true.
        if (node==NULL)
         return 1;
        
        //returning false if this node violates the min/max constraint.
        if (node->data < min || node->data > max)
         return 0;
        
        //otherwise checking the subtrees recursively.
        //tightening the min or max constraint.
        return
            isBSTUtil(node->left, min, node->data-1) &&  
            isBSTUtil(node->right, node->data+1, max); 
    }
};*/







// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool isBSTUtil(struct Node* root, Node*& prev)
{
	// traverse the tree in inorder fashion and
	// keep track of prev node
	if (root) {
		if (!isBSTUtil(root->left, prev))
			return false;

		// Allows only distinct valued nodes
		if (prev != NULL && root->data <= prev->data)
			return false;

		prev = root;

		return isBSTUtil(root->right, prev);
	}

	return true;
}

bool isBST(Node* root)
{
	Node* prev = NULL;
	return isBSTUtil(root, prev);
}

/* Driver code*/
int main()
{
	struct Node* root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);

	// Function call
	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}
