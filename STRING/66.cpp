#include <bits/stdc++.h> 
#include<stack>
int findMinimumCost(string str) {
      
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
        else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
        int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
    
}











// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;

// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string s)
{
	int temp = 0, res = 0, n = s.size();
	if (n % 2 != 0)
		return -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			temp++;
		else {
			if (temp == 0) {
				res++;
				temp++;
			}
			else
				temp--;
		}
	}
	if (temp > 0)
		res += temp / 2;
	return res;
}

// Driver program to test above function
int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
	// This code is contributed by Akansha Mittal
}
