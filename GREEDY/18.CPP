// CPP program to find the maximum value
// of i*arr[i]
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
	// Sort the array
	sort(arr, arr + n);

	// Finding the sum of arr[i]*i
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (arr[i] * i);

	return sum;
}

// Driven Program
int main()
{
	int arr[] = { 3, 5, 6, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxSum(arr, n) << endl;
	return 0;
}
/*
    Time Complexity : O(N*log(N))
    Space Complexity : O(1)

    where 'N' is the size of array 'A'.
*/


int maximumSum(vector<int> &a, int n) {
    // Sort the array
    sort(a.begin(), a.end());

    // Initialising the modulo number.
    const int M = 1000000007;

    long ans = 0;

    // Finding the sum of arr[i]*i
    for (int i = 0; i < n; i++) {
      long curr = a[i];
      curr = (curr * (long) i) % M;
      ans = (ans + curr) % M;
    }

    // Returning the final result.
    return (int) ans;
}