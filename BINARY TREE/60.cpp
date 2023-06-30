/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************
// serialisation + hashing (one time traversal)

#include<bits/stdc++.h>
string helper(BinaryTreeNode<char> *root,unordered_set<string>& set)
{
    if(root==NULL)
        return "#";
    string left = helper(root->left,set);
    if(left=="")
        return "";
    string right = helper(root->right,set);
    if(right=="")
        return "";
    string s;
    s.push_back(root->data);
    s = s+left+right;
    if(s.size()>3&&set.find(s)!=set.end())
    {
        return "";
    }
    set.insert(s);
    return s;
}
bool similarSubtree(BinaryTreeNode<char> *root)
{
    unordered_set<string> set;
    string s;
    string ans = helper(root,set);
    if(ans=="")
        return true;
    return false;
}

*/

// C++ program to find if there is a duplicate
// sub-tree of size 2 or more.
#include<bits/stdc++.h>
using namespace std;

// Separator node
const char MARKER = '$';

// Structure for a binary tree node
struct Node
{
	char key;
	Node *left, *right;
};

// A utility function to create a new node
Node* newNode(char key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

unordered_set<string> subtrees;

// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node *root)
{
	string s = "";

	// If current node is NULL, return marker
	if (root == NULL)
		return s + MARKER;

	// If left subtree has a duplicate subtree.
	string lStr = dupSubUtil(root->left);
	if (lStr.compare(s) == 0)
	return s;

	// Do same for right subtree
	string rStr = dupSubUtil(root->right);
	if (rStr.compare(s) == 0)
	return s;

	// Serialize current subtree
	s = s + root->key + lStr + rStr;

	// If current subtree already exists in hash
	// table. [Note that size of a serialized tree
	// with single node is 3 as it has two marker
	// nodes.
	if (s.length() > 3 &&
		subtrees.find(s) != subtrees.end())
	return "";

	subtrees.insert(s);

	return s;
}

// Driver program to test above functions
int main()
{
	Node *root = newNode('A');
	root->left = newNode('B');
	root->right = newNode('C');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right->right = newNode('B');
	root->right->right->right = newNode('E');
	root->right->right->left= newNode('D');

	string str = dupSubUtil(root);

	(str.compare("") == 0) ? cout << " Yes ":
							cout << " No " ;
	return 0;
}
