/* C++ program to construct a binary tree from
the given string */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
	if (si > ei)
		return -1;

	// Inbuilt stack
	stack<char> s;

	for (int i = si; i <= ei; i++) {

		// if open parenthesis, push it
		if (str[i] == '(')
			s.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// if stack is empty, this is
				// the required index
				if (s.empty())
					return i;
			}
		}
	}
	// if not found return -1
	return -1;
}

// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
	// Base case
	if (si > ei)
		return NULL;

	
	int num = 0;
	// In case the number is having more than 1 digit
	while(si <= ei && str[si] >= '0' && str[si] <= '9')
	{
	num *= 10;
	num += (str[si] - '0');
	si++;
	}

	// new root
	Node* root = newNode(num);
	int index = -1;

	// if next char is '(' find the index of
	// its complement ')'
	if (si <= ei && str[si] == '(')
		index = findIndex(str, si, ei);

	// if index found
	if (index != -1) {

		// call for left subtree
		root->left = treeFromString(str, si + 1, index - 1);

		// call for right subtree
		root->right
			= treeFromString(str, index + 2, ei - 1);
	}
	return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);
}
