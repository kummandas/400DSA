#include <bits/stdc++.h>
using namespace std;

int dx[3] = { -1, 0, 1 };
int dy[3] = { -1, -1, -1 };

bool isValid(int x, int y, int n, int m)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int maxGold(int n, int m, vector<vector<int> > M)
{
	int dp[n][m];

	// initialisation of first col
	for (int i = 0; i < n; i++)
		dp[i][0] = M[i][0];

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int mx = INT_MIN;
			for (int k = 0; k < 3; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (isValid(x, y, n, m))
					mx = max(mx, dp[x][y] + M[i][j]);
			}
			dp[i][j] = mx;
		}
	}

	int ans = INT_MIN;

	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i][m - 1]);
	}
	return ans;
}

int main()
{

	int n = 4;
	int m = 4;

	vector<vector<int> > gold = { { 1, 3, 1, 5 },
								{ 2, 2, 4, 1 },
								{ 5, 0, 2, 3 },
								{ 0, 6, 1, 2 } };

	cout << "Max Amount of gold collected = "
		<< maxGold(n, m, gold);
	return 0;
}









// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

int collectGold(vector<vector<int>> gold, int x, int y, int n, int m) {

	// Base condition.
	if ((x < 0) || (x == n) || (y == m)) {
		return 0;
	}


	// Right upper diagonal
	int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m);

	// right
	int right = collectGold(gold, x, y + 1, n, m);

	// Lower right diagonal
	int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m);

	// Return the maximum and store the value
	return gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right);
}

int getMaxGold(vector<vector<int>> gold, int n, int m)
{
	int maxGold = 0;

	for (int i = 0; i < n; i++) {

		// Recursive function call for ith row.
		int goldCollected = collectGold(gold, i, 0, n, m);
		maxGold = max(maxGold, goldCollected);
	}

	return maxGold;
}

// Driver Code
int main()
{
	vector<vector<int>> gold { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, n, m);
	return 0;
}












// C++ program to solve
// Gold Mine problem
#include <bits/stdc++.h>
using namespace std;

int MAX = 100;

// Returns maximum amount of
// gold that can be collected
// when journey started from
// first column and moves
// allowed are right, right-up
// and right-down
int getMaxGold(vector<vector<int>> gold, int m, int n)
{
// Create a table for storing
// intermediate results
// and initialize all cells to 0.
// The first row of
// goldMineTable gives the
// maximum gold that the miner
// can collect when starts that row
int goldTable[m][2];
for (int i = 0; i < m; i++)
{
	goldTable[i][0] = 0;
	goldTable[i][1] = 0;
}

for (int col = n - 1; col > -1; col--)
{
	for (int row = 0; row < m; row++)
	{
	int right, right_up, right_down;
	// Gold collected on going to
	// the cell on the right(->)
	if (col == n-1)
		right = 0;
	else
		right = goldTable[row][(col+1)%2];

	// Gold collected on going to
	// the cell to right up (/)
	if (row == 0 || col == n-1)
		right_up = 0;
	else
		right_up = goldTable[row-1][(col+1)%2];

	// Gold collected on going to
	// the cell to right down (\)
	if (row == m-1 || col == n-1)
		right_down = 0;
	else
		right_down = goldTable[row+1][(col+1)%2];

	// Max gold collected from taking
	// either of the above 3 paths
	goldTable[row][col%2] = gold[row][col] + max(right, max(right_up, right_down));
	}
}

// The max amount of gold
// collected will be the max
// value in first column of all rows
int res = goldTable[0][0];
for (int i = 1; i < m; i++)
	res = max(res, goldTable[i][0]);

return res;
}

// Driver code
int main()
{
int m = 4;
int n = 4;

vector<vector<int>> gold = {{ 1, 3, 1, 5},
							{2, 2, 4, 1},
							{5, 0, 2, 3},
							{0, 6, 1, 2}};


cout << getMaxGold(gold, m, n) << endl;
}

// This code is contributed
// by phasing17	
