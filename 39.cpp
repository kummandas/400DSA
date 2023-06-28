
// CPP program to find the row 
// with maximum number of 1s 
/*
#include <bits/stdc++.h>
using namespace std;
#define R 4 
#define C 4 

// Function that returns index of row 
// with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) {
    // code here
    int rowIndex = -1 ;
    int maxCount = 0 ;
    
    for(int i = 0 ; i < R ; i++){
        int count = 0 ;
        for(int j = 0 ; j < C ; j++ ){
            if(mat[i][j] == 1){
                count++ ;
            }
        }
        if(count > maxCount){
            maxCount = count ;
            rowIndex = i ;
        }
    }
    
    return rowIndex ;
}


// Driver Code 
int main() 
{ 
    bool mat[R][C] = { {0, 0, 0, 1}, 
                    {0, 1, 1, 1}, 
                    {1, 1, 1, 1}, 
                    {0, 0, 0, 0}}; 

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat); 

    return 0; 
} 

*/


/*
#include <bits/stdc++.h>
using namespace std;

// The main function that returns index
// of row with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) 
{ 
    int i, index; 

    // Initialize max using values from first row. 
    int max_row_index = 0; 
    int max = first(mat[0], 0, C - 1); 

    // Traverse for each row and count number of 1s 
    // by finding the index of first 1 
    for (i = 1; i < R; i++) 
    { 
        // Count 1s in this row only if this row 
        // has more 1s than max so far 

        // Count 1s in this row only if this row 
        // has more 1s than max so far 
        if (max != -1 && mat[i][C - max - 1] == 1) 
        { 
            // Note the optimization here also 
            index = first (mat[i], 0, C - max); 

            if (index != -1 && C - index > max) 
            { 
                max = C - index; 
                max_row_index = i; 
            } 
        } 
        else 
        { 
            max = first(mat[i], 0, C - 1); 
        } 
    } 
    return max_row_index; 
} 

// This code is contributed by rathbhupendra



*/



// C++ program to find the row with maximum
// number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = C - 1;

    for (int i = 0; i < R; i++) {
        // Move left until a 0 is found
      bool flag=false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          flag=true ;//present row has more 1's than previous
          }
      // if the present row has more 1's than previous
      if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}
// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
 
    return 0;
}
// this code is contributed by Rishabh Chauhan