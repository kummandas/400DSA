/*#include <bits/stdc++.h> 
bool ispalindr(string str,int i,int j){
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

//recursion code

// int partition(string str,int i,int j){
//     if(i>=j || ispalindr(str,i,j)){
//         return 0;
//     }
//     int ans=INT_MAX,count;
//     for(int k=i;k<j;k++){
//         if(ispalindr(str,i,k)){
//         count=partition(str,k+1,j)+1;
//         ans=min(ans,count);
//         }
//     }
//     return ans;
// }


//optimised it with storing all repetetions in recursion

int cuts(string str,int i,int j,vector<vector<int>> &dp){
    if(i>=j or ispalindr(str,i,j)){
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX,count;
    for(int k=i;k<j;k++){
        if(ispalindr(str,i,k)){
        count=cuts(str,k+1,j,dp)+1;
        ans=min(ans,count);
        }
        dp[i][j]=ans;
    }
    return dp[i][j];
}


int minimumCuts(string str) {
	// Write your code here.	
    int n=str.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return cuts(str,0,n-1,dp);
    
//     return partition(str,0,n-1);
}*/











/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N ^ 2)

    where N is the length of the string 'STR'. 


#include<climits>

int minimumCuts(string str){
	int n = str.size();
	vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));

	// Each character is a palindrome.
	for (int i = 0; i < n; i++) { 
        isPalindrome[i][i] = true; 
    } 

    // Loop to consider substrings of all sizes.
	for(int size = 2; size <= n; size++){
		int currentLength = n - size + 1; 

		// Loop to select the starting index of the substring.	
		for(int i = 0; i < currentLength; i++){

			// Ending index of the substring
			int j = i + size - 1;

			// If the length of the substring is 2, compare the both characters. 
			if(size == 2){

				if(str[i] == str[j]){
					isPalindrome[i][j] = true;
				}	
			}
			else{

				// If the corner characters are same and the substring str[i + 1... j - 1] is a palindrome.
				if(str[i] == str[j] and isPalindrome[i + 1][j - 1] == true){
					isPalindrome[i][j] = true;
				}
			}
		}
	}

	vector<int>cuts(n, INT_MAX);

	for (int i = 0; i < n; i++){ 

		// If substring[0...i] is a palindrome.
        if (isPalindrome[0][i] == true){
            cuts[i] = 0; 
        }
        else {

        	// Update the cuts array to find the minimum number of cuts.
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j + 1][i] == true and 1 + cuts[j] < cuts[i]){
                    cuts[i] = cuts[j] + 1; 
                }
            } 
        } 
    } 

    // Return the final answer.
	return cuts[n - 1];
}*/


/*/*
	Time Complexity: O(N ^ 3)
	Space Complexity: O(N ^ 2)

	where N is the length of the string 'STR'.


#include<climits>

// Function to check whether the string is a palindrome or not.
bool isPalindrome(string str, int start, int end){

	while(start <= end){

		if(str[start] != str[end]){
			return false;
		}

		start++;
		end--;
	}  

	return true;
}


int minimumCuts(string str){
	int n = str.size();
	vector<vector<int>>cuts(n, vector<int>(n, INT_MAX));

	// If there is only one character, 0 cuts are required.
	for (int i = 0; i < n; i++){ 
        cuts[i][i] = 0; 
    } 

    // Loop to consider substrings of all sizes.
	for(int size = 2; size <= n; size++){
		int currentLength = n - size + 1; 

		// Loop to select the starting index of the substring.	
		for(int i = 0; i < currentLength; i++){

			// Ending index of the substring.
			int j = i + size - 1;

			// If the current substring is a palindrome.
			if(isPalindrome(str, i, j) == true){
				cuts[i][j] = 0;
			}
			else{

				// Loop to make a cut at every position.
				for(int k = i; k < j; k++){

					// Update cost matrix to get the minimum cuts.
					cuts[i][j] = min(cuts[i][j], cuts[i][k] + 1 + cuts[k + 1][j]);
				}
			}
		}
	}

	return cuts[0][n - 1];
}*/




// C++ Code for Palindrome Partitioning
// Problem
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false;  
      i++;
      j--;
    }
    return true;
}
int minPalPartion(string String, int i, int j)
{
    if( i >= j || isPalindrome(String, i, j) )
      return 0;
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
      count = minPalPartion(String, i, k) + 
        minPalPartion(String, k + 1, j) + 1;
 
      ans = min(ans, count);
    }
    return ans;
}
// Driver code
int main() {
    string str = "ababbbabbababa";
    cout << "Min cuts needed for " << 
      "Palindrome Partitioning is " <<  
      minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}
// This code is contributed by rag2127