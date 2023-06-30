 /*
    Time Complexity: O(M * log(K))
    Space complexity: O(1),

    where 'K' is the sum of the time required to study all the chapters 
    and 'M' is the number of chapters.

#include <bits/stdc++.h> 

 
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    long long sum = 0;

    int maxTime = INT_MIN;

    // We will iterate through all the chapters and calculate the sum.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    // We will initialize the lower limit of binary search l with maxTime and the upper limit of binary search with sum.
    long long l = maxTime, r = sum, answer = sum;

    while (l <= r)
    {
        
        long long mid = (l + r) / 2;
        long days = 1;
        long long currentTime = 0;

        for (int i = 0; i < m; i++)
        {
            currentTime += time[i];
            if (currentTime > mid)
            {
                days++;
                currentTime = time[i];
            }

        }

        /*
            If the days required to study all the chaptes is greater than n than answer is not possible
            and we want more time to study in a given day so we will compress the range to the right hand side.
            Else we can study all the chapters and we will update the answer with mid.
        
        if (days <= n)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }

    // We will return the final answer.
    return answer;
} 
*/
// C++ program for optimal allocation of pages
#include <bits/stdc++.h>
using namespace std;

// Utility function to check if current minimum value
// is feasible or not.
bool isPossible(int arr[], int n, int m, int curr_min)
{
	int studentsRequired = 1;
	int curr_sum = 0;

	// iterate over all books
	for (int i = 0; i < n; i++) {
		// check if current number of pages are greater
		// than curr_min that means we will get the result
		// after mid no. of pages
		if (arr[i] > curr_min)
			return false;

		// count how many students are required
		// to distribute curr_min pages
		if (curr_sum + arr[i] > curr_min) {
			// increment student count
			studentsRequired++;

			// update curr_sum
			curr_sum = arr[i];

			// if students required becomes greater
			// than given no. of students,return false
			if (studentsRequired > m)
				return false;
		}

		// else update curr_sum
		else
			curr_sum += arr[i];
	}
	return true;
}

// function to find minimum pages
int findPages(int arr[], int n, int m)
{
	long long sum = 0;

	// return -1 if no. of books is less than
	// no. of students
	if (n < m)
		return -1;
	int mx = INT_MIN;

	// Count total number of pages
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		mx = max(mx, arr[i]);
	}

	// initialize start as 0 pages and end as
	// total pages
	int start = mx, end = sum;
	int result = INT_MAX;

	// traverse until start <= end
	while (start <= end) {
		// check if it is possible to distribute
		// books by using mid as current minimum
		int mid = (start + end) / 2;
		if (isPossible(arr, n, m, mid)) {
			// update result to current distribution
			// as it's the best we have found till now.
			result = mid;

			// as we are finding minimum and books
			// are sorted so reduce end = mid -1
			// that means
			end = mid - 1;
		}

		else
			// if not possible means pages should be
			// increased so update start = mid + 1
			start = mid + 1;
	}

	// at-last return minimum no. of pages
	return result;
}

// Drivers code
int main()
{
	// Number of pages in books
	int arr[] = { 12, 34, 67, 90 };
	int n = sizeof arr / sizeof arr[0];
	int m = 2; // No. of students

	cout << "Minimum number of pages = "
		<< findPages(arr, n, m) << endl;
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
