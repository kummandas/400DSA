// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array
	// so that we can retrieve
	// the large elements from
	// the end of array elements
	sort(a, a + n);

	// In this loop first we will insert
	// one smallest element not entered
	// till that time in final sequence
	// and then enter a highest element
	// (not entered till that time) in
	// final sequence so that we
	// have large difference value. This
	// process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2 because
	// we are inserting two elements at a
	// time in loop.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the
	// middle element at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);

	// variable to store the
	// maximum sum of absolute
	// difference
	int MaximumSum = 0;

	// In this loop absolute difference
	// of elements for the final sequence
	// is calculated.
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] -
								finalSequence[i + 1]);
	}

	// absolute difference of last element
	// and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] -
									finalSequence[0]);

	// return the value
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}






/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the length of the array.
*/

#include<algorithm>

int maxAbsSum(vector<int> &arr, int n) 
{
    // For best permutation array 
    vector<int>ans;

    sort(arr.begin(), arr.end());

    // Add number from both sides of array 
    for(int i = 0; i < n/2; i++)
    {
        ans.push_back(arr[i]);
        ans.push_back(arr[n - i - 1]);
    }

    // If n is odd then add the middle element
    if(n % 2 == 1)
    {
        ans.push_back(arr[n / 2]);
    }

    int maxSum = 0;
    for(int i = 0; i < n - 1; i++) 
    {
        maxSum += abs(ans[i] - ans[i + 1]);
    }

    // For the difference between the first and the last element
    maxSum += abs(ans[n - 1] - ans[0]);

    return maxSum;
}



// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

long long int maxSum(int arr[], int n)
{
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	bool off = true;
	long long int sum = 0;
	while (i < j) {
		sum += abs(arr[i] - arr[j]);
		if (!off) {
			j--;
		}
		else {
			i++;
		}
		off = !off;
	}
	sum += abs(arr[i] - arr[0]);
	return sum;
}
// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << maxSum(a, n) << endl;
}














#include <bits/stdc++.h> 
int maxAbsSum(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int left=0,right=n-1,res=0;
    bool front=true;
    while(left<=right) {
        res+=abs(arr[right]-arr[left]);
        if(front) {
            left++;
        }
        else {
            right--;
        }
        front=!front;
    }
    if(n%2!=0) {
        res+=(arr[left-1]-arr[0]);
    }
    else {
        res+=(arr[left]-arr[0]);
    }
    return res;
}