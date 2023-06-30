/*
    Time Complexity : O(N)
    Space Complexity: O(N)

    Where 'N' is the size of the given stack MY_STACK.      
*/

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
	// Base Case
	if (myStack.empty())
	{
		myStack.push(x);
		return myStack;
	}

	// Store top element in 'num'
	int num = myStack.top();

	// Pop the top element
	myStack.pop();

	// Recursive call
	pushAtBottom(myStack, x);

	// Add 'num' to stack
	myStack.push(num);

	return myStack;
}






#include <bits/stdc++.h>

// Function to push an element at the bottom of a stack
stack<int>pushAtBottom(stack<int>& myStack, int x)
{
    // Create a vector to store the elements of the stack
    vector<int>temp;

    // Pop all elements from the stack and store them in the vector
    while (!myStack.empty()) {
        int num = myStack.top();
        temp.push_back(num);
        myStack.pop();
    }

    // Push the new element at the bottom of the stack
    myStack.push(x);

    // Push all the elements back onto the stack, in the original order
    if (!temp.empty()) {
        for (int i = temp.size() - 1; i >= 0; i--) {
            myStack.push(temp[i]);
        }
    }

    // Return the modified stack
    return myStack;
}