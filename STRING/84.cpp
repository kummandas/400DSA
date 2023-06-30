/*
RECURSION (TLE)

class Solution {
public:
    bool f(int i,int j, string &s,string &p)
    {
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0)
        {
            while(j>=0)
            {
                if(p[j]=='*') j--;
                else return false;
            }
            return true;
        }
        
        if(s[i]==p[j] || p[j]=='?') return f(i-1,j-1,s,p);
        
        if(p[j]=='*')
        {
            return f(i-1,j,s,p) || f(i,j-1,s,p);
            //Two cases
            //Consider * as len=0
            //Give one charcter to * and remain at *
            //at next step it will again be decided from both these cases
        }
        return false;
        
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        return f(n-1,m-1,s,p);
    }
};
Memoization

class Solution {
public:
    int f(int i,int j, string &s,string &p,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=1;
        if(j==0 && i>0) return dp[i][j]=0;
        if(i==0 && j>0)
        {
            while(j>0)
            {
                if(p[j-1]=='*') j--;
                else return dp[i][j]=0;
            }
            return dp[i][j]=1;
        }
        
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp) ? 1:0;
            //Two cases
            //Consider * as len=0
            //Give one charcter to * and remain at *
            //at next step it will again be decided from both these cases
        }
        return dp[i][j]=0;
        
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};
Tabulation

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
Space Optimized

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        // vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        
        vector<bool> prev(m+1);
        //Initially prev is for n=0
        prev[0]=true;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            prev[i]=flag;
        }
        vector<bool> curr(m+1);
        
        
        for(int i=1;i<=n;i++)
        {
            curr[0]=false;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[j-1]=='*')
                    curr[j] = prev[j] || curr[j-1];
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};









bool isMatch(string s, string p) {
        int i=0, j=0, lsti=-1, lstj=-1;
        while(i<s.size())
        {
            if(j<p.size() && (s[i]==p[j] || p[j]=='?'))
            {
                i++;
                j++;
            }
            else if(j<p.size() && p[j]=='*')
            {
                j++;
                lsti = i;
                lstj = j;
            }
            else
            {
                if(lsti==-1)
                    return false;
                i = ++lsti;
                j = lstj;
            }
        }
        if(i<s.size())
            return false;
        while(j<p.size())
        {
            if(p[j]!='*')
                return false;
            j++;
        }
        return true;
    }
};

*/





// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input text
// with given wildcard pattern
bool strmatch(char txt[], char pat[],
			int n, int m)
{
	
	// empty pattern can only
	// match with empty string.
	// Base Case :
	if (m == 0)
		return (n == 0);

	// step-1 :
	// initialize markers :
	int i = 0, j = 0, index_txt = -1,
					index_pat = -1;

	while (i < n)
	{

		// For step - (2, 5)
		if (j < m && txt[i] == pat[j])
		{
			i++;
			j++;
		}

		// For step - (3)
		else if (j < m && pat[j] == '?')
		{
			i++;
			j++;
		}

		// For step - (4)
		else if (j < m && pat[j] == '*')
		{
			index_txt = i;
			index_pat = j;
			j++;
		}

		// For step - (5)
		else if (index_pat != -1)
		{
			j = index_pat + 1;
			i = index_txt + 1;
			index_txt++;
		}

		// For step - (6)
		else
		{
			return false;
		}
	}

	// For step - (7)
	while (j < m && pat[j] == '*')
	{
		j++;
	}

	// Final Check
	if (j == m)
	{
		return true;
	}

	return false;
}

// Driver code
int main()
{
	
	char str[] = "baaabab";
	char pattern[] = "*****ba*****ab";
	// char pattern[] = "ba*****ab";
	// char pattern[] = "ba*ab";
	// char pattern[] = "a*ab";

	if (strmatch(str, pattern,
				strlen(str), strlen(pattern)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	char pattern2[] = "a*****ab";
	if (strmatch(str, pattern2,
				strlen(str), strlen(pattern2)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
