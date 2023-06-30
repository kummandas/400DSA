/*/*
    Time complexity: O(1)
        For push(): O(1) - Constant extra space is required.
        For pop(): O(1) - Constant extra space is required.
        For top(): O(1) - Constant extra space is required.
        For getMin(): O(1) - Constant extra space is required.
        For isEmpty(): O(1) - Constant extra space is required.

    Space complexity: O(1)


# include <stack>

class SpecialStack {
    stack<int> s;
    int minEle;

    public:

    void push(int data) {
        if(s.empty()) {
            s.push(data);
            minEle = data;
        }
        else {
            if(data >= minEle) {
                s.push(data);
            }
            else {
                s.push(2*data - minEle);
                minEle = data;
            }
        }
    }

    int pop() {
        if(s.empty()) {
            return -1;
        }
        
        int y = s.top();
        s.pop();
        
        if(y < minEle) {
            int popped = minEle;
            minEle = 2*minEle - y;
            return popped;
        }
        else {
            return y;
        }
    }

    int top() {
        if(s.empty()) {
            return -1;
        }

        int y = s.top();
        if(y < minEle) {
            return minEle;
        }
        else {
            return y;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }

        return minEle;
    }
};*/







#include <iostream>
#include <stdlib.h>
  
using namespace std;
  
/* A simple stack class with 
basic stack functionalities */
class Stack {
private:
    static const int max = 100;
    int arr[max];
    int top;
  
public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
};
  
/* Stack's member method to check 
if the stack is empty */
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}
  
/* Stack's member method to check 
if the stack is full */
bool Stack::isFull()
{
    if (top == max - 1)
        return true;
    return false;
}
  
/* Stack's member method to remove 
an element from it */
int Stack::pop()
{
    if (isEmpty()) {
        cout << "Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}
  
/* Stack's member method to insert 
an element to it */
void Stack::push(int x)
{
    if (isFull()) {
        cout << "Stack Overflow";
        abort();
    }
    top++;
    arr[top] = x;
}
  
/* A class that supports all the stack 
operations and one additional
  operation getMin() that returns the 
minimum element from stack at
  any time.  This class inherits from 
the stack class and uses an
  auxiliary stack that holds minimum 
elements */
class SpecialStack : public Stack {
    Stack min;
  
public:
    int pop();
    void push(int x);
    int getMin();
};
  
/* SpecialStack's member method to insert
 an element to it. This method
   makes sure that the min stack is also 
updated with appropriate minimum
   values */
void SpecialStack::push(int x)
{
    if (isEmpty() == true) {
        Stack::push(x);
        min.push(x);
    }
    else {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if (x < y)
            min.push(x);
        else
            min.push(y);
    }
}
  
/* SpecialStack's member method to 
remove an element from it. This method
   removes top element from min stack also. */
int SpecialStack::pop()
{
    int x = Stack::pop();
    min.pop();
    return x;
}
  
/* SpecialStack's member method to get
 minimum element from it. */
int SpecialStack::getMin()
{
    int x = min.pop();
    min.push(x);
    return x;
}
  
/* Driver program to test SpecialStack
 methods */
int main()
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin();
    return 0;
}



// ALL O(1)













/*
    Time complexity: O(1)
        For push(): O(1) - Constant extra space is required.
        For pop(): O(1) - Constant extra space is required.
        For top(): O(1) - Constant extra space is required.
        For getMin(): O(1) - Constant extra space is required.
        For isEmpty(): O(1) - Constant extra space is required.

    Space complexity: O(1)
*/

# include <stack>

class SpecialStack {
    stack<int> s1, s2;

    public:

    void push(int data) {
        if(s2.empty() || data <= s2.top())
        {
            s2.push(data);
        }
        s1.push(data);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        if(s1.top() == s2.top())
        {
            s2.pop();
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }

    int getMin() {
        if(isEmpty()) {
            return -1;
        }
        return s2.top();
    }
};