/*#include <bits/stdc++.h> 
#include<bits/stdc++.h>
int helper(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
    
    if(i<0 || j<0 ){
        return 1e9;
    }
    if(i==0 && j==0){
        return arr[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=arr[i][j]+helper(i-1,j,n,m,arr,dp);
    int left=arr[i][j]+helper(i,j-1,n,m,arr,dp);
    int upleft=arr[i][j]+helper(i-1,j-1,n,m,arr,dp);
    int ans=min(upleft,min(up,left));
    dp[i][j]=ans;
    return dp[i][j];
}
int getMinPathSum(vector<vector<int>> &arr)
{
    //  Write your code here.
    int n=arr.size();
    int m=arr[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=helper(n-1,m-1,n,m,arr,dp);
    return ans;
}
*/


/*
    Time Complexity : O(N*M)
    Space Complexity : O(1)
    
    Where ‘N’ is the number of rows and ‘M’ is the number of columns in the given matrix.

#include <climits>

//  x-directions and y-directions
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

//  an auxilary function to check if a given (row, col) is inside the boundary or not
bool isValid(int row, int col, int n, int m)
{
    return (row >= 0 && col >= 0 && row < n && col < m);
}

int getMinPathSum(vector<vector<int>> &matrix)
{
   
    int n = matrix.size();
    int m = matrix[0].size();
    
    //  iterating through the matrix
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            //  Initialize currPathSum to a large number
            int currPathSum = INT_MAX;

            if (row == 0 && col == 0)
            {
                //  (0, 0)th cell is the first cell in any possible path
                continue;
            }

            //  Start exploring the possible previous options for getting the minimum path sum from (0, 0) to (row, col)
            for (int i = 0; i < 3; i++)
            {
                //  Get new cell
                int prevRow = row - dx[i];
                int prevCol = col - dy[i];

                //  Check whether new cell is a valid cell or not?
                if (isValid(prevRow, prevCol, n, m))
                {
                    currPathSum = min(currPathSum, matrix[prevRow][prevCol]);
                }
            }

            //  Update the matrix such that (row, col)th value contains min cost path sum from (0, 0) to (row, col)
            matrix[row][col] = currPathSum + matrix[row][col];
            
        }

        
    }

    return matrix[n-1][m-1];
}*/

/*class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix){
        vector<int> prev(N, 0);
        
        for(int j=0;j<N;j++) prev[j] = Matrix[0][j];
        
        for(int i=1;i<N;i++){
            vector<int> cur(N, 0);
            for(int j=0;j<N;j++){
                int up = Matrix[i][j] + prev[j];
                
                int ld = Matrix[i][j];
                (j >= 0)? ld += prev[j-1] : ld += -1e9;
                
                int rd = Matrix[i][j];
                (j+1 < N)? rd += prev[j+1] : rd += -1e9;
                
                cur[j] = max(up, max(ld, rd));
            }
            prev = cur;
        }
        
        int maxi = INT_MIN;
        
        for(int j=0;j<N;j++){
            maxi = max(maxi, prev[j]);
        }
        return maxi;
    }
};*/














// C++ program to find the longest path in a matrix
// with given constraints
#include <bits/stdc++.h>
#define n 3
using namespace std;

// Returns length of the longest path beginning with
// mat[i][j]. This function mainly uses lookup table
// dp[n][n]
int findLongestFromACell(int i, int j, int mat[n][n],
						int dp[n][n])
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return 0;

	// If this subproblem is already solved
	if (dp[i][j] != -1)
		return dp[i][j];

	// To store the path lengths in all the four directions
	int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;

	// Since all numbers are unique and in range from 1 to
	// n*n, there is atmost one possible direction from any
	// cell
	if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
		x = 1 + findLongestFromACell(i, j + 1, mat, dp);

	if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1]))
		y = 1 + findLongestFromACell(i, j - 1, mat, dp);

	if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j]))
		z = 1 + findLongestFromACell(i - 1, j, mat, dp);

	if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
		w = 1 + findLongestFromACell(i + 1, j, mat, dp);

	// If none of the adjacent fours is one greater we will
	// take 1 otherwise we will pick maximum from all the
	// four directions
	return dp[i][j] = max({x, y, z, w, 1});
}

// Returns length of the longest path beginning with any
// cell
int finLongestOverAll(int mat[n][n])
{
	int result = 1; // Initialize result

	// Create a lookup table and fill all entries in it as
	// -1
	int dp[n][n];
	memset(dp, -1, sizeof dp);

	// Compute longest path beginning from all cells
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1)
				findLongestFromACell(i, j, mat, dp);

			// Update result if needed
			result = max(result, dp[i][j]);
		}
	}

	return result;
}

// Driver program
int main()
{
	int mat[n][n]
		= { { 1, 2, 9 }, { 5, 3, 8 }, { 4, 6, 7 } };
	cout << "Length of the longest path is "
		<< finLongestOverAll(mat);
	return 0;
}
