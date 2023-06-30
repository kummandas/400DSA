// 3 methods (REC,REC+MEM,TAB) in C++

// Recurrance Relation --> nCr = (n-1)C(r-1) + (n-1)Cr
/*
#define MOD 1000000007
class Solution{
    int solveRec(int n,int r){
        // BASE CASE
        if(n==r) return 1;
        if(r==1) return n;
        return ((solveRec(n-1,r-1)%MOD)+(solveRec(n-1,r))%MOD)%MOD;
    }
    
    int solve(int n,int r,vector<vector<int>> &dp){
        // BASE CASE
        if(n==r) return 1;
        if(r==1) return n;
        if(dp[n][r]!=-1) return dp[n][r];
        dp[n][r] = ((solve(n-1,r-1,dp)%MOD)+(solve(n-1,r,dp))%MOD)%MOD;
        return dp[n][r];
    }
    
    int tab(int n,int r){
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        for(int i=1;i<=r;i++)
            dp[i][i] = 1;
        for(int i = 1;i<=n;i++)
          dp[i][1] = i;
        for(int i = 1;i<=n;i++){
            for(int j = 2;j<=r;j++){
                dp[i][j] = ((dp[i-1][j-1]%MOD)+(dp[i-1][j]%MOD))%MOD;
            }
        }
        return dp[n][r];
    }
    
public:
    int nCr(int n, int r){
        if(r>n) return 0;
        
        // Only Recursin
        // return solveRec(n,r);
        
        // Rec + Memoization
        // vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        // return solve(n,r,dp);
        
        // Tabulation
        return tab(n,r);
    }
};
*/

// C++ program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
	int C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (int i = 1; i <= n; i++)
	{
	
		// Compute next row of pascal triangle using
		// the previous row
		for (int j = min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
	return C[k];
}

/* Driver code*/
int main()
{
	int n = 5, k = 2;
	cout << "Value of C(" << n << "," << k << ")"<< "is " <<binomialCoeff(n, k);
	return 0;
}

// This code is contributed by shivanisinghss2110
