/*Void helper(TreeNode<int>*root,int k,vector<int>&curr,int &ans) {
    if(!root) {
        return;
    }
    curr.push_back(root->data);
    int sum=0;
    for(int i=curr.size()-1;i>=0;i--) {
        sum+=curr[i];
        if(sum==k) {
            ans++;
        }
    }
    helper(root->left,k,curr,ans);
    helper(root->right,k,curr,ans);
    curr.pop_back();
}
int noWays(TreeNode<int>*root,int k) {
    vector<int>curr;
    int ans=0;
    helper(root,k,curr,ans);
    return ans;
}*/










// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;

// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// binary tree node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int>& path, int k)
{
	// empty node
	if (!root)
		return;

	// add current node to the path
	path.push_back(root->data);

	// check if there's any k sum path
	// in the left sub-tree.
	printKPathUtil(root->left, path, k);

	// check if there's any k sum path
	// in the right sub-tree.
	printKPathUtil(root->right, path, k);

	// check if there's any k sum path that
	// terminates at this node
	// Traverse the entire path as
	// there can be negative elements too
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];

		// If path sum is k, print the path
		if (f == k)
			printVector(path, j);
	}

	// Remove the current element from the path
	path.pop_back();
}

// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	printKPath(root, k);

	return 0;
}





















/*
	Time complexity: O(N) 
	Space complexity: O(N)
	
	Where ‘N’ is the number of nodes in the given binary tree.
*/

void helper(TreeNode < int > * root, int k, int prefix, int & totalCount, unordered_map < int, int > & count) {
    // Return, If root is NULL.
    if (!root) {
        return;
    }

    // Add root's data in prefix.
    prefix += root -> data;

    // Increment totalCount, If found new path with sum of nodes equal to k.
    totalCount += count[prefix - k];

    // Increment corresponding value of count that is having key as prefix.
    count[prefix]++;

    // Check for left and right child.
    helper(root -> left, k, prefix, totalCount, count);
    helper(root -> right, k, prefix, totalCount, count);

    /* 
        Decrement value of count[prefix] to avoid paths
        having left and right both children included.
    */
    count[prefix]--;
}

int noWays(TreeNode < int > * root, int k) {
    // Make un unordered map to store prefix sums.
    unordered_map < int, int > count;
    count[0] = 1;
    int totalCount = 0;

    helper(root, k, 0, totalCount, count);

    return totalCount;
}