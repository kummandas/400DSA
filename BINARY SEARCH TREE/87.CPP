/*//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int getCount(Node* root, int low, int high)
    {
    	if (!root) 
    	    return 0;
    
    	//if data at current node is equal to lower and upper range, we return 1.
    	if (root->data == high && root->data == low)
    		return 1;
    
    	//if data at current node is within range then we include it in count 
    	//and call function recursively for its left and right children.
    	if (root->data <= high && root->data >= low)
    		return 1+getCount(root->left,low,high)+getCount(root->right,low,high);
    
    	//else if data at current node is smaller than lower range then
    	//we call function recursively only for right child.
    	else if (root->data < low)
    		return getCount(root->right, low, high);
    
    	//else we call function recursively only for left child.
    	else return getCount(root->left, low, high);
    }
};*/











// C++ program to count BST nodes within a given range
#include<bits/stdc++.h>
using namespace std;

// A BST node
struct node
{
	int data;
	struct node* left, *right;
};

// Utility function to create new node
node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

// Returns count of nodes in BST in range [low, high]
int getCount(node *root, int low, int high)
{
	// Base case
	if (!root) return 0;

	// Special Optional case for improving efficiency
	if (root->data == high && root->data == low)
		return 1;

	// If current node is in range, then include it in count and
	// recur for left and right children of it
	if (root->data <= high && root->data >= low)
		return 1 + getCount(root->left, low, high) +
					getCount(root->right, low, high);

	// If current node is smaller than low, then recur for right
	// child
	else if (root->data < low)
		return getCount(root->right, low, high);

	// Else recur for left child
	else return getCount(root->left, low, high);
}

// Driver program
int main()
{
	// Let us construct the BST shown in the above figure
	node *root	 = newNode(10);
	root->left	 = newNode(5);
	root->right	 = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	/* Let us constructed BST shown in above example
		10
		/ \
	5	 50
	/	 / \
	1	 40 100 */
	int l = 5;
	int h = 45;
	cout << "Count of nodes between [" << l << ", " << h
		<< "] is " << getCount(root, l, h);
	return 0;
}











/*Preorder Traversal
The idea is to traverse all the nodes using preorder traversal and count the number of nodes which are in the given range.
We will initialize the variable Count with zero which we will use to keep count of all the nodes in the given range.
We will start the preorder traversal from the root node and repeat the following until we reach the null node.
If the current node is in the given range then we increase the Count by one.
Then we will call the preorder traversal of the left child and then right child.
We will return Count as answer.
For example given the following tree.
                    

                           

And the query is [ 2 , 9 ] .
We will initialize Count = 0 , call the preorder traversal of 5.
In preorder traversal of 5 we increase count by 1 as 2 <= 5 <= 9.
We call the preorder traversal of 3.
In preorder traversal of 3 the count remains unchanged.
Going back to 5.
We call the preorder traversal of 8.
In preorder traversal of 8 the count is increase by 1 ase 2 <= 8 <= 9.
We return back to 5.
We return back.
We return the count as the answer which is 2.
Time Complexity
O(N * Q) , where N is the number of nodes in the BST and Q is the number of queries.

Because for each query we are traversing through the whole tree in O(N) and we have Q queries.

Space Complexity
O( M ) , where M is the space of recursion stack. 

M would be equal to the height of the tree because at a time M nodes will be there in the recursion stack.

 

Code
C++ (g++ 5.4)
/*
        Time Complexity: O(N, Q)
        Space Complexity: O(M),

        where N is the number of nodes in the bst, Q is the number of queries 
        and M is the complexity of the recursion stack when we will do preorder traversal. 


// The countNodes variable will be used to keep the count of node with value in the given range.
int countNodes;
void preorderTraversal(BinaryTreeNode<int> *currentNode, int l, int r) {

    // Base case, if the node is null then reutrn back.
    if (currentNode == NULL) {
        return;
    }

    // If the value of the node is within the given range then increase the count by 1.
    if ((currentNode->data >= l) && (currentNode->data <= r)) {
        countNodes++;
    }

    // Call the preorder traversal of the left and right child.
    preorderTraversal(currentNode->left, l, r);
    preorderTraversal(currentNode->right, l, r);
}

vector<int> bstQueries(BinaryTreeNode<int> *root, int q, vector<pair<int, int>> queries) {
	
    // Initialize the answer vector where we will store the answers of all the queries.
    vector<int> answer;
    
    // Iterate through all the queries and for each query calculate the number of nodes withing the given range using preorder traversal.
    for (int i = 0; i < q; i++) {
        countNodes = 0;
        preorderTraversal(root, queries[i].first, queries[i].second);
        answer.push_back(countNodes);
    }

    // Return the answer vector.
    return answer;
}*/