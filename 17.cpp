// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of pairs
int getPairsCount(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int x = 0, c = 0, y, z;
	for (int i = 0; i < n - 1; i++) {
		x = k - arr[i];

		// Lower bound from i+1
		int y = lower_bound(arr + i + 1, arr + n, x) - arr;

		// Upper bound from i+1
		int z = upper_bound(arr + i + 1, arr + n, x) - arr;
		c = c + z - y;
	}
	return c;
}

// Driver code
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;

	// Function call
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, k);
	return 0;
}










// C++ implementation of simple method to
// find count of pairs with given sum.
#include <bits/stdc++.h>
using namespace std;

// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
int getPairsCount(int arr[], int n, int k)
{
	unordered_map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(k - arr[i]) != m.end()) {
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}

// Driver code
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;

	// Function Call
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, sum);
	return 0;
}
