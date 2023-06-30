/*// Back-end complete function template for C++

vector<vector<int>> visited(5, vector<int> (5,0));
vector<string> result;

class Solution{
    public:
    void path(vector<vector<int>> &m, int x, int y, string dir, int n) {
        if (x == n - 1 and y == n - 1) {
            result.push_back(dir);
            return;
        }
    
        if (m[x][y] == 0 or visited[x][y] == 1) return;
    
        // DFS
        visited[x][y] = 1;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        result.clear();
    
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return result;
    
        path(m, 0, 0, "", n);
    
        sort(result.begin(), result.end());
        return result;
    }
};*/



/*/*
    Time complexity: O(3^(N^2))
    Space Complexity: O(N^2)

    where N is the size of array/list ARR.

bool isValidMove(int y, int x, vector < vector < int >> & arr, vector < vector < bool >> & visited) {

    if (x == -1 || x == arr.size() || y == -1 || y == arr.size() || visited[y][x] || arr[y][x] == 0) {
        return false;
    }

    return true;
}

void printPathUtil(vector < vector < int >> & arr, int y, int x, string path, vector < string > & pathList, vector < vector < bool >> & visited) {
    
    // This will check the initial point(i.e. (0, 0)) to start the paths.
    if (x == -1 || x == arr.size() || y == -1 || y == arr.size() || visited[y][x] || arr[y][x] == 0) {
        return;
    }

    // If reach the last cell (n-1, n-1) then store the path and return.
    if (x == arr.size() - 1 and y == arr.size() - 1) {
        pathList.push_back(path);
        return;
    }

    visited[y][x] = true;

    // Try for all the 4 directions (down, left, right, up) 
    // in the given order to get the paths in lexicographical order.

    if (isValidMove(y + 1, x, arr, visited)) {
        path += "D";
        printPathUtil(arr, y + 1, x, path, pathList, visited);
        path.pop_back();
    }

    if (isValidMove(y, x - 1, arr, visited)) {
        path += "L";
        printPathUtil(arr, y, x - 1, path, pathList, visited);
        path.pop_back();
    }

    if (isValidMove(y, x + 1, arr, visited)) {
        path += "R";
        printPathUtil(arr, y, x + 1, path, pathList, visited);
        path.pop_back();
    }

    if (isValidMove(y - 1, x, arr, visited)) {
        path += "U";
        printPathUtil(arr, y - 1, x, path, pathList, visited);
        path.pop_back();
    }

    // Mark the cell as unvisited for other possible paths.
    visited[y][x] = false;

}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    // Vector to store the answer.
    vector < string > possiblePaths;
    string path = "";

    vector < vector < bool >> visited(n, vector < bool > (n, false));

    printPathUtil(arr, 0, 0, path, possiblePaths, visited);

    return possiblePaths;
}*/












// C++ implementation of the above approach
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

// Function returns true if the
// move taken is valid else
// it will return false.
bool isSafe(int row, int col, int m[][MAX],
				int n, bool visited[][MAX])
{
	if (row == -1 || row == n || col == -1 ||
				col == n || visited[row][col]
						|| m[row][col] == 0)
		return false;

	return true;
}

// Function to print all the possible
// paths from (0, 0) to (n-1, n-1).
void printPathUtil(int row, int col, int m[][MAX],
			int n, string& path, vector<string>&
			possiblePaths, bool visited[][MAX])
{
	// This will check the initial point
	// (i.e. (0, 0)) to start the paths.
	if (row == -1 || row == n || col == -1
			|| col == n || visited[row][col]
						|| m[row][col] == 0)
		return;

	// If reach the last cell (n-1, n-1)
	// then store the path and return
	if (row == n - 1 && col == n - 1) {
		possiblePaths.push_back(path);
		return;
	}

	// Mark the cell as visited
	visited[row][col] = true;

	// Try for all the 4 directions (down, left,
	// right, up) in the given order to get the
	// paths in lexicographical order

	// Check if downward move is valid
	if (isSafe(row + 1, col, m, n, visited))
	{
		path.push_back('D');
		printPathUtil(row + 1, col, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the left move is valid
	if (isSafe(row, col - 1, m, n, visited))
	{
		path.push_back('L');
		printPathUtil(row, col - 1, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the right move is valid
	if (isSafe(row, col + 1, m, n, visited))
	{
		path.push_back('R');
		printPathUtil(row, col + 1, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the upper move is valid
	if (isSafe(row - 1, col, m, n, visited))
	{
		path.push_back('U');
		printPathUtil(row - 1, col, m, n,
			path, possiblePaths, visited);
		path.pop_back();
	}

	// Mark the cell as unvisited for
	// other possible paths
	visited[row][col] = false;
}

// Function to store and print
// all the valid paths
void printPath(int m[MAX][MAX], int n)
{
	// vector to store all the possible paths
	vector<string> possiblePaths;
	string path;
	bool visited[n][MAX];
	memset(visited, false, sizeof(visited));
	
	// Call the utility function to
	// find the valid paths
	printPathUtil(0, 0, m, n, path,
					possiblePaths, visited);

	// Print all possible paths
	for (int i = 0; i < possiblePaths.size(); i++)
		cout << possiblePaths[i] << " ";
}

// Driver code
int main()
{
	int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 0, 1 },
						{ 0, 0, 0, 0, 1 },
						{ 0, 0, 0, 0, 1 } };
	int n = sizeof(m) / sizeof(m[0]);
	printPath(m, n);

	return 0;
}
