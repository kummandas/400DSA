/*
    Time Complexity: O(K * N)
    Space Complexity: O(N)

    Where K is the number of axes and N is capacity of log cutting stand.


#include <vector>

int cutLogs(int k, int n)
{	
    // Create an array dp
    vector<int> dp(n + 1);

    for(int i=0; i <= n; i++)
    {
        dp[i] = i;
    }
	
    // Iterate i from 2 to K
    for(int i=2; i <= k; i++)
    {	
        // Create an array dp2
        vector<int> dp2(n + 1);
        int t = 1;
		
        // Iterate j from 1 to N
        for(int j=1; j <= n; j++)
        {
            while(t < j and max(dp[t - 1], dp2[j - t]) > max(dp[t], dp2[j - t - 1]))
            {
                t++;
            }
            dp2[j] = 1 + max(dp[t - 1], dp2[j - t]);
        }
		
        // Update dp with dp2
        dp = dp2;
    }
	
    // Return the element dp[n]
    return dp[n];
}

*/










// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k)
{
	// If there are no floors,
	// then no trials needed.
	// OR if there is one floor,
	// one trial needed.
	if (k == 1 || k == 0)
		return k;

	// We need k trials for one
	// egg and k floors
	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	// Consider all droppings from
	// 1st floor to kth floor and
	// return the minimum of these
	// values plus 1.
	for (x = 1; x <= k; x++) {
		res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
		if (res < min)
			min = res;
	}

	return min + 1;
}

// Driver code
int main()
{
	int n = 2, k = 10;
	cout << "Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k << " floors is "
		<< eggDrop(n, k) << endl;
	return 0;
}

// This code is contributed
// by Akanksha Rai












// C++ program to find minimum number of trials in worst
// case.
#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
	// Initialize array of size (n+1) and m as moves.
	int dp[n + 1] = { 0 }, m;
	for (m = 0; dp[n] < k; m++) {
		for (int x = n; x > 0; x--) {
			dp[x] += 1 + dp[x - 1];
		}
	}
	return m;
}

/* Driver code*/
int main()
{
int n = 2, k = 36;
cout<<"Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k << " floors is ";
	cout << minTrials(2, 36);
	return 0;
}

// This code is contributed by Arihant Jain (arihantjain01)
