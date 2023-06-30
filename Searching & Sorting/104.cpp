// C++ implementation of the approach
/*
#include <bits/stdc++.h>
using namespace std;

// function to sort the array according
// to the number of set bits in elements
void sortArr(int arr[], int n)
{
	multimap<int, int> map;

	for (int i = 0; i < n; i++) {
		int count = 0;
		int k = arr[i];

		// Counting no of setBits in arr[i]
		while (k) {
			k = k & k - 1;
			count++;
		}

		// The count is subtracted from 32
		// because the result needs
		// to be in descending order
		map.insert(make_pair(32 - count, arr[i]));
	}

	// Printing the numbers in descending
	// order of set bit count
	for (auto it = map.begin(); it != map.end(); it++) {
		cout << (*it).second << " ";
	}
}

// Driver code
int main()
{
	int arr[] = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortArr(arr, n);

	return 0;
}
*/

// C++ program to sort an array according to count of set
// bits using std::sort()
#include <bits/stdc++.h>
using namespace std;

// a utility function that returns total set bits count in an integer
int countBits(int a)
{
	int count = 0;
	while (a) {
		if (a & 1)
			count += 1;
		a = a >> 1;
	}
	return count;
}

// custom comparator of std::sort
int cmp(int a, int b)
{
	int count1 = countBits(a);
	int count2 = countBits(b);

	// this takes care of the stability of sorting algorithm too
	if (count1 <= count2)
		return false;
	return true;
}

// Function to sort according to bit count using std::sort
void sortBySetBitCount(int arr[], int n)
{
	stable_sort(arr, arr + n, cmp);
}

// Utility function to print an array
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	printArr(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
