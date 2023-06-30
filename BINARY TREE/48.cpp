#include <bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	// data of the node
	int data;
	// horizontal distance of the node
	int hd;
	//left and right references
	Node * left, * right;
	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};


void printBottomView(Node * root)
{
	if(!root) return ;//if root is NULL
	unordered_map<int,int> hash; // <vertical_index , root->data>
	int leftmost = 0; // to store the leftmost index so that we move from left to right
	queue<pair<Node*,int>> q; // pair<Node*,vertical Index> for level order traversal.
	q.push({root,0}); // push the root and 0 vertial index
	while(!q.empty()){
		auto top = q.front(); // store q.front() in top variable
		q.pop();
		Node *temp = top.first; // store the Node in temp for left and right nodes
		int ind = top.second; // store the vertical index of current node
		hash[ind] = temp->data; // store the latest vertical_index(key) -> root->data(value)
		leftmost = min(ind,leftmost); // have the leftmost vertical index
		if(temp->left){ q.push({temp->left,ind-1});}// check if any node of left then go in negative direction
		if(temp->right){ q.push({temp->right,ind+1});} //check if any node of left then go in positive direction
	}
	//Traverse each value in hash from leftmost to positive side till key is available
	while(hash.find(leftmost)!=hash.end()){ cout<<hash[leftmost++]<<" "; }
}

int main()
{
	Node * root = new Node(20);
	root -> left = new Node(8);
	root -> right = new Node(22);
	root -> left -> left = new Node(5);
	root -> left -> right = new Node(3);
	root -> right -> left = new Node(4);
	root -> right -> right = new Node(25);
	root -> left -> right -> left = new Node(10);
	root -> left -> right -> right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	printBottomView(root);
	return 0;
}
