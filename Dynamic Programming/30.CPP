// C++ program to find minimum cost to get exactly
// W Kg with given packets
#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

// cost[] initial cost array including unavailable packet
// W capacity of bag
int MinimumCost(int cost[], int n, int W)
{
	// val[] and wt[] arrays
	// val[] array to store cost of 'i' kg packet of orange
	// wt[] array weight of packet of orange
	vector<int> val, wt;

	// traverse the original cost[] array and skip
	// unavailable packets and make val[] and wt[]
	// array. size variable tells the available number
	// of distinct weighted packets
	int size = 0;
	for (int i=0; i<n; i++)
	{
		if (cost[i]!= -1)
		{
			val.push_back(cost[i]);
			wt.push_back(i+1);
			size++;
		}
	}

	n = size;
	int min_cost[n+1][W+1];

	// fill 0th row with infinity
	for (int i=0; i<=W; i++)
		min_cost[0][i] = INF;

	// fill 0'th column with 0
	for (int i=1; i<=n; i++)
		min_cost[i][0] = 0;

	// now check for each weight one by one and fill the
	// matrix according to the condition
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=W; j++)
		{
			// wt[i-1]>j means capacity of bag is
			// less than weight of item
			if (wt[i-1] > j)
				min_cost[i][j] = min_cost[i-1][j];

			// here we check we get minimum cost either
			// by including it or excluding it
			else
				min_cost[i][j] = min(min_cost[i-1][j],
					min_cost[i][j-wt[i-1]] + val[i-1]);
		}
	}

	// exactly weight W can not be made by given weights
	return (min_cost[n][W]==INF)? -1: min_cost[n][W];
}

// Driver program to run the test case
int main()
{
	int cost[] = {1, 2, 3, 4, 5}, W = 5;
	int n = sizeof(cost)/sizeof(cost[0]);

	cout << MinimumCost(cost, n, W);
	return 0;
}











// C++ program to find minimum cost to
// get exactly W Kg with given packets
#include<bits/stdc++.h>
using namespace std;

/* Returns the best obtainable price for
a rod of length n and price[] as prices
of different pieces */
int minCost(int cost[], int n)
{
int dp[n+1];
dp[0] = 0;

// Build the table val[] in bottom up
// manner and return the last entry
// from the table
for (int i = 1; i<=n; i++)
{
	int min_cost = INT_MAX;
	for (int j = 0; j < i; j++)
		if(cost[j]!=-1)
			min_cost = min(min_cost, cost[j] + dp[i-j-1]);
	dp[i] = min_cost;
}

return dp[n];
}

/* Driver code */
int main()
{
int cost[] = {20, 10, 4, 50, 100};
int W = sizeof(cost)/sizeof(cost[0]);
cout << minCost(cost, W);
return 0;
}
