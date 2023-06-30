#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

// A simple function to print leaf nodes of a binary tree
void printLeaves(Node* root)
{
    if (root == nullptr)
        return;

    printLeaves(root->left);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        cout << root->data << " ";

    printLeaves(root->right);
}

// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root)
{
    if (root == nullptr)
        return;

    if (root->left) {

        // to ensure top down order, print the node
        // before calling itself for left subtree
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root)
{
    if (root == nullptr)
        return;

    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary
// tree
void printBoundary(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";

    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);

    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);

    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}












#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

bool isLeaf(Node* node){
  if(node->left == NULL && node->right==NULL){
    return true;
  }
  return false;
}

void addLeftBound(Node * root, vector<int>& ans){
  //Go left left and no left then right but again check from left
  root = root->left;
  while(root!=NULL){
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left !=NULL) root = root->left;
    else root = root->right;
  }
}

void addRightBound(Node * root, vector<int>& ans){
  //Go right right and no right then left but again check from right
  root = root->right;
  //As we need the reverse of this for Anticlockwise
  stack<int> stk;
  while(root!=NULL){
    if(!isLeaf(root)) stk.push(root->data);
    if(root->right !=NULL) root = root->right;
    else root = root->left;
  }
  while(!stk.empty()){
    ans.push_back(stk.top());
    stk.pop();
  }
}

//its kind of inorder
void addLeaves(Node * root, vector<int>& ans){
  if(root==NULL){
    return;
  }
  if(isLeaf(root)){
    ans.push_back(root->data); //just store leaf nodes
    return;
  }
  addLeaves(root->left,ans);
  addLeaves(root->right,ans);
}

vector <int> boundary(Node *root)
{
  //Your code here
  vector<int> ans;
  if(root==NULL) return ans;
  if(!isLeaf(root)) ans.push_back(root->data); // if leaf then its done by addLeaf
  addLeftBound(root,ans);
  addLeaves(root,ans);
  addRightBound(root,ans);

  return ans;

}

int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    vector<int>ans = boundary(root);
      for(int v : ans){
        cout<<v<<" ";
    }
      cout<<"\n";
 
    return 0;
}