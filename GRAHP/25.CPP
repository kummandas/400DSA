class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};

















/*  
    Time Complexity : O(N ^ 2)
    Space Complexity : O(N ^ 2)
    
    Where 'N' is the number of rows and number of columns in board.
*/

#include <queue>
#include <climits>

class Coordinates
{
public:
    int rowNumber, columnNumber;

    //  Constructor will take size of board and cellNumber
    Coordinates(int cellNumber, int n)
    {
        //  Formula for conversion of cellNumber to Coordinates
        rowNumber = (cellNumber - 1) / n;
        columnNumber = (cellNumber - 1) % n;
 
        if (rowNumber % 2 == 1)
        {
            columnNumber = (n - 1) - columnNumber;
        }
 
        rowNumber = (n - 1) - rowNumber;
    }
};

int minDiceThrowToLastCell(int **board, int n)
{
    int *minDiceThrow, i;
    minDiceThrow = new int[(n * n) + 1];

    //  Initializing the minDiceThrow for all the cells to INT_MAX;
    for (i = 1; i <= n * n; i++)
    {
        minDiceThrow[i] = INT_MAX;
    }

    /*
        We will store cellNumber in the queue where the front of the queue will 
        always contain a cell which can be reached by minimum dice throw from start (cellNumber = 1).

        We will BFS Technique to maintain the queue.
    */
    queue<int> Q;

    // As we are starting from cell 1
    minDiceThrow[1] = 0;
    Q.push(1);

    while (!Q.empty())
    {
        int curCellNumber = Q.front();
        Q.pop();

        for (i = 1; i <= 6 && curCellNumber + i <= n * n; i++)
        {
            int nextCellNumber = i + curCellNumber;
            Coordinates nextCell(nextCellNumber, n);

            //  Check for Snake or Ladder
            if (board[nextCell.rowNumber][nextCell.columnNumber] != -1)
            {
                nextCellNumber = board[nextCell.rowNumber][nextCell.columnNumber];
            }

            //  If we have a better minimum
            if (minDiceThrow[nextCellNumber] > minDiceThrow[curCellNumber] + 1)
            {
                minDiceThrow[nextCellNumber] = minDiceThrow[curCellNumber] + 1;
                Q.push(nextCellNumber);
            }
        }
    }

    int finalMinDiceThrowToLastCell = minDiceThrow[n * n];

    //  If it's impossible to reach the last cell
    if (finalMinDiceThrowToLastCell == INT_MAX)
    {
        finalMinDiceThrowToLastCell = -1;
    }

    //  Deleting Dynamic MinDiceThrow Array
    delete[] minDiceThrow;

    return finalMinDiceThrowToLastCell;
}
