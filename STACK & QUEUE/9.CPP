// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {

        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find
        next greater for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

/* Driver code */
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}





/*#include<stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1; i>=0; i--){
            int curr = arr[i];
            
            while(!s.empty() && s.top() <= curr)
            s.pop();
            
            if(s.empty())
              ans[i] = -1;
            else
              ans[i] = s.top();
            
            s.push(curr);
        }
        return ans;
}*/






/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    where N is the number of elements in the array
*/

#include <stack>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Create a vetor to store next Greater elements
    vector<int> ans(n);

    // Stack, to keep track of next greater element
    stack<int> s;

    // Traverse in reverse fashion in the array
    for(int i = n - 1; i >= 0; i--)
    {
        //If current element is greater than or equal to stack's top 
        //element, we can pop it since now it will never get picked
        //as the next greater element
        while(!s.empty() && arr[i] >= s.top())
        {
             s.pop();
        }
        
        //If stack is not empty, stack's top element is 
        //the next greater element, else there is none
        if(!s.empty())
        {
            ans[i] = s.top();
        }
        else
        {
            ans[i] = -1;
        }

        // Push current element onto stack
        s.push(arr[i]);
    }

    // return final answer vector
    return ans;
}