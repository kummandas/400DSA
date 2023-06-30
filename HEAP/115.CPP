// C++ code for above approach
#include <bits/stdc++.h>
using namespace std;

// A max-heap based method
// for printing maximum element of
// all subarrays of size k
void printKMax(int arr[], int N, int K) {
	
	// create a max-heap to store
	// the first k elements
	priority_queue<int> max_heap;

	for (int i = 0; i < K; i++) {
		max_heap.push(arr[i]);
	}

	// output the maximum element
	// in the first window
	cout << max_heap.top() << " ";

	// process the remaining windows
	for (int i = 1; i <= N - K; i++) {

		// remove the first element of
		// the max-heap if it is outside
		// of the current window
		if (max_heap.top() == arr[i - 1]) {
			max_heap.pop();
		}

		// add the next element of the
		// array to the max-heap
		max_heap.push(arr[i + K - 1]);

		// output the maximum element
		// in the current window
		cout << max_heap.top() << " ";
	}
}

// Driver's code
int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	// Function call
	printKMax(arr, N, K);
	return 0;
}
