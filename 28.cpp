// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
    // .
    for (int i = 1; i < n - 1; i++) {
        int var = min(left[i - 1], right[i + 1]);
        if (var > arr[i]) {
            water += var - arr[i];
        }
    }

    return water;
}

// Driver program
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findWater(arr, n);
    return 0;
}











// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{ 
    // Indices to traverse the array
    int left = 0;
    int right = n-1;
 
    // To store Left max and right max 
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;
 
    // To store the total amount 
    // of rain water trapped
    int result = 0;
    while (left <= right)
    {
 
      // We need check for minimum of left 
      // and right max for each element
      if(r_max <= l_max)
      {
 
        // Add the difference between 
        // current value and right max at index r
        result += max(0, r_max-arr[right]);
 
        // Update right max
        r_max = max(r_max, arr[right]);
 
        // Update right pointer
        right -= 1;
      }
      else
      { 
 
        // Add the difference between 
        // current value and left max at index l
        result += max(0, l_max-arr[left]);
 
        // Update left max
        l_max = max(l_max, arr[left]);
 
        // Update left pointer
        left += 1;
      }
    }
    return result;
}

// Driver code
int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << maxWater(arr, N) << endl;
    return 0;
}

// This code is contributed by avanitrachhadiya2155