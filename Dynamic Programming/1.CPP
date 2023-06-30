// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int count(int coins[], int n, int sum)
{

	// If sum is 0 then there is 1 solution
	// (do not include any coin)
	if (sum == 0)
		return 1;

	// If sum is less than 0 then no
	// solution exists
	if (sum < 0)
		return 0;

	// If there are no coins and sum
	// is greater than 0, then no
	// solution exist
	if (n <= 0)
		return 0;

	// count is sum of solutions (i)
	// including coins[n-1] (ii) excluding coins[n-1]
	return count(coins, n - 1, sum)
		+ count(coins, n, sum - coins[n - 1]);
}

// Driver code
int main()
{
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;

	cout << " " << count(coins, n, sum);

	return 0;
}

// This code is contributed by shivanisinghss2110



// C++ program for coin change problem

#include <bits/stdc++.h>

using namespace std;

int count(int coins[], int n, int sum)
{
	int i, j, x, y;

	// We need sum+1 rows as the table
	// is constructed in bottom up
	// manner using the base case 0
	// value case (sum = 0)
	int table[sum + 1][n];

	// Fill the entries for 0
	// value case (sum = 0)
	for (i = 0; i < n; i++)
		table[0][i] = 1;

	// Fill rest of the table entries
	// in bottom up manner
	for (i = 1; i < sum + 1; i++) {
		for (j = 0; j < n; j++) {
			// Count of solutions including coins[j]
			x = (i - coins[j] >= 0) ? table[i - coins[j]][j]
									: 0;

			// Count of solutions excluding coins[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[sum][n - 1];
}

// Driver Code
int main()
{
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;
	cout << count(coins, n, sum);
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)









#include <bits/stdc++.h>

using namespace std;

// This code is
int count(int coins[], int n, int sum)
{
	// table[i] will be storing the number of solutions for
	// value i. We need sum+1 rows as the table is
	// constructed in bottom up manner using the base case
	// (sum = 0)
	int table[sum + 1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	table[0] = 1;

	// Pick all coins one by one and update the table[]
	// values after the index greater than or equal to the
	// value of the picked coin
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= sum; j++)
			table[j] += table[j - coins[i]];
	return table[sum];
}

// Driver Code
int main()
{
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;
	cout << count(coins, n, sum);
	return 0;
}









#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int v, int n,
			vector<vector<int> >& dp)
{
	if (v == 0)
		return dp[n][v] = 1;
	if (n == 0)
		return 0;
	if (dp[n][v] != -1)
		return dp[n][v];
	if (a[n - 1] <= v) {
		// Either Pick this coin or not
		return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
						+ coinchange(a, v, n - 1, dp);
	}
	else // We have no option but to leave this coin
		return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int32_t main()
{
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		int n, v;
		n = 3, v = 4;
		vector<int> a = { 1, 2, 3 };
		vector<vector<int> > dp(n + 1,
								vector<int>(v + 1, -1));
		int res = coinchange(a, v, n, dp);
		cout << res << endl;
	}
}
// This Code is Contributed by
// Harshit Agrawal NITT













/*
    Time Complexity: O(N * V)
    Space Complexity: O(V)
    
    where N is the length of denominations array and V is the value.

*/

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Dp[i] will be storing the number of solutions for value i.
    long *dp = new long[value + 1]();
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = denominations[i]; j <= value; j++)
        {
            dp[j] += dp[j - denominations[i]];
        }
    }

    return dp[value];
}