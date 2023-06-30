// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y)
// can be visited or not
bool isSafe(int mat[R][C], int visited[R][C],
			int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;

	return true;
}

// A function to check if a given cell (x, y) is
// a valid cell or not
bool isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
void markUnsafeCells(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			// if a landmines is found
			if (mat[i][j] == 0)
			{
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
				if (isValid(i + rowNum[k], j + colNum[k]))
					mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}

	// mark all found adjacent cells as unsafe
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	// Uncomment below lines to print the path
	/*for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << std::setw(3) << mat[i][j];
		}
		cout << endl;
	}*/
}

// Function to find shortest safe Route in the
// matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in
// current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
void findShortestPathUtil(int mat[R][C], int visited[R][C],
						int i, int j, int &min_dist, int dist)
{
	// if destination is reached
	if (j == C-1)
	{
		// update shortest path found so far
		min_dist = min(dist, min_dist);
		return;
	}

	// if current path cost exceeds minimum so far
	if (dist > min_dist)
		return;

	// include (i, j) in current path
	visited[i][j] = 1;

	// Recurse for all safe adjacent neighbours
	for (int k = 0; k < 4; k++)
	{
		if (isValid(i + rowNum[k], j + colNum[k]) &&
			isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
		{
			findShortestPathUtil(mat, visited, i + rowNum[k],
						j + colNum[k], min_dist, dist + 1);
		}
	}

	// Backtrack
	visited[i][j] = 0;
}

// A wrapper function over findshortestPathUtil()
void findShortestPath(int mat[R][C])
{
	// stores minimum cost of shortest path so far
	int min_dist = INT_MAX;

	// create a boolean matrix to store info about
	// cells already visited in current route
	int visited[R][C];

	// mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat);

	// start from first column and take minimum
	for (int i = 0; i < R; i++)
	{
		// if path is safe from current cell
		if (mat[i][0] == 1)
		{
			// initialize visited to false
			memset(visited, 0, sizeof visited);

			// find shortest route from (i, 0) to any
			// cell of last column (x, C - 1) where
			// 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0,
								min_dist, 0);

			// if min distance is already found
			if(min_dist == C - 1)
				break;
		}
	}

	// if destination can be reached
	if (min_dist != INT_MAX)
		cout << "Length of shortest safe route is "
			<< min_dist;

	else // if the destination is not reachable
		cout << "Destination not reachable from "
			<< "given source";
}

// Driver code
int main()
{
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	findShortestPath(mat);

	return 0;
}



/*/*
    Time complexity: O(3^(M*N))
    Space complexity: O(M*N)
    
    Where 'M' is the number of rows, 
    'N' is the number of columns in the field.


bool isValid(int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return false;
    }

    return true;
}

void markUnsafeCells(vector<vector<int>> &field, const int direction[4][2])
{
    // Find the number of rows in the field.
    int m = field.size();

    // Find the number of columns in the field.
    int n = field[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Cell contains a landmine.
            if (field[i][j] == 0)
            {
                // Mark all neighbouring unsafe cells as -1.
                for (int k = 0; k < 4; k++)
                {
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];

                    if (isValid(x, y, m, n) && field[x][y] == 1)
                    {
                        field[x][y] = -1;
                    }
                }
            }
        }
    }

    // Mark all the unsafe cells as 0.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] == -1)
            {
                // Cell is unsafe.
                field[i][j] = 0;
            }
        }
    }
}

void shortestPathHelper(vector<vector<int>> &field, vector<vector<bool>> &visited, int i, int j, int &minLength, int curLength, const int direction[4][2])
{
    // Find the number of rows in the field.
    int m = field.size();

    // Find the number of columns in the field.
    int n = field[0].size();

    if (j == n - 1)
    {
        // Generated a valid path. So, update the shortest path length.
        minLength = min(minLength, curLength);
        return;
    }

    if (curLength >= minLength)
    {
        // Path being generated is longer than the shortest path found so far.
        return;
    }

    visited[i][j] = true;

    // Move to the adjacent cells.
    for (int k = 0; k < 4; k++)
    {
        int x = i + direction[k][0];
        int y = j + direction[k][1];

        if (isValid(x, y, m, n) && field[x][y] == 1 && visited[x][y] == false)
        {
            // If the cell is safe and not visited before, then add it to the current path.
            shortestPathHelper(field, visited, x, y, minLength, curLength + 1, direction);
        }
    }

    // Backtrack to the previous cell.
    visited[i][j] = false;
}

int shortestPath(vector<vector<int>> &field)
{
    // Find the number of rows in the field.
    int m = field.size();

    // Find the number of columns in the field.
    int n = field[0].size();

    int minLength = INT_MAX;

    const int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Mark all the unsafe cells as 0 instead of 1.
    markUnsafeCells(field, direction);

    for (int i = 0; i < m; i++)
    {
        if (field[i][0] == 1)
        {
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            // Generate the path starting from the current cell.
            shortestPathHelper(field, visited, i, 0, minLength, 0, direction);

            if (minLength == n - 1)
            {
                break;
            }
        }
    }

    if (minLength == INT_MAX)
    {
        // No valid path exists.
        return -1;
    }

    return minLength;
}*/