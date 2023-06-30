/*#include<stack>
bool checkStringExpression(string str) {
// Write your code here.
   stack<char> s;
   
   int n=str.length();
   
   for(int i=0 ; i<n ; i++){
       char ch=str[i];
       
       if(ch == ')'){
           if(s.top() == '('){
               return true;
           }
           else{
               while(s.top() != '('){
                   s.pop();
               }
           }
           s.pop();
       }
       else{
           s.push(ch);
       }
   }
}*/








/* C++ Program to check whether valid
 expression is redundant or not
#include <bits/stdc++.h>
using namespace std;
 
// Function to check redundant brackets in a
// balanced expression
bool checkRedundancy(string& str)
{
    // create a stack of characters
    stack<char> st;
 
    // Iterate through the given expression
    for (auto& ch : str) {
 
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (!st.empty() and top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of stack
                top = st.top();
                st.pop();
            }
 
            // If operators not found
            if (flag == true)
                return true;
        }
 
        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
 
// Function to check redundant brackets
void findRedundant(string& str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 
// Driver code
int main()
{
    string str = "((a+b))";
    findRedundant(str);
    return 0;
}
*/




//C++ code to implement the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to check if the given character is an operator
// or not
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}
 
// Function to check if the given string contains redundant
// brackets or not
bool hasRedundantBrackets(string str)
{
    int n = str.length();
    int count = 0;
 
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            count++;
        }
        else if (str[i] == ')') {
            if (count <= 1) {
                return true;
            }
            else {
                count--;
                while (i < n - 1
                       && isOperator(str[i + 1])) {
                    i += 2;
                }
            }
        }
        else if (isOperator(str[i])) {
            continue;
        }
    }
 
    return false;
}
 
// Driver code
int main()
{
    string str = "((a+b))";
 
    if (hasRedundantBrackets(str)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
 
    return 0;
}
//This code is contributed by Veerendra_Singh_Rajpoot