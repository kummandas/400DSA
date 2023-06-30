/*
    Time complexity: O(K*logK)
    Space complexity: O(1)
    
    Where K is max(size(horizontal), size(vertical)). 



#include <algorithm>


int boardCutting(vector<int>& horizontal, vector<int>& vertical, int m, int n)
{
    int mod = 1e9 + 7;

    long long int cost = 0;

    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());

    // Total segments of each type present currently 
    int hori = 1, verti = 1;

    
    int i = m - 2, j = n - 2 ;

    // Loop until both the cost arrays are processed
    while (i >= 0 || j >= 0)
    {
        if (j < 0 || i >= 0 && horizontal[i] > vertical[j])
        {
            cost = (cost + (((long long)horizontal[i] * verti) % mod)) % mod;

            hori++;
            i--;
        }
        else
        {
            cost = (cost + (((long long)vertical[j] * hori) % mod)) % mod;

            verti++;
            j--;
        }
    }

    return cost;
}
*/









// C++ program to divide a board into m*n squares
#include <bits/stdc++.h>
using namespace std;

// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
	int res = 0;

	// sort the horizontal cost in reverse order
	sort(X, X + m, greater<int>());

	// sort the vertical cost in reverse order
	sort(Y, Y + n, greater<int>());

	// initialize current width as 1
	int hzntl = 1, vert = 1;

	// loop until one or both cost array are processed
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (X[i] > Y[j])
		{
			res += X[i] * vert;

			// increase current horizontal part count by 1
			hzntl++;
			i++;
		}
		else
		{
			res += Y[j] * hzntl;

			// increase current vertical part count by 1
			vert++;
			j++;
		}
	}

	// loop for horizontal array, if remains
	int total = 0;
	while (i < m)
		total += X[i++];
	res += total * vert;

	// loop for vertical array, if remains
	total = 0;
	while (j < n)
		total += Y[j++];
	res += total * hzntl;

	return res;
}

// Driver code to test above methods
int main()
{
	int m = 6, n = 4;
	int X[m-1] = {2, 1, 3, 1, 4};
	int Y[n-1] = {4, 1, 2};
	cout << minimumCostOfBreaking(X, Y, m-1, n-1);
	return 0;
}
