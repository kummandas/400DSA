class Solution {
public:
   int minChar(string str){ 
       // Write your code here
       int n = str.length();
       int left = 0;
       int right = n - 1;
       int added = 0;
       while (left < right) {
           // if left and right characters are same increase
           // left and decrease right pointer
           if (str[left] == str[right]) {
               left++;
               right--;
           }
           // else think of adding some characters at front and
           // start comparing the elements again
           else {
               left = 0;
               added = n - right;
               while (str[left] == str[right]) {
                   added--;
                   left++;81
               }
               right--;
           }
       }
       return added;
   }
};









// C++ program for getting minimum character to be
// added at front to make string palindrome
#include<bits/stdc++.h>
using namespace std;

// function for checking string is palindrome or not
bool ispalindrome(string s)
{
	int l = s.length();
	int j;
	
	for(int i = 0, j = l - 1; i <= j; i++, j--)
	{
		if(s[i] != s[j])
			return false;
	}
	return true;
}

// Driver code
int main()
{
	string s = "BABABAA";
	int cnt = 0;
	int flag = 0;
	
	while(s.length()>0)
	{
		// if string becomes palindrome then break
		if(ispalindrome(s))
		{
			flag = 1;
			break;
		}
		else
		{
		cnt++;
		
		// erase the last element of the string
		s.erase(s.begin() + s.length() - 1);
		}
	}
	
	// print the number of insertion at front
	if(flag)
		cout << cnt;
}
