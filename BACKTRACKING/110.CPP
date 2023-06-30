#include<bits/stdc++.h>
using namespace std;

// function to display the path
void display(vector<int> &ans) {
for(auto i :ans ) {
	cout<<i <<" ";
}
cout<<endl;
}

// a function which check whether our step is safe or not
bool issafe(int r,int c,vector<vector<int>>& visited,int n,int m) {
return (r < n and c <m and visited[r] !=-1 ); // return true if all values satisfied else false
}


void FindPaths(vector<vector<int>> &grid,int r,int c, int n,int m,vector<int> &ans) {
// when we hit the last cell we reach to destination then directly push the path
if(r == n-1 and c == m-1) {
	ans.push_back(grid[r]);
	display(ans); // function to display the path stored in ans vector
	ans.pop_back(); // pop back because we need to backtrack to explore more path
	return ;
}

// we will store the current value in ch and mark the visited place as -1
int ch = grid[r];

ans.push_back(ch); // push the path in ans array
grid[r] = -1; // mark the visited place with -1

// if is it safe to take next downward step then take it
if(issafe(r+1,c,grid,n,m)) {
	FindPaths(grid,r+1,c,n,m,ans);
}

// if is it safe to take next rightward step then take it
if(issafe(r,c+1,grid,n,m)) {
	FindPaths(grid,r,c+1,n,m,ans);
}

// backtracking step we need to make values original so to we can visit it by some another path
grid[r] = ch;

// remove the current path element we explore
ans.pop_back();
return ;
}

int main() {
	int n = 3 ,m =3;
	vector<vector<int> >grid{ {1,2,3},{4,5,6},{7,8,9}};
	vector<int>ans ; // it will store the path which we have covered
	
	FindPaths(grid,0,0,n,m,ans); // here 0,0 are initial position to start with
	return 0;
}
\



/*/*
    Time Complexity : O(2^(M+N))
    Space Complexity :O(M+N)
    
    Where M,N are rows and columns of matrix.


void findAllpaths(vector<vector<int> > &mat ,int row , int col, int m , int n , vector<int>  & path , int cur,vector<vector<int> > &res )
{
    /*
       If we are at last row
       we can move right only
    
    if(row == m-1)
    { 
        //Initialize vector to store path
        vector<int> temp=path;
        
        //Push elements to temp.
        for(int i = col; i < n; i++)
        {
            temp.push_back(mat[row][i]);
        } 
        
        //Add this path to our result. 
        res.push_back(temp);
        return;
    }
    
    /*
       If we are at last column
       we can move down only
    
    if( col==n-1 )
    {
        //Initialize vector to store path.
        vector<int> temp=path;
        
        //Push elements to temp.
        for(int i = row; i < m; i++)
        {
            temp.push_back(mat[i][col]);
        } 
        
        //Add this path to our result. 
        res.push_back(temp);
        return;
    }
    
    // Push current element to the path list. 
     path.push_back(mat[row][col]); 
      
    /* 
       Recursively call findAllpaths
       for right direction(next row)
    */
    findAllpaths(mat, row+1, col , m, n, path, cur + 1,res); 
       
    /* 
       Recursively call findAllpaths
       for down direction(next column)
    */
    findAllpaths(mat, row, col+1, m, n, path, cur + 1,res);
    
    //Pop the Current element
    path.pop_back();
    
}

vector<vector<int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    //Vector to store the current path.
    vector<int> path;
    
    //Store all the possible paths
    vector<vector<int> > ans;
    
    //Recursively call to find all paths.
    findAllpaths(mat, 0, 0, m, n, path, 0,ans); 
    
    return ans;
}


*/