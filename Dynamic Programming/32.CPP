/*
    Time complexity: O(N * M)
    Space complexity: O(N * M)
    
    Where 'N' and 'M' are the lengths of the two strings.


int lcs(string &str1, string &str2){
    // Creating 'DP' table.
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));

    // Variable to store the answer.
    int ans = 0;

    // Iterate through first string.
    for (int i = 0; i <= str1.size(); i++){
        // Iterate through second string.
        for (int j = 0; j <= str2.size(); j++){
            // Make for first row and column of dp table make the value 0.
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }

            // If characters are same at 'i' and 'j' then add 1 to the answer obtained from rest of the string.
            else if (str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    // Return the answer.
    return ans;
}*/


/* Dynamic Programming solution to 
   find length of the
   longest common substring */
#include <iostream>
#include <string.h>
using namespace std;

/* Returns length of longest 
   common substring of X[0..m-1]
   and Y[0..n-1] */
int LCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store 
    // lengths of longest
    // common suffixes of substrings.   
    // Note that LCSuff[i][j] contains 
    // length of longest common suffix 
    // of X[0..i-1] and Y[0..j-1].

    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

// Driver code
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of Longest Common Substring is "
         << LCSubStr(X, Y, m, n);
    return 0;
}

















// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the
// longest LCS
int LCSubStr(string s, string t, int n, int m)
{
  
    // Create DP table
    int dp[2][m + 1];
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > res)
                    res = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    return res;
}

// Driver Code
int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";

    int m = X.length();
    int n = Y.length();

    cout << LCSubStr(X, Y, m, n);
    return 0;
    cout << "GFG!";
    return 0;
}

// This code is contributed by rajsanghavi9.