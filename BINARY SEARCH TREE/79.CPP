TreeNode<int>* solve(vector<int> &arr, int &i, int bound){
    if(i == arr.size() || arr[i]>bound) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(arr[i++]);
    
    root->left = solve(arr, i, root->data);
    root->right = solve(arr, i, bound);
    
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    int bound = 100000;
    return solve(preOrder, i, bound);
}












// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key,
						int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	node* root = NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max) {
		// Allocate memory for root of this
		// subtree and increment *preIndex
		root = newNode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			// Construct the subtree under root
			// All nodes which are in range
			// {min .. key} will go in left
			// subtree, and first such node
			// will be root of left subtree.
			root->left = constructTreeUtil(pre, preIndex,
										pre[*preIndex],
										min, key, size);
		}
		if (*preIndex < size) {
			// All nodes which are in range
			// {key..max} will go in right
			// subtree, and first such node
			// will be root of right subtree.
			root->right = constructTreeUtil(pre, preIndex,
											pre[*preIndex],
											key, max, size);
		}
	}

	return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0],
							INT_MIN, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver code
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	// Function call
	node* root = constructTree(pre, size);

	printInorder(root);

	return 0;
}

// This code is contributed by rathbhupendra
















/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the tree.
*/

#include<climits>

TreeNode<int>* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){

    // If the preIndex is greater than the length of the array return NULL.
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    // If the current node lies inside the range then process the node.
    if (currNode > startRange && currNode < endRange){
        TreeNode<int>* root = new TreeNode<int>(currNode);

        // Increase the index by 1.
        preIndex += 1;

        // If left node exists process left.
        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
        // If right node exists process right.
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

        // Return the root.
        return root;
    }

    // If node was not processed return NULL.
    return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int preIndex = 0;

    // Return the util function.
    return util(preOrder, preIndex, INT_MIN, INT_MAX);
}