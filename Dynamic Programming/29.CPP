/*/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of elements int the sequence.

int minJumps(vector<int> &arr) 
{

    /* 
        The variable 'curEnd stores the last index reachable from the current index
        'curFarthest storest the farthest index reachable.
    
    int minJump = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < arr.size() - 1; i++) 
    {

        // Update 'curFarthest'.
        curFarthest = max(curFarthest, i + arr[i]);
        if (i == curEnd) 
        {

            // Increment number of jumps if we reach the last reachable index.
            minJump++;

            // Update the farthest index reachable.
            curEnd = curFarthest;
        }
    }
    return minJump;
}*/









// C++ program to count Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];

    // stores the number of steps
    // we can still take
    int step = arr[0];

    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;

    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}

// Driver program to test above function
int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int size = sizeof(arr) / sizeof(int);

    // Calling the minJumps function
    cout << ("Minimum number of jumps to reach end is %d ",
             minJumps(arr, size));
    return 0;
}
// This code is contributed by
// Shashank_Sharma









/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    Where 'N' is the number of elements in the sequence.
*/

int minJumpsHelper(vector<int>& arr, int currIdx, vector<int>& dp) {

    // Base Case.
    if (currIdx >= arr.size() - 1) 
    {
        return 0;
    }

    // If answer already calculated, return it immidiately.
    if (dp[currIdx] != -1) 
    {
        return dp[currIdx];
    }

    // Initialised with a very large value.
    int minJumps = 999999;  

    // Calculate answer recursively.
    int currentAns = 0;
    
    for (int i = 1; i <= arr[currIdx]; i++) 
    {
        if (currIdx + i <= arr.size() - 1) 
        {
            currentAns = 1 + minJumpsHelper(arr, currIdx + i, dp);
        }
        minJumps = min(currentAns, minJumps);

        // Store the calculated answer in the dp array.
        dp[currIdx] = minJumps;
    }
    return minJumps;
}

int minJumps(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> dp(n, -1);

    return minJumpsHelper(arr, 0, dp);
}