// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
and left and right pointers */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* This is the core function to convert
Tree to list. This function follows
steps 1 and 2 of the above algorithm */
node* bintree2listUtil(node* root)
{
	// Base case
	if (root == NULL)
		return root;

	// Convert the left subtree and link to root
	if (root->left != NULL) {
		// Convert the left subtree
		node* left = bintree2listUtil(root->left);

		// Find inorder predecessor. After this loop, left
		// will point to the inorder predecessor
		for (; left->right != NULL; left = left->right)
			;

		// Make root as next of the predecessor
		left->right = root;

		// Make predecessor as previous of root
		root->left = left;
	}

	// Convert the right subtree and link to root
	if (root->right != NULL) {
		// Convert the right subtree
		node* right = bintree2listUtil(root->right);

		// Find inorder successor. After this loop, right
		// will point to the inorder successor
		for (; right->left != NULL; right = right->left)
			;

		// Make root as previous of successor
		right->left = root;

		// Make successor as next of root
		root->right = right;
	}

	return root;
}

// The main function that first calls
// bintree2listUtil(), then follows step 3
// of the above algorithm
node* bintree2list(node* root)
{
	// Base case
	if (root == NULL)
		return root;

	// Convert to DLL using bintree2listUtil()
	root = bintree2listUtil(root);

	// bintree2listUtil() returns root node of the converted
	// DLL. We need pointer to the leftmost node which is
	// head of the constructed DLL, so move to the leftmost
	// node
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->right;
	}
}

/* Driver code*/
int main()
{
	// Let us create the tree shown in above diagram
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node* head = bintree2list(root);

	// Print the converted list
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra









Inorder Traversal
The basic idea of this approach is to use the Inorder tree traversal technique to traverse from the leftmost node to the rightmost node and during the traversal maintain the DLL by converting subtree into the small doubly linked list.

 

We will use an additional function that performs inorder traversal on the tree

TreeNode<int>* inorderTraversal(TreeNode<int>* root, TreeNode<int>* &prev)
Where ‘ROOT’ is the root node of BST, and ‘PREV’ is the previously traversed node.

 

The steps are as follows:

In the ‘IN_ORDER_TRAVERSAL’ function
Check if ‘ROOT’ is ‘NULL’ then returns the root.
Create a pointer variable ‘HEAD’ of type TREE_NODE<int> that will point to the head of DLL.
As we must have to set this 'HEAD' to the leftmost node in the tree and so, we will make a recursive call to ROOT→LEFT until it reaches the leftmost child.
After that, we check if 'PREV' is ‘NULL’ which means we haven’t picked any node yet, then we set our ‘HEAD’ to the ‘ROOT’.
Else, all we have to do is to set 'ROOT' in the right of ‘PREV’ and ‘PREV’ in the left of 'ROOT'.
Now, we have to move towards other nodes in the tree and so, we set ‘PREV' to ‘ROOT'.
Make a recursive call for the right subtree.
Return the 'HEAD'.
In the given function
Create a pointer variable 'PREV' and set it to ‘NULL’.
Return the result obtained after calling IN_ORDER_TRAVERSAL(ROOT, PREV).
Time Complexity
O(N), where ‘N’ is the total number of nodes in BST.

 

Since we are just performing inorder traversal in which we will traverse each node exactly once and so, the overall time complexity will be O(N).

Space Complexity
O(N), where ‘N’ is the total number of nodes in BST.

 

Since the height of the recursion tree goes up to ‘N’ in the worst case (skewed tree) and so, the overall space complexity will be O(N).

Code
C++ (g++ 5.4)
/*
	Time complexity: O(N) 
	Space complexity: O(N)
	
	Where ‘N’ is the total number of nodes in BST.
*/

TreeNode<int> *inorderTraversal(TreeNode<int> *root, TreeNode<int> *&prev)
{
    // Check if root is NULL then return root itself.
    if (root == NULL)
    {
        return root;
    }

    // Call for the left subtree.
    TreeNode<int> *head = inorderTraversal(root->left, prev);

    // For the leftmost node, set head to the root.
    if (prev == NULL)
    {
        head = root;
    }

    // Else, add this root node to the DLL.
    else
    {
        prev->right = root;
        root->left = prev;
    }

    // Move "prev" to one node forward.
    prev = root;

    // Call for the right subtree.
    inorderTraversal(root->right, prev);

    // Return the head node.
    return head;
}

TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    return inorderTraversal(root, prev);
}