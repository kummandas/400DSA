/*/*
    Time complexity: O(N^2*M^2)
    Space complexity: O(1)

    where N is the number of rows and M is the number of columns.


#include <climits>

vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Initialize the answer matrix with INT_MAX.
    vector < vector < int >> dist(n, vector < int > (m, INT_MAX));

    // For each cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /* 
                Traversing the whole matrix to find the minimum distance.
            
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    // If cell contain 1, check for minimum distance.
                    if (mat[k][l] == 1) {
                        dist[i][j] = min(dist[i][j], abs(i - k) + abs(j - l));
                    }
                }
            }
        }
    }
    return dist;
}
*/



/* //Function to find distance of nearest 1 in the grid for each cell.
    /*
    Hello everyone this is a standerd bfs question as this question asks for
    minimum distance from 1. To solve this question we need to follow thease steps.
    
     1.Take all 1's as the base level like a root of tree.
     2.Now make a answer matrix and initialize with -1.
     3.Find all 1 and push it to queue and update its distance to 0 in the answer matrix.
     4.Now traverse to all child of the 1's if the answer[i][j] of the child is -1 then update
     the answer by adding 1 to the distance of its parent.
     5.Finally return the answer matrix
     
     Similar question:
     Rotten oranges
     Knight Walk
     
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(row,vector<int>(col,-1));
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==1) {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    int dx[] = {0, 0, 1, -1};
	    int dy[] = {1, -1, 0 , 0};
	    
	    int level=0;
	    
	    while(!q.empty())
	    {
	        int size = q.size();
	        for(int i=0;i<size;i++) {
	            int a = q.front().first;
	            int b = q.front().second;
	            q.pop();
	            
	            for(int k=0;k<4;k++)
	            {
	                int na = a+dx[k];
	                int nb = b+dy[k];
	                
	                if(na<0||nb<0||na>=row||nb>=col||ans[na][nb]!=-1) continue;
	                q.push({na,nb});
	                ans[na][nb]=ans[a][b]+1;
	            }
	        }
	    }
	    return ans;
	}*/




    /*class Solution
{
    public:
	vector<int>dx = {1,-1,0,0};
	vector<int>dy = {0,0,1,-1};
	
	//Function to check whether the cell is within the matrix bounds.
	bool isValid(int x, int y, int n, int m){
		return (x >=0 and x < n and y >=0 and y < m);
	}
	
	//Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		
		//queue to store the cell indexes which have grid value 1.
		queue<pair<int, int>>q;
		
		//using dp list which will store the output.
		vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
		
		//traversing all the cells of the matrix.
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
			    //if grid value is 1, we update the dp value at same cell as 0 
			    //and push the cell indexes into queue.
				if(grid[i][j] == 1){
					dp[i][j] = 0;
					q.push({i,j});
				}
			}
		}
		
		while(!q.empty())
		{
		    //storing the cell indexes at top of queue and popping them.
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			//iterating over the adjacent cells.
			for(int i = 0; i < 4; i++)
			{
				int n_x = x + dx[i];
				int n_y = y + dy[i];
				if(isValid(n_x, n_y, n, m) and dp[n_x][n_y] > dp[x][y] + 1)
				{
				    //updating dp and pushing cell indexes in queue.
					dp[n_x][n_y] = dp[x][y] + 1;
					q.push({n_x, n_y});
				}
			}
		}
		//returning the dp list.
		return dp;
	}
};*/











// C++ program to find distance of nearest
// cell having 1 in a binary matrix.
#include <bits/stdc++.h>
#define N 3
#define M 4
using namespace std;

// Print the distance of nearest cell
// having 1 for each cell.
void printDistance(int mat[N][M])
{
	int ans[N][M];

	// Initialize the answer matrix with INT_MAX.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans[i][j] = INT_MAX;

	// For each cell
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			// Traversing the whole matrix
			// to find the minimum distance.
			for (int k = 0; k < N; k++)
				for (int l = 0; l < M; l++) {
					// If cell contain 1, check
					// for minimum distance.
					if (mat[k][l] == 1)
						ans[i][j]
							= min(ans[i][j],
								abs(i - k) + abs(j - l));
				}
		}

	// Printing the answer.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << ans[i][j] << " ";

		cout << endl;
	}
}

// Driver code
int main()
{
	int mat[N][M] = { 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0 };

	// Function call
	printDistance(mat);

	return 0;
}












/*
    Time complexity: O(N*M)
    Space complexity: O(N*M)

    where N is the number of rows and M is the number of columns.
*/

#include <climits>

vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {

    queue < pair < int, int >> q;
    vector < vector < int >> dist(n, vector < int > (m, INT_MAX));

    // Push the coordinates of cells containing 1 in the queue.
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 1) {
                q.push({
                    i,
                    j
                });
                dist[i][j] = 0;
            }
        }
    }
    // To move up, down, left, right.
    int x_dir[] = {-1, 0, 1, 0};
    int y_dir[] = {0, -1, 0, 1};

    // BFS performed.
    while (!q.empty()) {
        pair < int, int > temp = q.front();

        int i = temp.first;
        int j = temp.second;
        q.pop();

        // All adjacent cells checked.
        for (int k = 0; k < 4; k++) {
            int x_new = i + x_dir[k];
            int y_new = j + y_dir[k];

            // Conditions to check if adjacent cell lie in matrix and to minimum distance is updated.
            if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && dist[x_new][y_new] > dist[i][j] + 1) {
                dist[x_new][y_new] = dist[i][j] + 1;
                q.push({
                    x_new,
                    y_new
                });
            }
        }
    }
    return dist;
}M