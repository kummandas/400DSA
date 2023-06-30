/*/*
    Time Complexity - O(N)
    Space Complexity - O(H)

    Where N is the total number of nodes in the tree and H is the height of the tree.


#include<algorithm>
#include<queue>
#include<limits.h>

bool isDeadEndUtil(TreeNode<int>* root, int minimum, int maximum) {
	if(root == NULL){
        return false;
    }

    if(root->left == NULL && root->right == NULL){
        if(minimum == maximum){
            return true;
        }
        return false;
    }

    return isDeadEndUtil(root->left, minimum, min(root->data - 1, maximum))
    || isDeadEndUtil(root->right, max(root->data + 1, minimum), maximum);
}

bool isDeadEnd(TreeNode<int>* root) {
    if(root == NULL){
        return false;
    }

    int minimum = 1, maximum = INT_MAX;

    // Call the util function.
    return isDeadEndUtil(root, minimum, maximum);
}*/