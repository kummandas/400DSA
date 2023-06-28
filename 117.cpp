 /*
    Time Complexity = O(K * (log(arrSum)))
    Space Complexity = O(1)

    Where N is the number of elements in the given array/list and arrSum is the sum of the array elements.
*/

#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

//    Return the maximum element from the array.
int findMax(vector<int> &boards, int n)
{
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (boards[i] > max)
		{
			max = boards[i];
		}
	}

	return max;
}

//    Return the sum of the elements in the array.
int findSum(vector<int> &boards, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += boards[i];
	}
	return total;
}

//    Find minimum required painters for given maxlen which is the maximum length a painter can paint.
int countPainters(vector<int> &boards, int maxLen)
{
	int n = boards.size(), totalSum = 0, painters = 1;

	for (int i = 0; i < n; i++)
	{
		totalSum += boards[i];

		if (totalSum > maxLen)
		{
			totalSum = boards[i];
			painters++;
		}
	}

	return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
	int n = boards.size();

	int low = findMax(boards, n);
	int high = findSum(boards, n);

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int reqPainters = countPainters(boards, mid);

		//    Find better optimum in lower half here mid is included because we may not get anything better.
		if (reqPainters <= k)
		{
			high = mid;
		}
		
		//    Find better optimum in upper half here mid is excluded because it gives required Painters > k, which is invalid.
		else
		{
			low = mid + 1;
		}
	}

	return low;
} 