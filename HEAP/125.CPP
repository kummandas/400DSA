#include <iostream>

class Node {
public:
int data;
Node* left;
Node* right;
Node(int data) {
	this->data = data;
	left = NULL;
	right = NULL;
}
};

class IsBinaryTree_MaxHeap {
public:
bool isHeap(Node* tree) {
	bool result = true;

	// check if child is greater than parent
	if (tree != NULL && (tree->left != NULL && tree->left->data > tree->data) ||
		(tree->right != NULL && tree->right->data > tree->data)) {
	return false;
	}

	// check if left subtree has children but right is null
	if (tree->left != NULL) {
	if ((tree->left->left != NULL || tree->left->right != NULL) && tree->right == NULL) {
		return false;
	}
	}

	// check if right subtree has children and left is null
	if (tree->right != NULL) {
	if ((tree->right->left != NULL || tree->right->right != NULL) && tree->left == NULL) {
		return false;
	}
	}

	// check if right subtre has children but not left subtree
	if (tree->left != NULL) {
	if (tree->left->left == NULL && tree->left->right == NULL) {
		if (tree->right != NULL) {
		if (tree->right->left != NULL || tree->right->right != NULL) {
			return false;
		}
		}
	}
	}

	// recursively call for left and right subtree
	if (tree != NULL && tree->left != NULL) {
	bool l = isHeap(tree->left);
	result = result & l;
	}
	if (tree != NULL && tree->right != NULL) {
	bool r = isHeap(tree->right);
	result = result & r;
	}

	return result;
}
};

int main() {
IsBinaryTree_MaxHeap bt;

Node* root = new Node(10);
root->left = new Node(9);
root->right = new Node(8);
root->left->left = new Node(7);
root->left->right = new Node(6);
root->right->left = new Node(5);
root->right->right = new Node(4);
root->left->left->left = new Node(3);
root->left->left->right = new Node(2);
root->left->right->left = new Node(1);

if (bt.isHeap(root) == true)
	std::cout << "Given binary tree is a Heap" << std::endl;
else
	std::cout << "Given binary tree is not a Heap" << std::endl;

return 0;
}

// This code is contributed by vikramshirsath177.


/*/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is number of nodes in binary tree.


bool isBinaryHeapTree(BinaryTreeNode<int>* root)
{
    // List to store 'node, position'.
    vector<pair<BinaryTreeNode<int>*, int>> nodeArr;
    nodeArr.push_back(make_pair(root, 1));
    int i = 0;

    while (i < nodeArr.size())
    {
        BinaryTreeNode<int>* node = nodeArr[i].first;
        int position = nodeArr[i].second;
        i += 1;

        // If left child is not 'None'.
        if (node->left)
        {
            // Append left child.
            nodeArr.push_back(make_pair(node->left, 2 * position));

            /*
                Condition to check is value of 
                parent node is greater than it's left child.
            */
            if (node->left->data > node->data)
            {
                return false;
            }
        }

        // If right child is not 'None'.
        if (node->right)
        {
            // Append right child.
            nodeArr.push_back(make_pair(node->right, 2 * position + 1));

             /*
                Condition to check is value of 
                parent node is greater than it's right child.
            */
            if (node->right->data > node->data)
            {
                return false;
            }
        }
    }

    int lastIndex = nodeArr.size() - 1;

    return nodeArr[lastIndex].second == nodeArr.size();
}*/