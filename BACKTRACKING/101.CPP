#include <iostream>
using namespace std;

bool isPossible(int elements[], int sum, int n)
{
	int dp[sum + 1];
	
	// Initializing with 1 as sum 0 is
	// always possible
	dp[0] = 1;
	
	// Loop to go through every element of
	// the elements array
	for(int i = 0; i < n; i++)
	{
		
		// To change the values of all possible sum
		// values to 1
		for(int j = sum; j >= elements[i]; j--)
		{
			if (dp[j - elements[i]] == 1)
				dp[j] = 1;
		}
	}
	
	// If sum is possible then return 1
	if (dp[sum] == 1)
		return true;
		
	return false;
}

// Driver code
int main()
{
	int elements[] = { 6, 2, 5 };
	int n = sizeof(elements) / sizeof(elements[0]);
	int sum = 7;
	
	if (isPossible(elements, sum, n))
		cout << ("YES");
	else
		cout << ("NO");

	return 0;
}

// This code is contributed by Potta Lokesh

/*/*
    Time Complexity: O(2 ^ N)
    Space Complexity: O(N)

    Where 'N' is the size of the given array.
*/

bool canPartitionUtil(vector<int> &arr, int currentIndex, int subsetSum) {

	// If currentIndex reach the end of the array or sum < 0.
	if (currentIndex >= arr.size() || subsetSum < 0)
	{
		return false;
	}

	// If we found a subset of numbers we are looking for.
	if (subsetSum == 0)
	{
		return true;
	}

	// Recursive call after choosing the element at the currentIndex.
	bool include = canPartitionUtil(arr, currentIndex + 1, subsetSum - arr[currentIndex]);

	// Recursive call after excluding the element at the currentIndex
	bool exclude = canPartitionUtil(arr, currentIndex + 1, subsetSum);

	// Check if we can partition into two equal subset or not and return.
	return include || exclude;

}

bool canPartition(vector<int> &arr, int n)
{

	// It stores the sum of all array element.
	int totalsum = 0;

	// Iterating the array.
	for (int num : arr)
	{
		totalsum += num;
	}

	// If totalsum is odd, then it can't be partitioned into equal sum subsets.
	if (totalsum % 2 != 0)
	{
		return false;
	}

	// One subset sum will always be totalsum/2.
	int subsetSum = totalsum / 2;

	return canPartitionUtil(arr, 0, subsetSum);
}


/*
    Time Complexity: O(N * S)
    Space Complexity: O(N * S)    
    
    Where 'N' is the size of the array, 
    and 'S' is the sum of all elements in the given array.
*/

bool canPartitionUtil(vector<int> &arr, int currentIndex, int subsetSum, vector<vector<int>> &dp) {

    // If currentIndex reach the end of the array or sum < 0.
    if (currentIndex >= arr.size() || subsetSum < 0) {
        return false;
    }

    // If we found a subset of numbers we are looking for.
    if (subsetSum == 0) {
        return true;
    }

    // If we had already solved the same subproblem for index = currentIndex and sum = subsetSum.
    if (dp[currentIndex][subsetSum] != -1) {
        return dp[currentIndex][subsetSum] == 1;
    }

    // Recursive call after choosing the element at the currentIndex.
    bool include = canPartitionUtil(arr, currentIndex + 1, subsetSum - arr[currentIndex], dp);

    // Recursive call after excluding the element at the currentIndex.
    bool exclude = canPartitionUtil(arr, currentIndex + 1, subsetSum, dp);

    // Check if we can partition into two equal subset or not.
    dp[currentIndex][subsetSum] = (include || exclude) ? 1 : 0;

    return dp[currentIndex][subsetSum] == 1;
    
}

bool canPartition(vector<int> &arr, int n) {
    
    // It stores the sum of all array element.
    int totalsum = 0;

    // Iterating the array.
    for (int num : arr) {
        totalsum += num;
    }

    // If totalsum is odd, then it can't be partitioned into equal sum subsets.
    if (totalsum % 2 != 0) {
        return false;
    }

    // One subset sum will always be totalsum/2.
    int subsetSum = totalsum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, -1));

    return canPartitionUtil(arr, 0, subsetSum, dp);

}


/*
    Time Complexity: O(N * S)
    Space Complexity: O(N * S)
    
    Where 'N' is the size of the array, 
    and 'S' is the sum of all elements in the given array.
*/

bool canPartition(vector<int> &arr, int n) {
    
    // It stores the sum of all array element.
    int totalSum = 0;

    for (int num : arr) {
        totalSum += num;
    }

    // If sum is odd, then it can't be partitioned into equal sum subsets.
    if (totalSum % 2 != 0) {
        return false;
    }

    // One subset sum will always be totalSum/2.
    int subsetSum = totalSum / 2;

    // Create a new auxiliary array dp.
    vector<vector<bool>> dp(n + 1, vector<bool>(subsetSum + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= subsetSum; j++) {
            if (j - arr[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]];
            }

            dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
    }
    
    return dp[n][subsetSum];

}


/*
    Time Complexity: O(N * S)
    Space Complexity: O(S)

    Where 'N' is the size of the array,
    and 'S' is the sum of all elements in the given array.
*/

bool canPartition(vector<int> &arr, int n)
{

    // It stores the sum of all array element.
    int totalSum = 0;

    for (int num : arr) {
        totalSum += num;
    }

    // If sum is odd, then it can't be partitioned into equal sum subsets.
    if (totalSum % 2 != 0)
    {
        return false;
    }

    // One subset sum will always be totalSum / 2.
    int subsetSum = totalSum / 2;

    // Create a new auxiliary array dp.
    vector<bool> dp(subsetSum + 1, false);

    dp[0] = true;

    // Traversing the given array.
    for (int i = 1; i <= n; i++)
    {
        for (int j = subsetSum; j >= 0; j--)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[j] = dp[j - arr[i - 1]] || dp[j];
            }
        }
    }

    return dp[subsetSum];

}*/