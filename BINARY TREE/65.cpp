// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node {
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node* temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Declaration of methods
int sumOfGrandChildren(node* node,
					map<struct node*, int>& mp);
int getMaxSum(node* node);
int getMaxSumUtil(node* node, map<struct node*, int>& mp);

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node,
					map<struct node*, int>& mp)
{
	int sum = 0;

	// call for children of left child only if it is not
	// NULL
	if (node->left)
		sum += getMaxSumUtil(node->left->left, mp)






















			+ getMaxSumUtil(node->left->right, mp);

	// call for children of right child only if it is not
	// NULL
	if (node->right)
		sum += getMaxSumUtil(node->right->left, mp)
			+ getMaxSumUtil(node->right->right, mp);

	return sum;
}

// Utility method to return maximum sum rooted at node
// 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
	if (node == NULL)
		return 0;

	// If node is already processed then return calculated
	// value from map
	if (mp.find(node) != mp.end())
		return mp[node];

	// take current node value and call for all grand
	// children
	int incl = node->data + sumOfGrandChildren(node, mp);

	// don't take current node value and call for all
	// children
	int excl = getMaxSumUtil(node->left, mp)
			+ getMaxSumUtil(node->right, mp);

	// choose maximum from both above calls and store that
	// in map
	mp[node] = max(incl, excl);

	return mp[node];
}

// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
	if (node == NULL)
		return 0;
	map<struct node*, int> mp;
	return getMaxSumUtil(node, mp);
}

// Driver code
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSum(root) << endl;
	return 0;
}


// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
// declare map /dp array as global
unordered_map<Node*, int> umap;
int maxSum(Node* root)
{
	// base case
	if (!root)
		return 0;

	// if the max sum from the node is already in
	// map,return the value
	if (umap[root])
		return umap[root];

	// if the current node(root) is included in result
	// then find maximum sum
	int inc = root->data;

	// if left of node exists, add their grandchildren
	if (root->left) {
		inc += maxSum(root->left->left)
			+ maxSum(root->left->right);
	}
	// if right of node exist,add their grandchildren
	if (root->right) {
		inc += maxSum(root->right->left)
			+ maxSum(root->right->right);
	}

	// if the current node(root) is excluded, find the
	// maximum sum
	int ex = maxSum(root->left) + maxSum(root->right);

	// store the maximum of including & excluding the node
	// in map
	umap[root] = max(inc, ex);
	return max(inc, ex);
}

// Driver code
int main()
{
	Node* root = new Node(10);
	root->left = new Node(1);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->left->right = new Node(3);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(5);
	cout << maxSum(root);
	return 0;
}
vvv

















// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
// declare map /dp array as global
unordered_map<Node*, int> umap;
int maxSum(Node* root)
{
	// base case
	if (!root)
		return 0;

	// if the max sum from the node is already in
	// map,return the value
	if (umap[root])
		return umap[root];

	// if the current node(root) is included in result
	// then find maximum sum
	int inc = root->data;

	// if left of node exists, add their grandchildren
	if (root->left) {
		inc += maxSum(root->left->left)
			+ maxSum(root->left->right);
	}
	// if right of node exist,add their grandchildren
	if (root->right) {
		inc += maxSum(root->right->left)
			+ maxSum(root->right->right);
	}

	// if the current node(root) is excluded, find the
	// maximum sum
	int ex = maxSum(root->left) + maxSum(root->right);

	// store the maximum of including & excluding the node
	// in map
	umap[root] = max(inc, ex);
	return max(inc, ex);
}

// Driver code
int main()
{
	Node* root = new Node(10);
	root->left = new Node(1);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->left->right = new Node(3);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(5);
	cout << maxSum(root);
	return 0;
}



















// C++ program to find maximum sum from a subset of
// non-adjacent nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct Node {
	int data;
	struct Node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct Node* newNode(int data)
{
	struct Node* temp = new struct Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Declaration of the vector to store the answer
vector<vector<int> > dp;

// Variables and function to index the given Binary tree
// This indexing will be used in dp
int cnt = 0;
Node* temp;
Node* giveIndex(Node* root)
{
	if (root == NULL)
		return NULL;
	// give the index to the current node and increment the
	// index for next nodes.
	Node* newNode1 = newNode(cnt++);

	// Recursively calling right and left subtree
	newNode1->left = giveIndex(root->left);
	newNode1->right = giveIndex(root->right);
	return newNode1;
}

// Memoization function to store the answer
int solve(Node* root, int b, Node* temp)
{
	if (root == NULL)
		return 0;
	// If the answer is already calculated return that
	// answer
	if (dp[temp->data][b] != -1)
		return dp[temp->data][b];

	// Variable to store the answer for the current node.
	int res;

	// if the parent is not selected then we can either
	// select ot not select this node.
	if (b == 0)
		res = max(root->data
					+ solve(root->right, 1, temp->right)
					+ solve(root->left, 1, temp->left),
				solve(root->right, 0, temp->right)
					+ solve(root->left, 0, temp->left));

	// If parent is selected then we can't select this node.
	else
		res = solve(root->right, 0, temp->right)
			+ solve(root->left, 0, temp->left);

	// return the answer
	return dp[temp->data][b] = res;
}
int getMaxSum(Node* root)
{
	// Initialization of the dp
	dp = vector<vector<int> >(100, vector<int>(2, -1));
	// Calling the indexing function
	temp = giveIndex(root);
	// calling the solve function for root with parent not
	// selected
	int res = solve(root, 0, temp);

	return res;
}

// Driver code to test above methods
int main()
{
	// TEST 1
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);
	cout << getMaxSum(root) << endl;

	// TEST 2
	Node* root2 = newNode(10);
	root2->left = newNode(1);
	root2->left->left = newNode(2);
	root2->left->left->left = newNode(1);
	root2->left->right = newNode(3);
	root2->left->right->left = newNode(4);
	root2->left->right->right = newNode(5);
	cout << getMaxSum(root2);

	return 0;
}
// Code contributed by Anirudh Singh.
