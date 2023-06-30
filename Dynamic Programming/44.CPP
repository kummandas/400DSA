/*int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    if(n==1){
		        return 1;
		    }
		   vector<array<int,2>> dp(n+2);
		  // > < > < > < > < > 
		  // < > < > < > < > < 
		   // zero is for 1st type of sequence and 1 is for the other 
		   // these are the base cases // 
		   dp[0][0] = 1;
		   dp[0][1] = 1;
		   // min ans can be 1 //
		   int ans = 1;
		  // dp[i][0]  here  represents the max. length of patten upto index i ending at 
		  // > greater than sign 
		  // dp[i][1] represents the max length of the pattern upto index i ending at 
		  // < less than sign 
		  for(int i=1;i<n;i++){
		        
		       if(nums[i-1]>nums[i]){
		           dp[i][0] = dp[i-1][1] + 1;
		       }
		       if(nums[i-1]<nums[i]){
		            dp[i][1] = dp[i-1][0] + 1;
		       }
		       dp[i][0] = max(dp[i][0],dp[i-1][0]);
		       dp[i][1] = max(dp[i][1],dp[i-1][1]);
		       
		    }
		
		    return max(dp[n-1][0],dp[n-1][1]);
		}
		//another idea : This question can also be done by making 2 dps -> dp1 and dp2 
        // one for each pattern and then dp1 will depend on dp2 and dp2 will depend on 
        // dp1 , this type of idea where we need make more than 1 dp and one dp is depend 
        // on other is used in harder problems
        
        // also u can optimise the space in this by a simple observation do it a*/



// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function for finding
// longest alternating
// subsequence
int LAS(int arr[], int n)
{

    // "inc" and "dec" initialized as 1
    // as single element is still LAS
    int inc = 1;
    int dec = 1;

    // Iterate from second element
    for (int i = 1; i < n; i++) 
    {

        if (arr[i] > arr[i - 1]) 
        {

            // "inc" changes iff "dec" 
            // changes
            inc = dec + 1;
        }

        else if (arr[i] < arr[i - 1]) 
        {

            // "dec" changes iff "inc" 
            // changes
            dec = inc + 1;
        }
    }

    // Return the maximum length
    return max(inc, dec);
}

// Driver Code
int main()
{
    int arr[] = { 10, 22, 9, 33, 49, 
                           50, 31, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    cout << LAS(arr, n) << endl;
    return 0;
}




// C++ program to find longest alternating 
// subsequence in an array
#include<iostream>
using namespace std;
 
// Function to return max of two numbers
int max(int a, int b)
{ 
    return (a > b) ? a : b;
}
 
// Function to return longest alternating 
// subsequence length
int zzis(int arr[], int n)
{
    
    /*las[i][0] = Length of the longest 
        alternating subsequence ending at
        index i and last element is greater
        than its previous element
    las[i][1] = Length of the longest 
        alternating subsequence ending 
        at index i and last element is
        smaller than its previous element */
    int las[n][2];
 
    // Initialize all values from 1 
    for(int i = 0; i < n; i++)
        las[i][0] = las[i][1] = 1;
    
    // Initialize result
    int res = 1; 
 
    // Compute values in bottom up manner 
    for(int i = 1; i < n; i++)
    {
        
        // Consider all elements as 
        // previous of arr[i]
        for(int j = 0; j < i; j++)
        {
            
            // If arr[i] is greater, then 
            // check with las[j][1]
            if (arr[j] < arr[i] && 
                las[i][0] < las[j][1] + 1)
                las[i][0] = las[j][1] + 1;
 
            // If arr[i] is smaller, then 
            // check with las[j][0]
            if(arr[j] > arr[i] && 
               las[i][1] < las[j][0] + 1)
                las[i][1] = las[j][0] + 1;
        }
 
        // Pick maximum of both values at index i 
        if (res < max(las[i][0], las[i][1]))
            res = max(las[i][0], las[i][1]);
    }
    return res;
}
 
// Driver code
int main()
{
    int arr[] = { 10, 22, 9, 33, 
                  49, 50, 31, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Length of Longest alternating "
         << "subsequence is " << zzis(arr, n);
         
    return 0;
}

