/*
	Time complexity: O(N)
	Space complexity: O(N)

	Where 'N' denotes the number of nodes in the Binary tree.
*/

TreeNode<int>* buildTreeHelper(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inOrder, int inStart, int inEnd) 
{
	if (postStart > postEnd || inStart > inEnd) 
	{
		return NULL;
	}

    // Assign rootVal as postOrder[postEnd]
	int rootVal = postOrder[postEnd];
    
	TreeNode<int>* root = new TreeNode<int>(rootVal);

	// Find parent element index from inOrder array.
	int k = 0;
    
    // Iterate i from inStart to inEnd
    for (int i = inStart; i <= inEnd; i++) 
	{
		if (rootVal == inOrder[i]) 
		{
			k = i;
			break;
		}
	}

    // Create recursive call for left and right subtree
	root -> left = buildTreeHelper(postOrder, postStart, postStart + k - inStart - 1, inOrder, inStart, k - 1);
	root -> right = buildTreeHelper(postOrder, postStart + k - inStart, postEnd - 1, inOrder, k + 1, inEnd);

	return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int n = postOrder.size();

	int postStart = 0;
	int postEnd = n - 1;
	int inStart = 0;
	int inEnd = n - 1;

    // Call buildTreeHelper function 
	return buildTreeHelper(postOrder, postStart, postEnd, inOrder, inStart, inEnd);
}

