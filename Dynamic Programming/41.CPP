/*#include <bits/stdc++.h> 
int solve(string &s){
     int n=s.size();
     vector<int>curr(n+1,0),next(n+1,0);
     for(int i=n-1;i>=0;i--){
         for(int j=i;j<n;j++){
             if(i==j){
                 curr[j]=1;
                continue;
             }                
            int ans=0;
            if(s[i]==s[j])
                ans=2+next[j-1];
            else{
                ans=max(curr[j-1],next[j]);
                }
            curr[j]=ans;
         }
         next=curr;
     }
    return next[n-1];
    
    }
int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    if(n<=1)
        return n;
    return solve(s);
}










#include <bits/stdc++.h> 
    int solve(int i,int j,string &s){
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        int ans=0;
        if(s[i]==s[j])
            ans=2+solve(i+1,j-1,s);
        else{
            ans=max(solve(i,j-1,s),solve(i+1,j,s));
        }
        return ans;
    }
int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    if(n<=1)
        return n;
    return solve(0,n-1,s);
}











#include <bits/stdc++.h> 
int solve(string &s){
     int n=s.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
     for(int i=n-1;i>=0;i--){
         for(int j=i;j<n;j++){
             if(i==j){
                 dp[i][j]=1;
                continue;
             }                
            int ans=0;
            if(s[i]==s[j])
                ans=2+dp[i+1][j-1];
            else{
                ans=max(dp[i][j-1],dp[i+1][j]);
                }
            dp[i][j]=ans;
         }
     }
    return dp[0][n-1];
    
    }
int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    if(n<=1)
        return n;
    return solve(s);
}













#include <bits/stdc++.h> 
int solve(string &s){
     int n=s.size();
     vector<int>curr(n+1,0),next(n+1,0);
     for(int i=n-1;i>=0;i--){
         for(int j=i;j<n;j++){
             if(i==j){
                 curr[j]=1;
                continue;
             }                
            int ans=0;
            if(s[i]==s[j])
                ans=2+next[j-1];
            else{
                ans=max(curr[j-1],next[j]);
                }
            curr[j]=ans;
         }
         next=curr;
     }
    return next[n-1];
    
    }
int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    if(n<=1)
        return n;
    return solve(s);
}










*/

// A Space optimized Dynamic Programming based C++
// program for LPS problem
#include <bits/stdc++.h>
using namespace std;

// Returns the length of the longest palindromic
// subsequence in str
int lps(string &s)
{
	int n = s.length();

	// a[i] is going to store length of longest
	// palindromic subsequence of substring s[0..i]
	int a[n];

	// Pick starting point
	for (int i = n - 1; i >= 0; i--) {

		int back_up = 0;
		

		// Pick ending points and see if s[i]
		// increases length of longest common
		// subsequence ending with s[j].
		for (int j = i; j < n; j++) {

			// similar to 2D array L[i][j] == 1
			// i.e., handling substrings of length
			// one.
			if (j == i)
				a[j] = 1;

			// Similar to 2D array L[i][j] = L[i+1][j-1]+2
			// i.e., handling case when corner characters
			// are same.
			else if (s[i] == s[j])
			{
				
				// value a[j] is depend upon previous
				// unupdated value of a[j-1] but in
				// previous loop value of a[j-1] is
				// changed. To store the unupdated
				// value of a[j-1] back_up variable
				// is used.
				int temp = a[j];
				a[j] = back_up + 2;
				back_up = temp;
			}

			// similar to 2D array L[i][j] = max(L[i][j-1],
			// a[i+1][j])
			else
			{
				back_up = a[j];
				a[j] = max(a[j - 1], a[j]);
			}
		}
	}
	
	return a[n - 1];
}

/* Driver program to test above functions */
int main()
{
	string str = "GEEKSFORGEEKS";
	cout << lps(str);
	return 0;
}







class Solution {
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1), dpPrev(n + 1);

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};