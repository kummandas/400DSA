// C++ implementation to find the minimum
// and maximum amount
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum amount
// to buy all candies
int findMinimum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        // Buy current candy
        res += arr[i];

        // And take k candies for free
        // from the last
        n = n - k;
    }
    return res;
}

// Function to find the maximum amount
// to buy all candies
int findMaximum(int arr[], int n, int k)
{
    int res = 0, index = 0;

    for (int i = n - 1; i >= index; i--) 
    {
        // Buy candy with maximum amount
        res += arr[i];

        // And get k candies for free from
        // the starting
        index += k;
    }
    return res;
}

// Driver code
int main()
{
    int arr[] = { 3, 2, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    sort(arr, arr + n);

    // Function call
    cout << findMinimum(arr, n, k) << " "
         << findMaximum(arr, n, k) << endl;
    return 0;
}








// C++ implementation
// to find the minimum
// and maximum amount
#include <bits/stdc++.h>
using namespace std;

// function to find the maximum
// and the minimum cost required
void find(vector<int> arr, int n, int k)
{

    // Sort the array
    sort(arr.begin(), arr.end());
    int b = ceil(n / k * 1.0);
    int min_sum = 0, max_sum = 0;

    for(int i = 0; i < b; i++) 
      min_sum += arr[i];
    for(int i = 2; i < arr.size(); i++)
      max_sum += arr[i];

    // print the minimum cost
    cout << "minimum " << min_sum << endl;

    // print the maximum cost
    cout << "maximum " << max_sum << endl;

}


// Driver code
int main()
{
  vector<int> arr = {3, 2, 1, 4};
  int n = arr.size();
  int k = 2;

  // Function call
  find(arr,n,k);
}
