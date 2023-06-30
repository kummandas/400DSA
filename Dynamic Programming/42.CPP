// Counts Palindromic Subsequence in a given String
#include <cstring>
#include <iostream>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str)
{
	int N = str.length();

	// create a 2D array to store the count of palindromic
	// subsequence
	int cps[N + 1][N + 1];
	memset(cps, 0, sizeof(cps));

	// palindromic subsequence of length 1
	for (int i = 0; i < N; i++)
		cps[i][i] = 1;

	// check subsequence of length L is palindrome or not
	for (int L = 2; L <= N; L++) {
		for (int i = 0; i <= N-L; i++) {
			int k = L + i - 1;
			if (str[i] == str[k])
				cps[i][k]
					= cps[i][k - 1] + cps[i + 1][k] + 1;
			else
				cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
							- cps[i + 1][k - 1];
		}
	}

	// return total palindromic subsequence
	return cps[0][N - 1];
}

// Driver program
int main()
{
	string str = "abcb";
	cout << "Total palindromic subsequence are : "
		<< countPS(str) << endl;
	return 0;
}










// C++ program to counts Palindromic Subsequence
// in a given String using recursion
#include <bits/stdc++.h>
using namespace std;

int n, dp[1000][1000];
string str = "abcb";

// Function return the total
// palindromic subsequence
int countPS(int i, int j)
{

	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == j)
		return dp[i][j] = 1;

	else if (str[i] == str[j])
		return dp[i][j]
			= countPS(i + 1, j) +
				countPS(i, j - 1) + 1;

	else
		return dp[i][j] = countPS(i + 1, j) +
						countPS(i, j - 1) -
						countPS(i + 1, j - 1);
}

// Driver code
int main()
{
	memset(dp, -1, sizeof(dp));
	n = str.size();
	cout << "Total palindromic subsequence are : "
		<< countPS(0, n - 1) << endl;
	return 0;
}
// this code is contributed by Kushdeep Mittal

'











/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

    where 'N' is the length of the string.
*/

int countPalindromicSubseq(string &s)
{
	int n = s.size();

	int const mod = 1e9 + 7;
	//    Dynamic programming matrix to store the number of palindromic subsequences.
	vector<vector<int>> dp(n, vector<int>(n, 0));

	//    Start traversing the given string.
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			//    Length of the current substring.
			int len = j - i + 1;

			if (len == 1)
			{
				//    Every single character in the string is a palindrome itself.
				dp[i][j] = 1;
			}
			else if (len == 2)
			{
				if (s[i] == s[j])
				{
					//    Each subsequence of current subtring will be palindrome.
					dp[i][j] = 3;
				}
				else
				{
					//    Two palindromes of single character.
					dp[i][j] = 2;
				}
			}
			else
			{
				if (s[i] == s[j])
				{
					dp[i][j] = (1 + dp[i + 1][j] + dp[i][j - 1]) % mod;
				}
				else
				{
					dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1] + mod) % mod;
				}
			}
		}
	}

	return dp[0][n - 1];
}'