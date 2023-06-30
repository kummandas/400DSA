
/*
    Time Complexity : O(P * N)
    Space Complexity: O(P * N)

    Where 'N' is size of Array and 'P' is Product value.


#define mod 1000000007

int countSubsequences(vector < int > & a, int n, int p) {

    // 2D array to store result.
    int dp[p + 1][n + 1];

    // Set values of 'DP' to '0'.
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {

            // Store result of 'j - 1' elements.
            dp[i][j] = dp[i][j - 1] % mod;

            // Check whether to include 'j'th element or not.
            if (a[j - 1] <= i && a[j - 1] > 0) {
                //Count of subsequences by taking 'j'th element.
                dp[i][j] = (dp[i][j] + dp[i / a[j - 1]][j - 1] + 1) % mod;
            }
            
        }

    }

    // Result is stored at 'DP[P][N]'.
    return dp[p][n];
}









/*
    Time Complexity : O(2 ^ N)
    Space Complexity : O(N)

    Where 'N' is size of Array.

#define mod 1000000007

int countSubsequenceHelper(vector < int > & a, int p, int pr, int idx) {

    // If we have traversed all the elements and product is not more than 'P'.
    if (idx >= a.size() && pr >= 0 && pr <= p){
        return 1;
    }

    // If traversed all the elements and first base condition fails.
    if (idx >= a.size()){
        return 0;
    }

    // Variable to count subsequences.
    int cnt = 0;

    // Recursive call when 'A[IDX]' is included.
    if (pr == -1){
        cnt += countSubsequenceHelper(a, p, a[idx], idx + 1);
    }
    else{
        cnt += countSubsequenceHelper(a, p, pr * a[idx], idx + 1);
    }

    // Recursive call when 'A[IDX]' is not included.
    cnt += countSubsequenceHelper(a, p, pr, idx + 1);

    return cnt % mod;
}

int countSubsequences(vector < int > & a, int n, int p) {

    // Recursive function to count subsequences.
    int res = countSubsequenceHelper(a, p, -1, 0);

    // Return 'RES'.
    return res % mod;
}                                            















/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(N)

    Where N is the number of Dumbbells in RACK



int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int dp[n];
    int totalWeight = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        dp[i] = rack[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            // Choose element which is smaller than last element.
            if(rack[i] > rack[j] && dp[i] < dp[j] + rack[i])
            {
                dp[i] = dp[j] + rack[i];
            }
        }

        // Store the maximum weigth in 'totalWeight'.
        totalWeight = max(totalWeight, dp[i]);
    }

    return totalWeight;
}
*/

// CPP program to find number of subarrays having
// product less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &arr, int k)
{
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
	
			// number of subsequence using j-1 terms
			dp[i][j] = dp[i][j - 1];

			// if arr[j-1] > i it will surely make product greater
			// thus it won't contribute then
			if (arr[j - 1] <= i)

				// number of subsequence using 1 to j-1 terms
				// and j-th term
				dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
		}
	}
	return dp[k][n];
}

// Driver code
int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	int k = 10;
	cout << productSubSeqCount(A, k) << endl;
}
