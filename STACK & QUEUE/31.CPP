/*#include <queue>

bool valid_Constraints(int cr, int cc, int row, int col) {
    // this utility function will helps us avoid from trying to access any invalid index of our matrix.
    return (cr >= 0 && cr < row && cc >= 0 && cc < col);
}

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // n - row, m - col
    // queue is used for optimal approach i.e. BFS
    queue<pair<int, int>> q; 
    int rot_matrix[n][m], count_fresh_O = 0, timeFrames = -1;
    // 2d rot_matrix is declared which will be a copy of grid because we don't want to modified the original grid data.
    // count_fresh_O stores the count of fresh oranges in the matrix.
    // timeFrames keep track of the time.
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // copy the data of grid array to rot_Matrix
            rot_matrix[i][j] = grid[i][j];
            if(grid[i][j] == 2) {
                // push all the rotten oranges to queue.
                q.push({i, j});
            }
            // count the fresh oranges.
            if(grid[i][j] == 1) count_fresh_O++;
        }
    }
    // If there is no fresh oranges simply return 0 no need to check furthur.
    if(count_fresh_O == 0) return 0;
    // if q is empty it means there is no rotten oranges so return -1 as per the statement given.
    if(q.empty()) return -1;
    
    // otherwise if q is not empty continue below
    while(!q.empty()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            auto front = q.front();
            q.pop();
            // current adjacent row index
            int cr = front.first; 
            // current adjacent col index
            int cc = front.second;
            // rot the oranges below if possible
            if(valid_Constraints( cr + 1, cc, n, m ) && rot_matrix[cr + 1][cc] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr + 1][cc] = 2;
                // push to queue
                q.push({cr + 1, cc});
            }
            // rot the oranges above if possible
            if(valid_Constraints( cr - 1, cc, n, m ) && rot_matrix[cr - 1][cc] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr - 1][cc] = 2;
                // push to queue
                q.push({cr - 1, cc});
            }  
            // rot the right oranges if possible
            if(valid_Constraints( cr, cc + 1, n, m ) && rot_matrix[cr][cc + 1] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr][cc + 1] = 2;
                // push to queue
                q.push({cr, cc + 1});
            }  
            // rot the left oranges if possible
            if(valid_Constraints( cr, cc - 1, n, m ) && rot_matrix[cr][cc - 1] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr][cc - 1] = 2;
                // push to queue
                q.push({cr, cc - 1});
            }  
            
        }
        // increment the timeFrames after the first level traversal
        timeFrames++; 
    }
    // return the timeFrames if there is no more fresh oranges otherwise return -1.
    return (count_fresh_O == 0)?  timeFrames : -1; 
}
*/



/*/*
    Time Complexity - O(N * M)
    Space Complexity - O(N * M)

    where N and M are the number of rows and columns of
    the grid respectively.



#include <queue>


int isValid(vector<vector<bool>>& visited, int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false;
}

// BFS solution.
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int time = 0;

    // 2D array to mark visited cells.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // Queue for BFS.
    queue<pair<int, int>> q;

    // Push all the rotten oranges into the queue as level 0.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int i, j;

    // Array for exploring all 4 directions.
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(q.size() > 0)
    {
        // Current level size.
        int levelSize = q.size();

        while(levelSize--)
        {
            pair<int,int> currCell = q.front();
            q.pop();

            i = currCell.first;
            j = currCell.second;
            
            // Check all adjacent cells and push them in queue, if fresh and valid.
            for(int k = 0; k < 4; k++)
            {
                int nextI = i + dx[k];
                int nextJ = j + dy[k];

                if(isValid(visited, nextI, nextJ, n, m) && grid[nextI][nextJ] == 1)
                {
                    q.push({nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
        }

        // Increment time for next level.
        time++;
    }

    // If a fresh orange is still present, return -1.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == false)
            {
                return -1;
            }
        }
    }

    // Return time elapsed.
    return max(0, time - 1);
}*/












// C++ program to rot all oranges when u can move
// in all the four direction from a rotten orange
#include <bits/stdc++.h>
using namespace std;

const int R = 3;
const int C = 5;

// Check if i, j is under the array limits of row and column
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }

        // if no rotten orange found it means all
        // oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            // if any orange is found to be
            // not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }

    // Because initial value for a rotten
    // orange was 2
    return no - 2;
}

// Driver function
int main()
{

    int v[R][C] = { { 2, 1, 0, 2, 1 },
                    { 1, 0, 1, 2, 1 },
                    { 1, 0, 0, 2, 1 } };

    cout << "Max time incurred: " << rotOranges(v);

    return 0;
}







/*
    Time Complexity - O(N * M)
    Space Complexity - O(N * M)

    where N and M are the number of rows and columns of
    the grid respectively.
*/


#include <queue>


int isValid(vector<vector<bool>>& visited, int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false;
}

// BFS solution.
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int time = 0;

    // 2D array to mark visited cells.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // Queue for BFS.
    queue<pair<int, int>> q;

    // Push all the rotten oranges into the queue as level 0.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int i, j;

    // Array for exploring all 4 directions.
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(q.size() > 0)
    {
        // Current level size.
        int levelSize = q.size();

        while(levelSize--)
        {
            pair<int,int> currCell = q.front();
            q.pop();

            i = currCell.first;
            j = currCell.second;
            
            // Check all adjacent cells and push them in queue, if fresh and valid.
            for(int k = 0; k < 4; k++)
            {
                int nextI = i + dx[k];
                int nextJ = j + dy[k];

                if(isValid(visited, nextI, nextJ, n, m) && grid[nextI][nextJ] == 1)
                {
                    q.push({nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
        }

        // Increment time for next level.
        time++;
    }

    // If a fresh orange is still present, return -1.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == false)
            {
                return -1;
            }
        }
    }

    // Return time elapsed.
    return max(0, time - 1);
}