#include <iostream>
using namespace std;

// lcs with tabulation
int lcs(const string& s1, const string& s2)
{
	int m = s1.length(), n = s2.length();
	int db[n + 1] = {}; // db is initialized to all zeros

	// i and j are the length of s1 and s2
	for (int i = 1; i <= m; ++i) {
		int prev = db[0];
		for (int j = 1; j <= n; ++j) {
			int temp = db[j];
			if (s1[i - 1] == s2[j - 1])
				db[j] = 1 + prev;
			else
				db[j] = max(db[j - 1], db[j]);
			prev = temp;
		}
	}

	return db[n];
}

int main()
{
	string s1 = "AGGTAB", s2 = "GXTXAYB";
	int r = lcs(s1, s2);

	cout << "Length of LCS is " << lcs(s1, s2);
	return 0;
}






// Space optimized C++ implementation
// of LCS problem
#include<bits/stdc++.h>
using namespace std;

// Returns length of LCS
// for X[0..m-1], Y[0..n-1]
int lcs(string &X, string &Y)
{
	
	// Find lengths of two strings
	int m = X.length(), n = Y.length();

	int L[2][n + 1];

	// Binary index, used to
	// index current row and
	// previous row.
	bool bi;

	for (int i = 0; i <= m; i++)
	{
		
		// Compute current
		// binary index
		bi = i & 1;

		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[bi][j] = 0;

			else if (X[i-1] == Y[j-1])
				L[bi][j] = L[1 - bi][j - 1] + 1;

			else
				L[bi][j] = max(L[1 - bi][j],
							L[bi][j - 1]);
		}
	}

	// Last filled entry contains
	// length of LCS
	// for X[0..n-1] and Y[0..m-1]
	return L[bi][n];
}

// Driver code
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";

	printf("Length of LCS is %d\n", lcs(X, Y));

	return 0;
}
