/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(1)

    Where 'N' is the size of the array.


int maxSumPairWithDifferenceLessThanK(vector<int> & arr, int n, int k){

    // Initialize 'MAXSUM' to 0.
    int maxSum = 0;

    // Sort all the elements present inside the array.
    sort(arr.begin(), arr.end());

    int i = n - 1;

    while(i > 0){
        /*
            If the difference of 'ARR[i]' and 'ARR[i - 1]' is less than 'K', 
            then add the pair to the 'MAXSUM'.
        
        if(arr[i] - arr[i - 1] < k){
            maxSum += arr[i];
            maxSum += arr[i - 1];
            i -= 1;
        }
        
        i -= 1;
    }

    return maxSum;
}*/







// C++ program to find maximum pair sum whose
// difference is less than K
#include <bits/stdc++.h>
using namespace std;

// Method to return maximum sum we can get by
// finding less than K difference pairs
int maxSumPair(int arr[], int N, int k)
{
	int maxSum = 0;

	// Sort elements to ensure every i and i-1 is closest
	// possible pair
	sort(arr, arr + N);

	// To get maximum possible sum,
	// iterate from largest to
	// smallest, giving larger
	// numbers priority over smaller
	// numbers.
	for (int i = N - 1; i > 0; --i)
	{
		// Case I: Diff of arr[i] and arr[i-1]
		// is less than K,add to maxSum	
		// Case II: Diff between arr[i] and arr[i-1] is not
		// less than K, move to next i since with
		// sorting we know, arr[i]-arr[i-1] <
		// rr[i]-arr[i-2] and so on.
		if (arr[i] - arr[i - 1] < k)
		{
			// Assuming only positive numbers.
			maxSum += arr[i];
			maxSum += arr[i - 1];

			// When a match is found skip this pair
			--i;
		}
	}

	return maxSum;
}

// Driver code
int main()
{
	int arr[] = { 3, 5, 10, 15, 17, 12, 9 };
	int N = sizeof(arr) / sizeof(int);

	int K = 4;
	cout << maxSumPair(arr, N, K);
	return 0;
}
