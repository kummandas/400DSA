/*class Solution{
    public:
    long long  dp[1000][1000];
    long long maximumAmount(int arr[], int n){
        memset(dp,-1,sizeof(dp));
        return fun(1,arr,n,0,n-1);
        
        // Your code here
    }
    long long  fun(int turn , int arr[] ,int n , int i , int  j ){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=0;
        if(turn){
            //me
            
            ans+=max(arr[j]+fun(turn^1,arr,n,i,j-1),arr[i]+fun(turn^1,arr,n,i+1,j));
            
        }
        else{   
            ans+=min(fun(turn^1,arr,n,i,j-1),fun(turn^1,arr,n,i+1,j));
        }
        return dp[i][j]=ans;
}};*/









/*
	Time complexity: O(2 ^ N)
	Space Complexity: O(N)
	
	Where N is the number of coins. 


int optimalStrategyOfGameHelper(vector<int> &coins, int i, int j, int sum)
{
    if (i + 1 == j)
    {
        // Only two coins in the subarray.
        return max(coins[i], coins[j]);
    }
    
    // Player selects ith coin.
    int a = sum - optimalStrategyOfGameHelper(coins, i + 1, j, sum - coins[i]);

    // Player selects jth coin. 
    int b = sum - optimalStrategyOfGameHelper(coins, i, j - 1, sum - coins[j]);

    // Choose the combination which gives maximum amount.
    int amount = max(a,b);
    return amount;
}

int optimalStrategyOfGame(vector<int> coins, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = (sum + coins[i]);
    }
    return optimalStrategyOfGameHelper(coins, 0, n - 1, sum);
}
*/











#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum possible
// amount of money we can win.
long long maximumAmount(int arr[], int n)
{
	long long sum = 0;
	vector<long long> dp(n, 0);
	for (int i = (n - 1); i >= 0; i--) {

		// Calculating the sum of all the elements
		sum += arr[i];
		for (int j = i; j < n; j++) {
			if (i == j) {

				// If there is only one element then we
				// can only get arr[i] score
				dp[j] = arr[j];
			}
			else {
				// Calculating the dp states
				// using the relation
				dp[j] = max(arr[i] - dp[j],
							arr[j] - dp[j - 1]);
			}
		}
	}
	// Equating and returning the final answer
	// as per the relation
	return (sum + dp[n - 1]) / 2;
}

// Driver Code
int main()
{
	int arr1[] = { 8, 15, 3, 7 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	printf("%lld\n", maximumAmount(arr1, n));

	return 0;
}
