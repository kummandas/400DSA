/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in binary tree.
*/

int helperMethod(BinaryTreeNode<int>* root){

    // Base case.
    if(!root){
        return 0;
    }

    int leftValue = helperMethod(root->left);
    int rightValue = helperMethod(root->right);

    // If one of them is '-1' then child subtree are not balanced.
    if(leftValue == -1 or rightValue == -1){
        return -1;
    }

    // Allow only '0, -1, 1' height differencein 'left' child subtree height and 'right' subtree height.
    if(abs(leftValue-rightValue) <= 1){
        return max(leftValue, rightValue)+1;
    }

    // If left and right child subtree height more than '2'.
    return -1;
}

bool isBalancedBT(BinaryTreeNode<int>* root){

    // Base condition.
    if(!root){
        return true;
    }

    // If root tree is balanced.
    if (helperMethod(root) != -1){
        return true;
    }
    else{
        return false;
    }
}