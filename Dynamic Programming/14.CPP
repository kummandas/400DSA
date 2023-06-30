// A Naive recursive implementation of LCS problem

#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
		return max(lcs(X, Y, m, n - 1),
				lcs(X, Y, m - 1, n));
}

// Driver code
int main()
{
	string S1 = "AGGTAB";
	string S2 = "GXTXAYB";
	int m = S1.size();
	int n = S2.size();

	cout << "Length of LCS is " << lcs(S1, S2, m, n);

	return 0;
}

// This code is contributed by rathbhupendra







/* A Top-Down DP implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char* X, char* Y, int m, int n,
		vector<vector<int> >& dp)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
						lcs(X, Y, m - 1, n, dp));
}

/* Driver code */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
	cout << "Length of LCS is " << lcs(X, Y, m, n, dp);

	return 0;
}
his code is contributed by rathbhupendra




// Dynamic Programming C implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(string X, string Y, int m, int n)
{
	// Initializing a matrix of size (m+1)*(n+1)
	int L[m + 1][n + 1];

	// Following steps build L[m+1][n+1] in bottom up
	// fashion. Note that L[i][j] contains length of LCS of
	// X[0..i-1] and Y[0..j-1]
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1]
	// and Y[0..m-1]
	return L[m][n];
}

// Driver code
int main()
{
	string S1 = "AGGTAB";
	string S2 = "GXTXAYB";
	int m = S1.size();
	int n = S2.size();

	cout << "Length of LCS is " << lcs(S1, S2, m, n);

	return 0;
}
// code submitted by Aditya Yadav (adityayadav012552)
