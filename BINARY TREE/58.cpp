// C++ code to implement the above approach
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		: val(x)
		, left(NULL)
		, right(NULL)
	{
	}
};
// function to check if given binary tree is sumtree or not
bool isSumTree(TreeNode* root)
{
	// If root is NULL or it's a leaf node, return true
	if (root == NULL
		|| (root->left == NULL && root->right == NULL)) {
		return true;
	}

	// Create an empty queue and add the root node to it
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		// Remove the front node from the queue
		TreeNode* curr = q.front();
		q.pop();

		// If the node is a leaf node, continue
		if (curr->left == NULL && curr->right == NULL) {
			continue;
		}

		// Calculate the sum of the left and right subtrees
		int sum = 0;
		if (curr->left != NULL) {
			sum += curr->left->val;
			q.push(curr->left);
		}
		if (curr->right != NULL) {
			sum += curr->right->val;
			q.push(curr->right);
		}

		// If the sum of the left and right subtrees is not
		// equal to the value of the node, return false
		if (sum != curr->val) {
			return false;
		}
	}

	// If all nodes satisfy the sum tree property, return
	// true
	return true;
}
// Driver Code
int main()
{
	// Example usage
	TreeNode* root = new TreeNode(26);
	root->left = new TreeNode(10);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(6);
	root->right->right = new TreeNode(3);

	if (isSumTree(root)) {
		cout << "Given binary tree is a sum tree." << endl;
	}
	else {
		cout << "Given binary tree is not a sum tree."
			<< endl;
	}

	return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
