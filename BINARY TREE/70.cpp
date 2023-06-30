// C++ program to find averages of all levels
// in a binary tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node {
	int data;
	struct Node* left, *right;
};

string inorder(Node* node, unordered_map<string, int>& m)
{
	if (!node)
		return "";

	string str = "(";
	str += inorder(node->left, m);
	str += to_string(node->data);
	str += inorder(node->right, m);
	str += ")";

	// Subtree already present (Note that we use
	// unordered_map instead of unordered_set
	// because we want to print multiple duplicates
	// only once, consider example of 4 in above
	// subtree, it should be printed only once.
	if (m[str] == 1)
		cout << node->data << " ";

	m[str]++;

	return str;
}

// Wrapper over inorder()
void printAllDups(Node* root)
{
	unordered_map<string, int> m;
	inorder(root, m);
}

/* Helper function that allocates a
new node with the given data and
NULL left and right pointers. */
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver code
int main()
{
	Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(2);
	root->right->left->left = newNode(4);
	root->right->right = newNode(4);
	printAllDups(root);
	return 0;
}










/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N ^ 2)

    Where 'N' is the number of nodes in a binary tree.
*/

#include <unordered_map>
#include <string>

string duplicateSubtreesHelper(TreeNode<int> *root, unordered_map<string, int> &store, vector<int> &result)
{
    //    If root is NULL then return an empty string.
    if (root == NULL)
    {
        return "";
    }

    //    We enclose the string into paranthesis.
    string str = "(";
    
    //    Traverse for the left subtree.
    str.append(duplicateSubtreesHelper(root->left, store, result));

    //    Convert the integer data to string.
    str.append(to_string(root->data));

    //    Traverse for the right subtree.
    str.append(duplicateSubtreesHelper(root->right, store, result));
    
    str.append(")");

    //    If subtree is already present then add that data to our final result.
    if (store[str] == 1)
    {
        result.push_back(root->data);
    }    

    //    Increment the occurence of current string in the HashMap.
    store[str]++;

    return str;
}

vector<int> duplicateSubtrees(TreeNode<int> *root)
{
    //    Declare a HashMap.
    unordered_map<string, int> store;

    //    Stores the final result.
    vector<int> result;

    //    Call the helper function.
    duplicateSubtreesHelper(root, store, result);

    //    If no duplicate subtrees are present then return -1.
    if (result.size() == 0)
    {
        result.push_back(-1);
    }

    return result;
}