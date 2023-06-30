// C++ program to maximize array sum after
// k operations.
#include <bits/stdc++.h>
using namespace std;

// This function does k operations on array in a way that
// maximize the array sum. index --> stores the index of
// current minimum element for j'th operation
int maximumSum(int arr[], int n, int k)
{
	// Modify array K number of times
	for (int i = 1; i <= k; i++) {
		int min = INT_MAX;
		int index = -1;

		// Find minimum element in array for current
		// operation and modify it i.e; arr[j] --> -arr[j]
		for (int j = 0; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}

		// this the condition if we find 0 as minimum
		// element, so it will useless to replace 0 by -(0)
		// for remaining operations
		if (min == 0)
			break;

		// Modify element of array
		arr[index] = -arr[index];
	}

	// Calculate sum of array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

// Driver code
int main()
{
	int arr[] = { -2, 0, 5, -1, 2 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maximumSum(arr, n, k);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)







// C++ program to find maximum array sum after at most k
// negations.
#include <bits/stdc++.h>

using namespace std;

int sol(int arr[], int n, int k)
{
	int sum = 0;
	int i = 0;

	// Sorting given array using in-built sort function
	sort(arr, arr + n);
	while (k > 0) {
		// If we find a 0 in our sorted array, we stop
		if (arr[i] >= 0)
			k = 0;
		else {
			arr[i] = (-1) * arr[i];
			k = k - 1;
		}
		i++;
	}

	// Calculating sum
	for (int j = 0; j < n; j++)
		sum += arr[j];
	return sum;
}

// Driver code
int main()
{
	int arr[] = { -2, 0, 5, -1, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << sol(arr, n, 4) << endl;
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
