/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    where N is the number of nodes in the BST.

*/

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    if (root == NULL){
        return NULL;
    }

    if (key < root -> data){
        root -> left = deleteNode(root -> left, key);
    }

    else if (key > root -> data){
        root -> right = deleteNode(root -> right, key);
    }

    else{

        // Leaf node.
        if (root -> left == NULL && root -> right == NULL){
            return NULL;
        }

        if (root -> left == NULL){
            // Node doesn't have a left subtree.
            return root -> right;
        }

        if (root -> right == NULL){
            // Node doesn't have a right subtree.
            return root -> left;
        }


        // Find the minimum value in the right Subtree(successor).
        BinaryTreeNode<int>* rightSubtree = root -> right;

        while (rightSubtree -> left != NULL){
            rightSubtree = rightSubtree -> left;
        }

        root -> data = rightSubtree -> data;

        // Delete the inorder successor.
        root -> right = deleteNode(root -> right, rightSubtree -> data);
    }

    return root;
}




































class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* iter = root, *par = nullptr;
		// search for key node & keep a pointer to current node's parent
        while(iter && iter -> val != key) {                              
            par = iter;
            if(iter -> val < key) iter = iter -> right;
            else iter = iter -> left;
        }
        if(!iter) return root;                                           // node not found  => Case:1
        // iter is the node to be deleted
        
        // node found with less than two children  => Case-2/3/4 combined
        if(!iter -> left or !iter -> right) {
            auto child = iter -> left ? iter -> left : iter -> right;    // find child node of iter if it exists
            if(!par) root = child;                                       // iter is root node. Update root as child of iter
            else if(par -> left == iter) par -> left = child;            // iter is left child. Update its parent's left pointer as iter's child
            else par -> right = child;                                   // Else update parent's right pointer as iter's child
        }
        // node found with both children => Case-5
        else {
            auto cur = iter;                                              // cur maintains a reference to the node to be deleted
            par = iter, iter = iter -> right;                             // go to right subtree 
            while(iter -> left) par = iter, iter = iter -> left;          // and find smallest node in that right subtree
            cur -> val = iter -> val;                                     // delete by replacing with smallest node found
			// smallest node replaced from right subtree may have a right child. 
			// So update that node's parent to hold the right child
            if(par -> left == iter) par -> left = iter -> right;          
            else par -> right = iter -> right;
        }
		// dont show the interviewer that you are a leaker :)
        delete iter;        // free the memory		
        return root;
    }
};