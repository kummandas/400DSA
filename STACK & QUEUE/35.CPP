/*/*
    Time Complexity: O(N*K)
    Space Complexity: O(1),

	Where N is the number of elements in the array, K is the size of the subarray.


#include<vector>

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Initialize a variable to store final result
	long long totalSum = 0;

	for (int i = 0; i <= n-k; i++) {

		// Stores minimum value for this window.
		long long minCurrent = 10e9;

		// Stores maximum value for this window.
		long long maxCurrent = -1;	

		for (int j = i; j < i+k; j++) {
			if(nums[j]<minCurrent) {
				minCurrent = nums[j];
			}

			if(nums[j]>maxCurrent) {
				maxCurrent = nums[j];
			}

		}

		// Add minimum and maximumvalues of this window to the final result.
		totalSum += minCurrent + maxCurrent;	
	}
    
    return totalSum;
}*/











// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0; // Initialize result

	// The queue will store indexes of useful elements
	// in every window
	// In deque 'G' we maintain decreasing order of
	// values from front to rear
	// In deque 'S' we maintain increasing order of
	// values from front to rear
	deque< int > S(k), G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous greater elements
		// that are useless.
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Process rest of the Array elements
	for ( ; i < n; i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += arr[S.front()] + arr[G.front()];

		// Remove all elements which are out of this
		// window
		while ( !S.empty() && S.front() <= i - k)
			S.pop_front();
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();

		// remove all previous greater element that are
		// useless
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// remove all previous smaller that are elements
		// are useless
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += arr[S.front()] + arr[G.front()];

	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}
























/*
    Time Complexity: O(N)
    Space Complexity: O(K),

    Where N is the number of elements in the array, K is the size of the subarray.
*/

#include<deque>

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    // Initialize a variable to store final result
    long long totalSum = 0;

    deque<int> minDQ, maxDQ;
     
    for(int i=0;i<k;i++) {

        // The current element
        int curr = nums[i];     

        while(!minDQ.empty() && nums[minDQ.back()] >= curr) {
            minDQ.pop_back();
        }

        while(!maxDQ.empty() && nums[maxDQ.back()] <= curr) {
            maxDQ.pop_back();
        }

        minDQ.push_back(i);
        maxDQ.push_back(i);
    }

    // Add minimum and maximum values of this window to the final result.
    totalSum += nums[minDQ.front()] + nums[maxDQ.front()];

    for(int i=k;i<n;i++) {
        
        // The current element
        int curr = nums[i];     

        // Remove all indices from both the Dequeues that are not in the current window.
        while ( !minDQ.empty() && minDQ.front() <= i - k) {
            minDQ.pop_front();
        }

        while ( !maxDQ.empty() && maxDQ.front() <= i - k) {
            maxDQ.pop_front();
        }


        // Remove all previous greater elements from the rear end.
        while(!minDQ.empty() && nums[minDQ.back()] >= curr) {
            minDQ.pop_back();
        }

        // Remove all previous smaller elements from the rear end.
        while(!maxDQ.empty() && nums[maxDQ.back()] <= curr) {
            maxDQ.pop_back();
        }

        // Insert the current index to both the Dequeues. 
        minDQ.push_back(i);
        maxDQ.push_back(i);

        // Add minimum and maximum values of this window to the final result.
        totalSum += nums[minDQ.front()] + nums[maxDQ.front()];

    }

    return totalSum;
}