#include <bits/stdc++.h> 
/*
int Recursion(vector<int> &weight, vector<int> &value, int index, int capacity){
	// base case
	if (index == 0){
		if (weight[0] <= capacity) return value[0];
		else return 0;
	}

	int include = 0;
	if (weight[index] <= capacity){
		include = value[index] + Recursion(weight, value, index-1, capacity-weight[index]);
	}

	int exclude = Recursion(weight, value, index-1, capacity);

	int ans = max(include, exclude);

	return ans;
}

int RecurMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
	// base case
	if (index == 0){
		if (weight[0] <= capacity) return value[0];
		else return 0;
	}

	if (dp[index][capacity] != -1) return dp[index][capacity];

	int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + RecurMemo(weight, value, index - 1, capacity-weight[index], dp);
    }

    int exclude = RecurMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int Tabulation(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<vector<int> > dp(n, vector<int>(capacity+1, 0));

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) dp[0][w] = value[0];
		else dp[0][w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=0; w<=capacity; w++){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + dp[index-1][w-weight[index]];
			}

			int exclude = 0 + dp[index-1][w];
			dp[index][w] = max(include, exclude);
		}
	}

	return dp[n-1][capacity];
}

int Space_Optimize(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) prev[w] = value[0];
		else prev[w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=0; w<=capacity; w++){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + prev[w-weight[index]];
			}

			int exclude = prev[w];
			curr[w] = max(include, exclude);
		}
		prev = curr;
	}

	return prev[capacity];
}

int Improved(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) curr[w] = value[0];
		else curr[w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=capacity; w>=0; w--){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + curr[w-weight[index]];
			}

			int exclude = curr[w];
			curr[w] = max(include, exclude);
		}
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Using Recursion
	// return Recursion(weight, value, n-1, maxWeight);

	// Using Recursion + Memoization
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return RecurMemo(weight, value, n-1, maxWeight, dp);
	
	// Using Tabulation
	// return Tabulation(weight, value, n, maxWeight);

	// Using Space_Optimize
	// return Space_Optimize(weight, value, n, maxWeight);
	
	// Using Further Improved solution - Only single array
	return (weight, value, n, maxWeight);
}
*/









// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {

		// Store the value of function call
		// stack in table before return
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i]
						+ knapSackRec(W - wt[i], wt, val,
										i - 1, dp),
					knapSackRec(W, wt, val, i - 1, dp));

		// Return value of table after storing
		return dp[i][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	// double pointer to declare the
	// table dynamically
	int** dp;
	dp = new int*[n];

	// loop to create the table dynamically
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];

	// loop to initially filled the
	// table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

// Driver Code
int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, weight, profit, n);
	return 0;
}
