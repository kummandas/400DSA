/* A Naive recursive implementation of
unbounded Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int unboundedKnapsack(int W, int wt[], int val[], int idx)
{

	// Base Case
	// if we are at idx 0.
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	// There are two cases either take element or not take.
	// If not take then
	int notTake
		= 0 + unboundedKnapsack(W, wt, val, idx - 1);
	// if take then weight = W-wt[idx] and index will remain
	// same.
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx);
	}
	return max(take, notTake);
}

// Driver code
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);

	cout << unboundedKnapsack(W, wt, val, n - 1);
	return 0;
}
// This code is contributed by Sanskar.







/* A Naive recursive implementation of
unbounded Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int unboundedKnapsack(int W, int wt[], int val[], int idx,
					vector<vector<int> >& dp)
{

	// Base Case
	// if we are at idx 0.
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	// If the value is already calculated then we will
	// previous calculated value
	if (dp[idx][W] != -1)
		return dp[idx][W];
	// There are two cases either take element or not take.
	// If not take then

	int notTake
		= 0 + unboundedKnapsack(W, wt, val, idx - 1, dp);
	// if take then weight = W-wt[idx] and index will remain
	// same.
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx, dp);
	}
	return dp[idx][W] = max(take, notTake);
}

// Driver code
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);
	vector<vector<int> > dp(n, vector<int>(W + 1, -1));
	cout << unboundedKnapsack(W, wt, val, n - 1, dp);
	return 0;
}
// This code is contributed by Sanskar.










// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
					int val[], int wt[])
{
	// dp[i] is going to store maximum value
	// with knapsack capacity i.
	int dp[W+1];
	memset(dp, 0, sizeof dp);

	// Fill dp[] using above recursive formula
	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (wt[j] <= i)
			dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

	return dp[W];
}

// Driver program
int main()
{
	int W = 100;
	int val[] = {10, 30, 20};
	int wt[] = {5, 10, 15};
	int n = sizeof(val)/sizeof(val[0]);

	cout << unboundedKnapsack(W, n, val, wt);

	return 0;
}








/*
	Time Complexity : O(N*W)
	Space Complexity : O(W)

	where 'N' is total number of items, 'W' is knapsack capacity.
*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Initialize 1-D array.
    int dp[w + 1];

    // Set all values to 0.
    memset(dp, 0, sizeof(dp));

    /*
    	Compute result for all values of knapsack capacity
		from 0 to 'w'. 
	*/
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (weight[j] <= i)
            {
                dp[i] = max(dp[i], profit[j] + dp[i - weight[j]]);
            }
        }
    }

    /*
    	dp[w] stores the maximum profit when knapsack
		capacity is 'w'.
	*/
    return dp[w];
}








/*// Recursive code  ==> pick and not pick approach on every possible index

 

#include <bits/stdc++.h> 
int helper(int ind,int W,vector<int> w, vector<int> v,vector<vector<int>>&dp)
{   
   if(ind<0)
   {
           return 0;
   }

   
   int taken = 0;
   if(W>=w[ind])
       taken = v[ind]+helper(ind,W-w[ind],w,v,dp);
   int notTaken = helper(ind-1,W,w,v,dp);
   return max(taken,notTaken);
}
int unboundedKnapsack(int n, int maxWeight, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
   
   return helper(n-1,maxWeight,weight,profit);
Time Complexity => O(2^n)

---→ Not accepted

 

Memoized code
 

#include <bits/stdc++.h> 
int helper(int ind,int W,vector<int> w, vector<int> v,vector<vector<int>>&dp)
{   
   if(ind<0)
   {
           return 0;
   }
   
   if(dp[ind][W]!=-1)
       return dp[ind][W];
   
   int taken = 0;
   if(W>=w[ind])
       taken = v[ind]+helper(ind,W-w[ind],w,v,dp);
   int notTaken = helper(ind-1,W,w,v,dp);
   return dp[ind][W]=max(taken,notTaken);
}
int unboundedKnapsack(int n, int maxWeight, vector<int> &profit, vector<int> &weight)
{
   // Write Your Code Here.
  vector<vector<int>>dp(n,vector<int>((maxWeight+1),-1));
 return helper(n-1,maxWeight,weight,profit,dp);
  
}
 

Time Complexity → O(N*maxWeight)

Space Complexity → O(N*maxWeight) + O(N)

---→ Paritally Accepted

 

Tabulation Code
 

int unboundedKnapsack(int n, int maxWeight, vector<int> &v, vector<int> &w)
{
   // Write Your Code Here.
   vector<vector<int>>dp(n+1,vector<int>((maxWeight+1),0));
   for(int ind=1;ind<=n;ind++)
   {
        for(int W=0;W<=maxWeight;W++)
        {
                int taken = 0;
   if(W>=w[ind-1])
       taken = v[ind-1]+dp[ind][W-w[ind-1]];
   int notTaken = 0 + dp[ind-1][W];
   dp[ind][W]=max(taken,notTaken);
        }
   }
   return dp[n][maxWeight];
}
 

Time Complexity → O(N*maxWeight)

Space Complexity → O(N*maxWeight) 

---→ Accepted

 

Space Optimization in Tabulation Approach
 

int unboundedKnapsack(int n, int maxWeight, vector<int> &v, vector<int> &w)
{
   // Write Your Code Here.

   vector<int>prev(maxWeight+1,0);
   vector<int>curr(maxWeight+1,0);
   
   for(int ind=1;ind<=n;ind++)
   {
        for(int W=0;W<=maxWeight;W++)
        {
                int taken = 0;
   if(W>=w[ind-1])
       taken = v[ind-1]+curr[W-w[ind-1]];
   int notTaken = 0 + prev[W];
   curr[W]=max(taken,notTaken);
        }
       prev=curr;
   }
   return prev[maxWeight];
}
 

Time Complexity → O(N*maxWeight)

Space Complexity → O(maxWeight) 

---→ Accepted*/