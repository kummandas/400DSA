/*
    Time Complexity: O(m+n)
    Space Complexity: O(m+n)

    Where 'n' is the number of elements in 'arr1' and 'm' is the number of elements in 'arr2'.


int kthElement(vector<int> &arr1, int n, vector<int> &arr2, int m, int k)
{
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        // Pushing the minimum current element into 'arr3'.
        if (arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    // Pushing the remaining elements into 'arr3'.
    while (i < n)
    {
        arr3.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        arr3.push_back(arr2[j]);
        j++;
    }
    return arr3[k - 1];
}
*/




// Program to find k-th element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
	if (arr1 == end1)
		return arr2[k];
	if (arr2 == end2)
		return arr1[k];
	int mid1 = (end1 - arr1) / 2;
	int mid2 = (end2 - arr2) / 2;
	if (mid1 + mid2 < k)
	{
		if (arr1[mid1] > arr2[mid2])
			return kth(arr1, arr2 + mid2 + 1, end1, end2,
				k - mid2 - 1);
		else
			return kth(arr1 + mid1 + 1, arr2, end1, end2,
				k - mid1 - 1);
	}
	else
	{
		if (arr1[mid1] > arr2[mid2])
			return kth(arr1, arr2, arr1 + mid1, end2, k);
		else
			return kth(arr1, arr2, end1, arr2 + mid2, k);
	}
}

int main()
{
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int k = 5;
	cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
	return 0;
}










// C++ Program to find kth element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k,
						int st1 = 0, int st2 = 0)
{
	// In case we have reached end of array 1
	if (st1 == m)
		return arr2[st2 + k - 1];

	// In case we have reached end of array 2
	if (st2 == n)
		return arr1[st1 + k - 1];

	// k should never reach 0 or exceed sizes
	// of arrays
	if (k == 0 || k > (m - st1) + (n - st2))
		return -1;

	// Compare first elements of arrays and return
	if (k == 1)
		return (arr1[st1] < arr2[st2]) ?
			arr1[st1] : arr2[st2];
	int curr = k / 2;

	// Size of array 1 is less than k / 2
	if (curr - 1 >= m - st1)
	{
		// Last element of array 1 is not kth
		// We can directly return the (k - m)th
		// element in array 2
		if (arr1[m - 1] < arr2[st2 + curr - 1])
			return arr2[st2 + (k - (m - st1) - 1)];
		else
			return kth(arr1, arr2, m, n, k - curr,
				st1, st2 + curr);
	}

	// Size of array 2 is less than k / 2
	if (curr-1 >= n-st2)
	{
		if (arr2[n - 1] < arr1[st1 + curr - 1])
			return arr1[st1 + (k - (n - st2) - 1)];
		else
			return kth(arr1, arr2, m, n, k - curr,
				st1 + curr, st2);
	}
	else
	{
		// Normal comparison, move starting index
		// of one array k / 2 to the right
		if (arr1[curr + st1 - 1] < arr2[curr + st2 - 1])
			return kth(arr1, arr2, m, n, k - curr,
				st1 + curr, st2);
		else
			return kth(arr1, arr2, m, n, k - curr,
				st1, st2 + curr);
	}
}

// Driver code
int main()
{
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int k = 5;
	cout << kth(arr1, arr2, 5, 4, k);
	return 0;
}
