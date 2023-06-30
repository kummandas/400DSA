/*class Solution
{
public:
    void populateNextRecur(Node *p, Node **next_ref)
    {
        if (p)
        {

            populateNextRecur(p->right, next_ref);

            p->next = *next_ref;

            *next_ref = p;

            populateNextRecur(p->left, next_ref);
        }
    }

    void populateNext(Node *root)
    {

        Node *next = NULL;

        populateNextRecur(root, &next);
    }
};*/




// C++ program to populate inorder
// traversal of all nodes
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* next;
};

/* Set next of p and all descendants of p
by traversing them in reverse Inorder */
void populateNext(node* p)
{
	// The first visited node will be the
	// rightmost node next of the rightmost
	// node will be NULL
	static node* next = NULL;

	if (p) {
		// First set the next pointer
		// in right subtree
		populateNext(p->right);

		// Set the next as previously visited
		// node in reverse Inorder
		p->next = next;

		// Change the prev for subsequent node
		next = p;

		// Finally, set the next pointer in
		// left subtree
		populateNext(p->left);
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	Node->next = NULL;

	return (Node);
}

// Driver Code
int main()
{

	/* Constructed binary tree is
			10
			/ \
		8 12
		/
	3
	*/
	node* root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(12);
	root->left->left = newnode(3);

	// Populates nextRight pointer in all nodes
	populateNext(root);

	// Let us see the populated values
	node* ptr = root->left->left;
	while (ptr) {
		// -1 is printed if there is no successor
		cout << "Next of " << ptr->data << " is "
			<< (ptr->next ? ptr->next->data : -1) << endl;
		ptr = ptr->next;
	}

	return 0;
}

// This code is contributed by rathbhupendra














/*
    Time Complexity : O(N)
    Space Complexity : O(1)
	
    Where 'N' is the number of nodes in the given binary tree.
*/

// Function to evaluate reverse inorder traversal of tree
TreeNode < int > * reverseInorder(TreeNode < int > * root) {

    // Check for left value
    if (!root -> left) {

        // if not found return root
        return root;
    }

    //recursively call function if left value found
    return reverseInorder(root -> left);
}

// Function to evaluate Inorder traversal
void inOrder(TreeNode < int > * root, TreeNode < int > * prev) {

    // If root is empty    
    if (!root) {

        //return empty
        return;
    }

    // if root has left value
    if (root -> right) {
        root -> next = reverseInorder(root -> right);
    } else {
        root -> next = prev;
    }

    //recursively call for left and right sides of tree
    inOrder(root -> right, prev);
    inOrder(root -> left, root);
}

void inorderSuccessor(TreeNode < int > * root) {

    // Recursively call function to find inorder traversal
    inOrder(root, nullptr);
}

































void inorder(TreeNode<int> *root, vector<TreeNode<int>*> &output)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, output);
    output.push_back(root);
    inorder(root->right, output);
}
void inorderSuccessor(TreeNode<int> *root)
{
	//    Write your code here
    if (root == NULL)
    {
        return ;
    }
    vector<TreeNode<int>*> output;
    inorder(root, output);
    int i;
    for(i=0;i<output.size()-1;i++){
        TreeNode<int>* node=output[i];
        TreeNode<int>* successor=output[i+1];
        node->next=successor;
    }
    output[i]->next=NULL;
}