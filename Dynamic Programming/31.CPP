// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
	// base case when all elements are removed
	if (i >= j)
		return 0;

	// if condition is satisfied, no more
	// removals are required
	else if ((a[j] - a[i]) <= k)
		return 0;

	// if the state has already been visited
	else if (dp[i][j] != -1)
		return dp[i][j];

	// when Amax-Amin>d
	else if ((a[j] - a[i]) > k) {

		// minimum is taken of the removal
		// of minimum element or removal
		// of the maximum element
		dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
						countRemovals(a, i, j - 1, k));
	}
	return dp[i][j];
}

// To sort the array and return the answer
int removals(int a[], int n, int k)
{
	// sort the array
	sort(a, a + n);

	// fill all stated with -1
	// when only one element
	memset(dp, -1, sizeof(dp));
	if (n == 1)
		return 0;
	else
		return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}










// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

int removal(int a[], int n, int k)
{
	// Sort the Array; Time complexity:O(nlogn)
	sort(a, a + n);

	// to store the max length of
	// array with difference <= k
	int maxLen = INT_MIN;
	int i = 0;
	// J goes from 0 to n-1
	// Thus time complexity of below loop is O(n)
	for (int j = 0; j < n && i < n; j++) {
		// if the subarray from i to j index is valid
		// the store it's length
		if (a[j] - a[i] <= k) {
			maxLen = max(maxLen, j - i + 1);
		}
		// if subarray difference exceeds k
		// change starting position, i.e. i
		else {
			i++;
		}
	}
	// no. of elements need to be removed is
	// Length of array - max subarray with diff <= k
	int removed = n - maxLen;
	return removed;
}

//Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removal(a, n, k);
	return 0;
}











// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int removal(int a[], int n, int k)
{
	// Code here
	// Sort the Array; Time complexity:O(nlogn)
	sort(a, a + n);
	int diff= 0; // to store difference of max(a) and min(a)
	int ans = 0; // to store maximum length of array with length <=k

	// use sliding window to iterate array, maintaining two
	// pointers for desired subarray
	// which starting from index j and ending with index i
	for (int i = 0, j = 0; i < n; i++) {
		int diff = a[i] - a[j];
		// as array is already sorted, if difference exceeds
		// k we will move starting pointer forward
		while (i >= j && diff > k) {
			diff = a[i] - a[++j];
		}
		ans = max(ans, i - j + 1);
	}
	return n - ans;
}
// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removal(a, n, k);
	return 0;
}

// This code is contributed by Gaurav Garg






















// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k
int findInd(int key, int i,
			int n, int k, int arr[])
{
	int start, end, mid, ind = -1;
	
	// Initialising start to i + 1
	start = i + 1;
	
	// Initialising end to n - 1
	end = n - 1;
	
	// Binary search implementation
	// to find the rightmost element
	// that satisfy the condition
	while (start < end)
	{
		mid = start + (end - start) / 2;
		
		// Check if the condition satisfies
		if (arr[mid] - key <= k)
		{
			
			// Store the position
			ind = mid;
			
			// Make start = mid + 1
			start = mid + 1;
		}
		else
		{
			// Make end = mid
			end = mid;
		}
	}
	
	// Return the rightmost position
	return ind;
}

// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
	int i, j, ans = n - 1;
	
	// Sort the given array
	sort(arr, arr + n);
	
	// Iterate from 0 to n-1
	for (i = 0; i < n; i++)
	{
		
		// Find j such that
		// arr[j] - arr[i] <= k
		j = findInd(arr[i], i, n, k, arr);
		
		// If there exist such j
		// that satisfies the condition
		if (j != -1)
		{
			// Number of elements
			// to be removed for this
			// particular case is
			// (j - i + 1)
			ans = min(ans, n - (j - i + 1));
		}
	}
	
	// Return answer
	return ans;
}

// Driver Code
int main()
{
	int a[] = {1, 3, 4, 9, 10,
			11, 12, 17, 20};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}
