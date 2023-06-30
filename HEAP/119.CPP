/*Hint 1

 Full Solution

// Back-end complete function Template for C++


void maxHeapify(vector<int> &arr, int n, int idx) {
    // Find largest of node and its children
    if (idx >= n) return;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max;
    if (l < n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    if (r < n && arr[r] > arr[max]) max = r;

    // Put maximum value at root and
    // recur for the child with the
    // maximum value
    if (max != idx) {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}

// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(vector<int> &arr, int n) {
    // building the heap from first non-leaf
    // node by calling max heapify function
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
}

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> merged(n+m,0);
        for (int i = 0; i < n; i++) merged[i] = a[i];
        for (int i = 0; i < m; i++) merged[n + i] = b[i];

        buildMaxHeap(merged, n + m);
        return merged;
    }
};*/

// C++ program to find the K-th largest sum
// of subarray
#include <bits/stdc++.h>
using namespace std;

// Function to calculate Kth largest element
// in contiguous subarray sum
int kthLargestSum(int arr[], int N, int K)
{
	// array to store prefix sums
	int sum[N + 1];
	sum[0] = 0;
	sum[1] = arr[0];
	for (int i = 2; i <= N; i++)
		sum[i] = sum[i - 1] + arr[i - 1];

	// priority_queue of min heap
	priority_queue<int, vector<int>, greater<int> > Q;

	// loop to calculate the contiguous subarray
	// sum position-wise
	for (int i = 1; i <= N; i++) {

		// loop to traverse all positions that
		// form contiguous subarray
		for (int j = i; j <= N; j++) {
			// calculates the contiguous subarray
			// sum from j to i index
			int x = sum[j] - sum[i - 1];

			// if queue has less than k elements,
			// then simply push it
			if (Q.size() < K)
				Q.push(x);

			else {
				// it the min heap has equal to
				// k elements then just check
				// if the largest kth element is
				// smaller than x then insert
				// else its of no use
				if (Q.top() < x) {
					Q.pop();
					Q.push(x);
				}
			}
		}
	}

	// the top element will be then kth
	// largest element
	return Q.top();
}

// Driver's code
int main()
{
	int a[] = { 10, -10, 20, -40 };
	int N = sizeof(a) / sizeof(a[0]);
	int K = 6;

	// Function call
	cout << kthLargestSum(a, N, K);
	return 0;
}
