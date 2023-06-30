

#include <bits/stdc++.h>
#include<vector> 
#include<iostream>

using namespace std;
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
    queue<TreeNode<int> *> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        // Currently number of element present in the queue denotes the size of the level
        int size = q.size();
        vector<int> store(size);
        //level process
        for(int i=0;i<size;i++){
            TreeNode<int> *node = q.front();
            q.pop();
            int index = leftToRight?i:size-i-1;
            store[index] = node->data;
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }   
        }
        // get the values from the level order
        for(int a:store){
            ans.push_back(a);
        }
//       change the direction
        leftToRight = !leftToRight;
    }
    
    return ans;
}