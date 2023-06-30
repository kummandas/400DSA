/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where 'N' is the total number of nodes in the binary tree.
*/

// Use answer to store traversal of nodes.
vector<int> answer;

void inOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    inOrder(node->left);

    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit right subtree.
    inOrder(node->right);
}

vector<int> getInOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call inOrder function and store inOrder traversal in answer array.
    inOrder(root);

    // Return answer.
    return answer;

}


void preOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }
    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit left subtree.
    preOrder(node->left);

    // Visit right subtree.
    preOrder(node->right);
}

vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call preOrder function and store preOrder traversal in answer array.
    preOrder(root);

    // Return answer.
    return answer;
}


void postOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    postOrder(node->left);

    // Visit right subtree.
    postOrder(node->right);

    // Add data of node to answer.
    answer.push_back(node->data);

}

vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call postOrder function and store postOrder traversal in answer array.
    postOrder(root);

    // Return answer.
    return answer;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result(3);

    // Call function to get inOrder Traversal.
    result[0] = getInOrderTraversal(root);

    // Call function to get preOrder Traversal.
    result[1] = getPreOrderTraversal(root);

    // Call function to get postOrder Traversal.
    result[2] = getPostOrderTraversal(root);

    // Return all 3 tree traversals.
    return result;
}








/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where 'N' is the total number of nodes in the binary tree.
*/

#include <stack>
#include <algorithm>

vector<int> getInOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // Create an empty stack.
    stack<BinaryTreeNode<int> *> s;

    // Initialize current node as 'ROOT'.
    BinaryTreeNode<int> *current = root;

    // Run a loop until 'CURRENT'!= NULL or stack is not empty.
    while (current != NULL || s.empty() == false)
    {
        while (current !=  NULL)
        {
            // Push current node to stack.
            s.push(current);

            // Move to left subtree of 'CURRENT'.
            current = current->left;
        }

        // 'CURRENT' must be NULL at this point.
        current = s.top();

        // Pop top node from stack.
        s.pop();

        // Add data of popped node to answer.
        answer.push_back(current->data);

		// Visit right subtree of current node.
        current = current->right;

    }

    return answer;

}


vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // Create an empty stack.
    stack<BinaryTreeNode<int>*> s;

    // Push 'ROOT' to stack.
    s.push(root);

    // Run a loop until stack is not empty.
    while (s.empty() == false) {

        // Get the top node from stack.
        BinaryTreeNode<int>* node = s.top();

        // Add data of top node to 'ANSWER'.
        answer.push_back(node->data);

        // Pop the top node.
        s.pop();

        // Push right subtree of node to stack.
        if (node->right) {
            s.push(node->right);
        }

        // Push left subtree of node to stack.
        if (node->left) {
            s.push(node->left);
        }
    }

    return answer;
}


vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root) {

    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL) {
        return answer;
    }

    // Create an empty stack.
    stack<BinaryTreeNode<int> *> s;
    BinaryTreeNode<int>* current = root;

    // Push current node to stack.
    s.push(current);


    // Run a loop until stack is not empty.
    while (!s.empty()) {

        // Pop a node from 'S'.
        current = s.top();
        s.pop();

        // Add data of popped node to 'ANSWER'.
        answer.push_back(current->data);

        // Push left child of current node  to stack.
        if (current->left) {
            s.push(current->left);
        }

        // Push right child of current node  to stack.
        if (current->right) {
            s.push(current->right);
        }
    }

    // Reverse all elements of 'ANSWER' array.
    reverse(answer.begin(), answer.end());

    return answer;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result(3);

    // Call function to get inOrder Traversal.
    result[0] = getInOrderTraversal(root);

    // Call function to get preOrder Traversal.
    result[1] = getPreOrderTraversal(root);

    // Call function to get postOrder Traversal.
    result[2] = getPostOrderTraversal(root);

    // Return all 3 tree traversals.
    return result;
}