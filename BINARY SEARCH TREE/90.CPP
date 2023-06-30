/*1

 Full Solution

//Back-end complete function template for C++

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node * post_order ( int pre[], int size )
    {
        if (canRepresentBST(pre, size) == false)
        {   cout << "NO";
            return NULL;
        }
    
        //creating a stack of capacity equal to size of array.
        Stack* stack = createStack( size );
    
        //first element of preorder traversal is always root of BST.
        Node* root = newNode( pre[0] );
    
        //pushing root into the stack.
        push( stack, root );
    
        int i;
        Node* temp;
    
        //iterating over rest of the array elements.
        for ( i = 1; i < size; ++i )
        {
            temp = NULL;
    
            //we keep on popping from stack while data at top of stack is less
            //than the current array element.
            while ( !isEmpty( stack ) && pre[i] > peek(stack)->data )
                temp = pop(stack);
    
            //we make this greater value as the right child and push it into stack.
            if ( temp != NULL)
            {
                temp->right = newNode( pre[i] );
                push( stack, temp->right );
            }
    
            //if current array element is less than data at top of stack, we make
            //it as the left child of the stack's top node and push it into stack.
            else
            {
                peek( stack )->left = newNode( pre[i] );
                push( stack, peek( stack )->left );
            }
        }
        return root;
         
    }
};*/




















// C++ program for finding postorder
// traversal of BST from preorder traversal
#include <bits/stdc++.h>
using namespace std;

// Function to find postorder traversal from
// preorder traversal.
void findPostOrderUtil(int pre[], int n, int minval,
					int maxval, int& preIndex)
{

	// If entire preorder array is traversed then
	// return as no more element is left to be
	// added to post order array.
	if (preIndex == n)
		return;

	// If array element does not lie in range specified,
	// then it is not part of current subtree.
	if (pre[preIndex] < minval || pre[preIndex] > maxval) {
		return;
	}

	// Store current value, to be printed later, after
	// printing left and right subtrees. Increment
	// preIndex to find left and right subtrees,
	// and pass this updated value to recursive calls.
	int val = pre[preIndex];
	preIndex++;

	// All elements with value between minval and val
	// lie in left subtree.
	findPostOrderUtil(pre, n, minval, val, preIndex);

	// All elements with value between val and maxval
	// lie in right subtree.
	findPostOrderUtil(pre, n, val, maxval, preIndex);

	cout << val << " ";
}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{

	// To store index of element to be
	// traversed next in preorder array.
	// This is passed by reference to
	// utility function.
	int preIndex = 0;

	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}

// Driver code
int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };

	int n = sizeof(pre) / sizeof(pre[0]);

	// Calling function
	findPostOrder(pre, n);
	return 0;
}
