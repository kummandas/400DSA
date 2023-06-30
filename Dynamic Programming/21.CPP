/* 














int longestSubsequence(int n, int a[])
    {
        // code here
        vector<int> dp(1001, 0);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int diff1 = a[i]-1;
            int diff2 = a[i]+1;
            dp[a[i]] = 1+max(dp[diff1] , dp[diff2]);
            ans = max(ans,dp[a[i]]);
        }
        
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
      int longestSubsequence(int n, int arr[])
    {
        int maxi=-1;
    vector<int>dp(n+2,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(abs(arr[i]-arr[j])==1&&1+dp[j]>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    
    }*/


    /*/*
    Time Complexity - O(N ^ 2)
    Space Complexity - O(N)

    Where N is the size of the array "nums".


#include <vector>
#include <algorithm>

int longestSubsequence(vector<int> &nums){
	
	int n = nums.size();
	int dp[n];

	// Initialize all the elements of the dp array to 1.
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {

			if(abs(nums[j] - nums[i]) == 1) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}

	int maximum = 0;

	for(int i = 0; i < n; i++) {
		maximum = max(maximum, dp[i]);
	}

	return maximum;
}*/


//O(N)

//O(N)
#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int arr[])
	{
		if(n==1)
			return 1;
		unordered_map<int,int> mapp;
		int res = 1;
		for(int i=0;i<n;i++){
			if(mapp.count(arr[i]+1) >0 || mapp.count(arr[i]-1)>0){
				mapp[arr[i]]=1+max(mapp[arr[i]+1],mapp[arr[i]-1]);
			}
			else
				mapp[arr[i]]=1;
			res = max(res, mapp[arr[i]]);
		}
		return res;
		//This code is contributed by Akansha Mittal
	}
int main()
{
	// Longest subsequence with one difference is
	// {1, 2, 3, 4, 3, 2}
	int arr[] = {1, 2, 3, 4, 5, 3, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << longestSubsequence(n, arr);
	return 0;
}



// C++ program to find the longest subsequence such
// the difference between adjacent elements of the
// subsequence is one.
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of longest subsequence
int longestSubseqWithDiffOne(int arr[], int n)
{
	// Initialize the dp[] array with 1 as a
	// single element will be of 1 length
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	// Start traversing the given array
	for (int i = 1; i < n; i++) {
		// Compare with all the previous elements
		for (int j = 0; j < i; j++) {
			// If the element is consecutive then
			// consider this subsequence and update
			// dp[i] if required.
			if ((arr[i] == arr[j] + 1) || (arr[i] == arr[j] - 1))

				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// Longest length will be the maximum value
	// of dp array.
	int result = 1;
	for (int i = 0; i < n; i++)
		if (result < dp[i])
			result = dp[i];
	return result;
}

// Driver code
int main()
{
	// Longest subsequence with one difference is
	// {1, 2, 3, 4, 3, 2}
	int arr[] = { 1, 2, 3, 4, 5, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubseqWithDiffOne(arr, n);
	return 0;
}
