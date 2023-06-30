// C++ program to implement the above approach
/*#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms
// required
int findPlatform(int arr[], int dep[], int n)
{
	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;

	// Run a nested for-loop to find the overlap
	for (int i = 0; i < n; i++) {

		// Initially one platform is needed
		plat_needed = 1;
		for (int j = 0; j < n; j++) {
			if (i != j)
				// Increment plat_needed when there is an
				// overlap
				if (arr[i] >= arr[j] && dep[j] >= arr[i])
					plat_needed++;
		}

		// Update the result
		result = max(plat_needed, result);
	}
	return result;
}

// Driver Code
int main()
{

	// Train 1 => Arrival : 01:00, Departure : 09:00
	// Train 2 => Arrival : 03:00, Departure : 04:00
	// Train 3 => Arrival : 05:00, Departure : 06:00
	int arr[] = { 100, 300, 500 };
	int dep[] = { 900, 400, 600 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}

// Code contributed by farzams101
*/








// C++ program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

int minPlatform(int arrival[], int departure[], int n)
{

	// as time range from 0 to 2359 in 24 hour clock,
	// we declare an array for values from 0 to 2360
	int platform[2361] = {0};
	int requiredPlatform = 1;
	for (int i = 0; i < n; i++) {

		// increment the platforms for arrival
		++platform[arrival[i]];

		// once train departs we decrease the platform count
		--platform[departure[i] + 1];
	}

	// We are running loop till 2361 because maximum time value
	// in a day can be 23:60
	for (int i = 1; i < 2361; i++) {

		// taking cumulative sum of platform give us required
		// number of platform for every minute
		platform[i] = platform[i] + platform[i - 1];
		requiredPlatform = max(requiredPlatform, platform[i]);
	}
	return requiredPlatform;
}

// Driver code
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = "
		<< minPlatform(arr, dep, n);
	return 0;
}
