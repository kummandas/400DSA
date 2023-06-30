/*#include <bits/stdc++.h> 

void addsolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col,map<int,bool>&colmap,map<int,bool>&upperdiagonal,map<int,bool>&lowerdiagonal,int n){
   
    //checking for if queen is present in previous diffrent col of same row 
   if(colmap[row]==1)
       return false;
    //left to top diagonal
    if(upperdiagonal[(n-1)+(col-row)]==1)
        return false;
    //left to bottom diagonal
    if(lowerdiagonal[row+col]==1)
        return false;
    return true;
}

void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n,map<int,bool>&colmap,map<int,bool>&upperdiagonal,map<int,bool>&lowerdiagonal){
    //base case
    if(col==n){
        addsolution(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,colmap,upperdiagonal,lowerdiagonal,n)){
            board[row][col]=1;
            colmap[row]=true;
            upperdiagonal[(n-1)+(col-row)]=1;
            lowerdiagonal[row+col]=1;
            solve(col+1,board,ans,n,colmap,upperdiagonal,lowerdiagonal);
            colmap[row]=false;
            upperdiagonal[(n-1)+(col-row)]=0;
            lowerdiagonal[row+col]=0;
            board[row][col]=0;            
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    map<int,bool>colmap;
    map<int,bool>upperdiagonal;
    map<int,bool>lowerdiagonal;

    solve(0,board,ans,n,colmap,upperdiagonal,lowerdiagonal);
    return ans;
}*/















/*

    Time Complexity : O(N!)
    Space Complexity : O(N * N)
    
    Where N is the number of Queens.



//Function to add valid configuration
void addSolution(int n, vector<vector<int>>& ans, vector<int>& queensInRows) 
{
    vector<int> currentAnswer;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (queensInRows[j] == i) 
            {
                currentAnswer.push_back(1);
            } 
            else 
            {
                currentAnswer.push_back(0);
            }
        }
    }

    ans.push_back(currentAnswer);
}

void nQueensHelper(int col, int n, vector<vector<int>>& ans, vector<int>& queensInRows, vector<int>& queensInDiag1, vector<int>& queensInDiag2) 
{
    // If all the queens have been placed
    if (col == n) 
    {  
        addSolution(n, ans, queensInRows);
        return;
    }

    // Try all the rows for column col
    for (int i = 0; i < n; i++) 
    {                   
        // If its not safe to place queen here              
        if ((queensInRows[i] != -1) || (queensInDiag1[col - i + n - 1] != -1) || (queensInDiag2[col + i] != -1))
        {
            continue;
        }                    

        // Mark queen placed
        queensInRows[i] = queensInDiag1[col - i + n - 1] = queensInDiag2[col + i] = col;    

        // Try placing the remaining queens
        nQueensHelper(col + 1, n, ans, queensInRows, queensInDiag1, queensInDiag2);     

        // Unmark the cell to backtrack
        queensInRows[i] = queensInDiag1[col - i + n - 1] = queensInDiag2[col + i] = -1;  

    }

    return;
}


vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> queensInRows(n, -1), queensInDiag1(2 * n, -1), queensInDiag2(2 * n, -1);

    nQueensHelper(0, n, ans, queensInRows, queensInDiag1, queensInDiag2);

    return ans;
}
*/























/*


1- Create 2D-array to represent the board with each cell in the array corresponding to a box in the board
2- Create a stack to keep track of the queens' positions where the queen on the top is always the most recently added queen.
3- set counter j = 1 which will be used loop through columns in the coming steps.
4- Create an outer loop through the rows from i = 1 ----> i = n
    5- Create inner loop through columns from j  ----> j = n.
        6- in the inner body of loops check if the current cell is valid to add a queen
        if valid 
            - add the queen to the board
            - add the queen's position to the stack
            - break the inner loop
    7- after finishing or breaking the inner loop 
    a) set j = 1 (so the default is to start looping through the columns from j = 1 in the coming iteration)
    b) check if the size of the stack equals the number of the row to see if a queen was placed in current row
    if no queen was placed:
        8- back track to the last added queen by doing the following:
            a) accessing the position of the last added queen from the top of stack
            b) delete the last added queen from the board
            c) set i (counter for rows of the board) = the row of the last added queen
            d) set j = the column of last added queen + 1
    9- if i == n meaning that all rows are now visited and filled with queens
        a) print solution
        b) do step 8 again to test other solutions until the stack is empty
            
    
            
According to the below Implementation, the solutions will be printed as an n*n matrix of zeros and ones, where the cells = 1 represent the queens. 

Below is the Implementation of the above algorithm

*/
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std;
using vvi = vector<vector<int> >;
using vi = vector<int>;
void print(vvi board)
{
 
    int count = 0;
    for (auto& row : board) {
        for (auto& el : row)
            if (el == 1)
                count++;
    }
    // Not valid solution
    if (count != board.size())
        return;
 
    // Print the matrix
    for (auto& row : board) {
        for (auto& el : row)
            cout << el << " ";
        cout << '\n';
    }
}
bool validate(vvi board, int i, int j)
{
    // validate rows
    for (int c = 1; c <= j; c++)
        if (board[i - 1] == 1)
            return false;
    // validate columns
    for (int r = 1; r <= i; r++)
        if (board[r - 1][j - 1] == 1)
            return false;
    // validate diagonals to right up corner
    int c = j;
    int r = i;
    while (c != 0 and r != 0) {
        if (board[r - 1] == 1)
            return false;
        r--;
        c--;
    }
    // validate diagonals to left up corner
    c = j;
    r = i;
    while (c != board.size() + 1 and r != 0) {
        if (board[r - 1] == 1)
            return false;
        r--;
        c++;
    }
    return true;
}
 
void n_queen(int n)
{
    vvi board(n, vi(n));
    stack<pair<int, int> >
        queens_positions; // stores positions of added
                          // queens
    int j = 1;
    for (int i = 1; i <= board.size(); i++) {
        for (; j <= board.size(); j++) {
            if (validate(board, i,
                         j)) { // check validity of cell
                               // before adding the queen
                board[i - 1][j - 1] = 1;
                queens_positions.push(make_pair(i, j));
                break;
            }
        }
        j = 1;
        if (queens_positions.size()
            != i) { // checks if a queen was placed in the
                    // current row
 
            if (!queens_positions.empty()) {
                pair<int, int> Q_last
                    = queens_positions
                          .top(); // position of last added
                                  // queen
                queens_positions.pop();
 
                // backtracking
                board[Q_last.first - 1][Q_last.second - 1]
                    = 0; // nulling the last added queen
                i = Q_last.first
                    - 1; // going back to the row of the
                         // last added queen
                j = Q_last.second
                    + 1; // going back to the column of the
                         // last added queen + 1
            }
        }
 
        if (i == board.size()) {
            print(board);
            cout << '\n';
            if (!queens_positions.empty()) {
                pair<int, int> Q_last
                    = queens_positions
                          .top(); // position of last added
                                  // queen
                queens_positions.pop();
 
                // backtracking
                board[Q_last.first - 1][Q_last.second - 1]
                    = 0; // nulling the last added queen
                i = Q_last.first
                    - 1; // going back to the row of the
                         // last added queen
                j = Q_last.second
                    + 1; // going back to the column of the
                         // last added queen + 1
            }
        }
    }
}
 
int main() { n_queen(4); }
/*
Output
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 
Time Complexity: O(n2 * n!), where n is the size of the board.
Space Complexity: O(n2)
*/