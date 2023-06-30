/* int solve(int i, int j, vector<vector<int>> &mat, int &maxi){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        int right = solve(i, j+1, mat, maxi);
        int diagonal = solve(i+1, j+1, mat, maxi);
        int down = solve(i+1, j, mat, maxi);
        
        if(mat[i][j] == 1){
            int ans = 1 + min(right, min(diagonal, down));
            
            maxi = max(maxi, ans);
            
            return ans;
        }
        else
            return 0;
    }
    
    int solveMem(int i, int j, vector<vector<int>> &mat, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solveMem(i, j+1, mat, maxi, dp);
        int diagonal = solveMem(i+1, j+1, mat, maxi, dp);
        int down = solveMem(i+1, j, mat, maxi, dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            
            maxi = max(maxi, dp[i][j]);
            
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }
    
    int solveTab(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row+1, vector<int> (col+1, 0));
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return 0;
    }
    
    int solveSpaceOP1(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col, 0);
        vector<int> next(col+1, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            
            next = curr;
        }
        
        return 0;
    }
    
    // HOMEWORK
    // Here Space Complexity is O(1) as n and m at max can be 50 
    // By referring to the constraints in problem statment :- 1<= n, m <= 50
    int solveSpaceOP2(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(50, 0);
        vector<int> next(51, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            
            next = curr;
        }
        
        return 0;
    }
    
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        // RECURSION
        /*
        int maxi = 0;
        solve(0, 0, mat, maxi);
        
        return maxi;
        */
        
        // RECURSION + MEMOIZATION
        /*
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        int maxi = 0;
        
        solveMem(0, 0, mat, maxi, dp);
        
        return maxi;
        */
        
        // TABULATION
        /*
        int maxi = 0;
        
        solveTab(mat, maxi);
        
        return maxi;
        */
        
        // SPACE OPTIMIZATION - 1
        /*
        int maxi = 0;
        
        solveSpaceOP(mat, maxi);
        
        return maxi;
        
        
        // SPACE OPTIMIZATION - 2 --> HW Que --> S.C. = O(1)
        int maxi = 0;
        
        solveSpaceOP2(mat, maxi);
        
        return maxi;
    }*/


    /*/*
    Time Complexity: O(N * M)
    Space Complexity: O(1)

    where N is the number of rows and
    M is the number of columns of the grid.



int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
{
    int maxSquareSide = 0;

    for (int i = 0; i < n; i++)
    {
        if (MAT[i][0] == 1)
        {
            maxSquareSide = 1;
            break;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (MAT[0][j] == 1)
        {
            maxSquareSide = 1;
            break;
        }
    }


    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (MAT[i][j] == 1)
            {
                MAT[i][j] = 1 + min(MAT[i - 1][j], min(MAT[i][j - 1], MAT[i - 1][j - 1]));

                maxSquareSide = max(maxSquareSide, MAT[i][j]);
            }
        }
    }

    return maxSquareSide * maxSquareSide;
}

*/


// C++ code for Maximum size square
// sub-matrix with all 1s
// (space optimized solution)
#include <bits/stdc++.h>

using namespace std;

#define R 6
#define C 5

void printMaxSubSquare(bool M[R][C])
{
	int S[2][C], Max = 0;

	// set all elements of S to 0 first
	memset(S, 0, sizeof(S));

	// Construct the entries
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {

			// Compute the entry at the current position
			int Entrie = M[i][j];
			if (Entrie)
				if (j)
					Entrie
						= 1
						+ min(S[1][j - 1],
								min(S[0][j - 1], S[1][j]));

			// Save the last entry and add the new one
			S[0][j] = S[1][j];
			S[1][j] = Entrie;

			// Keep track of the max square length
			Max = max(Max, Entrie);
		}

	// Print the square
	cout << "Maximum size sub-matrix is: \n";
	for (int i = 0; i < Max; i++, cout << '\n')
		for (int j = 0; j < Max; j++)
			cout << "1 ";
}

// Driver code
int main()
{
	bool M[R][C] = { { 0, 1, 1, 0, 1 }, { 1, 1, 0, 1, 0 },
					{ 0, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0 },
					{ 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 } };

	printMaxSubSquare(M);

	return 0;

	// This code is contributed
	// by Gatea David
}
