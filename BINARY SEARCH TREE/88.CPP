/*#include <bits/stdc++.h> 
vector<int> leastGreaterElement(vector<int> &arr) 
{ 
    
    int n = arr.size();

    
    for (int i = 0; i < n; i++) 
    {
        
        int leastGreater = -1;

        
        for (int j = i + 1; j < n; j++)
        {
            
            if (arr[j] > arr[i]) 
            {
                
                if (leastGreater == -1) 
                {
                    leastGreater = arr[j];
                }
                else 
                {
                    leastGreater = min(leastGreater, arr[j]);
                }
            }
        }
        
     
        arr[i] = leastGreater;
    }  
    
    return arr;
}*/












/*Back-end complete function Template for C++

class Solution{
    public:
        vector<int> findLeastGreater(vector<int>& arr, int n) {
	        set<int> s;
	        vector<int> ans(arr.size());
        	for(int i=arr.size()-1;i>=0;i--) { //traversing the array backwards
        		s.insert(arr[i]); // inserting the element into set
        		auto it = s.upper_bound(arr[i]); // finding upper bound
        		if(it == s.end()) ans[i] = -1; // if upper_bound does not exist then -1
        		else ans[i] = *it; // if upper_bound exists, lets take it
	        }
	        return ans;
    }
};
*/














// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node {
	int data;
	Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with
given data in BST and find its successor */
Node* insert(Node* root, int val, int& suc)
{
	/* If the tree is empty, return a new node */
	if (!root)
		return newNode(val);
	// go to right subtree
	if (val >= root->data)
		root->right = insert(root->right, val, suc);
	// If key is smaller than root's key, go to left
	// subtree and set successor as current node
	else {
		suc = root->data;
		root->left = insert(root->left, val, suc);
	}
	return root;
}

// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
	Node* root = nullptr;
	// start from right to left
	for (int i = n - 1; i >= 0; i--) {
		int suc = -1;
		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], suc);
		arr[i] = suc;
	}
}

// Driver Program to test above functions
int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
				43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);
	replace(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
