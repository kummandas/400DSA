/*
    Time Complexity : O(2 ^ N)
    Space Complexity : O(N)
    Where N is the size of the array


#include <climits>

int longestIncreasingSubsequenceHelper(int arr[], int prev, int curPosition, int n)
{
    // Base case
    if (curPosition == n)
    {
        return 0;
    }

    int taken = 0;

    // Taking the current element
    if (arr[curPosition] > prev)
    {
        taken = 1 + longestIncreasingSubsequenceHelper(arr, arr[curPosition], curPosition + 1, n);
    }

    // Not Taking the current element
    int notTaken = longestIncreasingSubsequenceHelper(arr, prev, curPosition + 1, n);

    return max(taken, notTaken);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return longestIncreasingSubsequenceHelper(arr, INT_MIN, 0, n);
}
*/


/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(N)
    Where N is the size of the array


int longestIncreasingSubsequence(int arr[], int n)
{
    // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int dp[n]; 

    // Base case
    dp[0] = 1;

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        int maxval = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                maxval = max(maxval, dp[j]);
            }
        }
        dp[i] = maxval + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}
*/








#include <bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
	if (v.size() == 0) // boundary case
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1; // always points empty slot in tail

	tail[0] = v[0];

	for (int i = 1; i < v.size(); i++) {

		// Do binary search for the element in
		// the range from begin to begin + length
		auto b = tail.begin(), e = tail.begin() + length;
		auto it = lower_bound(b, e, v[i]);

		// If not present change the tail element to v[i]
		if (it == tail.begin() + length)
			tail[length++] = v[i];
		else
			*it = v[i];
	}

	return length;
}

int main()
{
	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	std::cout
		<< "Length of Longest Increasing Subsequence is "
		<< LongestIncreasingSubsequenceLength(v);
	return 0;
}
