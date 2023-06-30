// CPP program to find maximum product of
// a subset.
#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
	if (n == 1)
		return a[0];

	// Find count of negative numbers, count
	// of zeros, negative number
	// with least absolute value
	// and product of non-zero numbers
	int max_neg = INT_MIN;
	int count_neg = 0, count_zero = 0;
	int prod = 1;
	for (int i = 0; i < n; i++) {

		// If number is 0, we don't
		// multiply it with product.
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		// Count negatives and keep
		// track of negative number
		// with least absolute value
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}

		prod = prod * a[i];
	}

	// If there are all zeros
	if (count_zero == n)
		return 0;

	// If there are odd number of
	// negative numbers
	if (count_neg & 1) {

		// Exceptional case: There is only
		// negative and all other are zeros
		if (count_neg == 1 &&
			count_zero > 0 &&
			count_zero + count_neg == n)
			return 0;

		// Otherwise result is product of
		// all non-zeros divided by
		//negative number with
		// least absolute value
		prod = prod / max_neg;
	}

	return prod;
}

// Driver Code
int main()
{
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxProductSubset(a, n);
	return 0;
}









/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the size of the given array.
*/

long long int maxProductSubset(vector<int> &arr, int n)
{
    if (n == 1)
    {	
        // Only 1 element in the array.
        return arr[0];
    }
    
    long long int ans = 1;
    int mod = 1e9 + 7;
    int id = -1, minElement = 0;
    int zeroCount = 0, negCount  = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {   
           // Counting number of zeros.
           zeroCount++; 
        }
        else if (arr[i] < 0)
        {   
            // Counting number of negative numbers.
            negCount++;
            if (id == -1 || arr[i] > minElement)
            {   
                // Storing the index of negative element having least magnitude.
                id = i;
                minElement = arr[i];
            }
        }
    }
    if(zeroCount == n)
    {   
        // If there are all zeros.
        return 0;
    }
    if (negCount == 1 && zeroCount == n - 1)
    {   
        // If all elements are zero except one negative element, then return 0.
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            continue;
        }
        if(negCount % 2 == 1 && i == id)
        {   
            // Removing the negative element having least magnitude.  
            continue;
        }
        ans = ((ans * arr[i]) % mod + mod) % mod;
        
    }
    return ans;
}