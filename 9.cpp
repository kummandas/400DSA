// C++ Code for the Approach

#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);

    // Maximum possible height difference
    int ans = arr[n - 1] - arr[0];

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++) {

        // If on subtracting k we got
        // negative then continue
        if (arr[i] - k < 0)
            continue;

        // Minimum element when we
        // add k to whole array
        tempmin = min(arr[0] + k, arr[i] - k);

        // Maximum element when we
        // subtract k from whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);

        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

// Driver Code Starts
int main()
{

    int k = 6, n = 6;
    int arr[n] = { 7, 4, 8, 8, 8, 9 };

    // Function Call
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}