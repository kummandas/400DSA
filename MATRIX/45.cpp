// A Program to prints common element in all
// rows of matrix
#include <bits/stdc++.h>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;

	// initialize 1st row elements with value 1
	for (int j = 0; j < N; j++)
		mp[(mat[0][j])] = 1;

	// traverse the matrix
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// If element is present in the map and
			// is not duplicated in current row.
			if (mp[(mat[i][j])] == i)
			{
			// we increment count of the element
			// in map by 1
				mp[(mat[i][j])] = i + 1;

				// If this is last row
				if (i==M-1 && mp[(mat[i][j])]==M)
				cout << mat[i][j] << " ";
			}
		}
	}
}

// driver program to test above function
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}





/*
    Time Complexity: O(N*M)
    Space Complexity: O(M)
    
    Where 'N' and 'M' denotes the number of rows 
    and the number of columns in the matrix respectively.
*/

#include <unordered_map>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Finding the number of rows and columns
    int n = mat.size();
    int m = mat[0].size();

    // Defining the HashMap to store common elements
    unordered_map<int, int> commonElements;

    // Adding the elements of first row to HashMap
    for (int j = 0; j < m; j++)
    {
        commonElements[mat[0][j]] = 1;
    }

    // Iterating through the elements of the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Checking whether the current element is present in all the previously traversed rows
            if (commonElements.find(mat[i][j]) != commonElements.end() && commonElements[mat[i][j]] == i)
            {
                commonElements[mat[i][j]]++;
            }
        }
    }

    // Defining the output array
    vector<int> ans;

    // Traversing the HashMap
    for (pair<int, int> p : commonElements)
    {
        // Adding all elements that are present in all the matrix rows to the output array
        if (p.second == n)
        {
            ans.push_back(p.first);
        }
    }

    // Returning the output array
    return ans;
}

