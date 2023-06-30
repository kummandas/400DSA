/* C++ Program to find LCA of n1 and n2 using one traversal
* of Binary Tree */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function returns pointer to LCA of two given values
// n1 and n2. This function assumes that n1 and n2 are
// present in Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with root's key, report
	// the presence by returning root (Note that if a key is
	// ancestor of other, then the ancestor key becomes LCA
	if (root->key == n1 || root->key == n2)
		return root;

	// Look for keys in left and right subtrees
	Node* left_lca = findLCA(root->left, n1, n2);
	Node* right_lca = findLCA(root->right, n1, n2);

	// If both of the above calls return Non-NULL, then one
	// key is present in once subtree and other is present
	// in other, So this node is the LCA
	if (left_lca && right_lca)
		return root;

	// Otherwise check if left subtree or right subtree is
	// LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in the above example
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)















Create a hash table or a map to store the parent pointers of each node in the binary tree.
Traverse the binary tree and populate the hash table or the map with the parent pointers for each node.
Starting from the first node, traverse up the tree and add each ancestor to a set or a list.
Starting from the second node, traverse up the tree and check if each ancestor is already in the set or the list. The first ancestor that is already in the set or the list is the lowest common ancestor.
If no common ancestor is found, return null or any other value that indicates the absence of a common ancestor.
Below is the implementation for the above approach:


// C++ code to implement above approach
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
 
using namespace std;
 
// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
// Function to create a new binary tree node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 
// Function to build a hash table or a map of parent
// pointers for each node in the tree
unordered_map<Node*, Node*> buildParentMap(Node* root)
{
    unordered_map<Node*, Node*> parentMap;
    parentMap[root] = NULL;
    vector<Node*> queue = { root };
    while (!queue.empty()) {
        Node* node = queue.front();
        queue.erase(queue.begin());
        if (node->left) {
            parentMap[node->left] = node;
            queue.push_back(node->left);
        }
        if (node->right) {
            parentMap[node->right] = node;
            queue.push_back(node->right);
        }
    }
    return parentMap;
}
 
// Function to find the lowest common ancestor of two nodes
// using an auxiliary data structure
int findLCA(Node* root, int n1, int n2)
{
    // Build a hash table or a map of parent pointers for
    // each node in the tree
    unordered_map<Node*, Node*> parentMap
        = buildParentMap(root);
 
    // Find the nodes with values n1 and n2
    Node* p = NULL;
    Node* q = NULL;
    vector<Node*> queue = { root };
    while (!queue.empty()) {
        Node* node = queue.front();
        queue.erase(queue.begin());
        if (node->data == n1) {
            p = node;
        }
        if (node->data == n2) {
            q = node;
        }
        if (node->left) {
            queue.push_back(node->left);
        }
        if (node->right) {
            queue.push_back(node->right);
        }
    }
 
    // Add all the ancestors of the first node to a set or a
    // list
    set<Node*> ancestors;
    while (p) {
        ancestors.insert(p);
        p = parentMap[p];
    }
 
    // Traverse up from the second node and check if each
    // ancestor is already in the set or the list
    while (q) {
        if (ancestors.find(q) != ancestors.end()) {
            return q
                ->data; // The first ancestor that is
                        // already in the set or the list is
                        // the lowest common ancestor
        }
        q = parentMap[q];
    }
 
    return -1; // No common ancestor found
}
 
// Driver code
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << endl;
    cout << "LCA(3,4) = " << findLCA(root, 3, 4) << endl;
    cout << "LCA(2, 4) = " << findLCA(root, 2, 4) << endl;
 
    return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
Output
LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(3,4) = 1
LCA(2, 4) = 2
Time Complexity: O(n),

The time complexity of the given code is O(n), where n is the number of nodes in the binary tree.

Building the parent map for each node in the tree requires visiting each node once, which takes O(n) time. Finding the nodes with values n1 and n2 requires visiting each node once, which also takes O(n) time. Traversing up from the second node and checking if each ancestor is already in the set or the list takes O(h) time, where h is the height of the binary tree.

In the worst case, the height of the binary tree is O(n), if the binary tree is skewed. Therefore, the overall time complexity of the given code is O(n) + O(n) + O(n) = O(n).

Space Complexity: O(n),

The space complexity of the given code is O(n) in the worst case. This is because the size of the parent map built for each node in the tree is O(n). Additionally, the set of ancestors can also contain all the nodes in the binary tree in the worst case, which also takes O(n) space. Finally, the queue used for traversing the binary tree takes O(n) space. Therefore, the overall space complexity of the given code is O(n) + O(n) + O(n) = O(n).