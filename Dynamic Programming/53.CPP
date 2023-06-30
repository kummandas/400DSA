// A Naive Recursive C program to count number of possible numbers
// of given length
#include <stdio.h>

// left, up, right, down move from current location
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};

// Returns count of numbers of length n starting from key position
// (i, j) in a numeric keyboard.
int getCountUtil(char keypad[][3], int i, int j, int n)
{
	if (keypad == NULL || n <= 0)
		return 0;

	// From a given key, only one number is possible of length 1
	if (n == 1)
		return 1;

	int k=0, move=0, ro=0, co=0, totalCount = 0;

	// move left, up, right, down from current location and if
	// new location is valid, then get number count of length
	// (n-1) from that new position and add in count obtained so far
	for (move=0; move<5; move++)
	{
		ro = i + row[move];
		co = j + col[move];
		if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 &&
		keypad[ro][co] != '*' && keypad[ro][co] != '#')
		{
			totalCount += getCountUtil(keypad, ro, co, n-1);
		}
	}

	return totalCount;
}

// Return count of all possible numbers of length n
// in a given numeric keyboard
int getCount(char keypad[][3], int n)
{
	// Base cases
	if (keypad == NULL || n <= 0)
		return 0;
	if (n == 1)
		return 10;

	int i=0, j=0, totalCount = 0;
	for (i=0; i<4; i++) // Loop on keypad row
	{
		for (j=0; j<3; j++) // Loop on keypad column
		{
			// Process for 0 to 9 digits
			if (keypad[i][j] != '*' && keypad[i][j] != '#')
			{
				// Get count when number is starting from key
				// position (i, j) and add in count obtained so far
				totalCount += getCountUtil(keypad, i, j, n);
			}
		}
	}
	return totalCount;
}

// Driver program to test above function
int main(int argc, char *argv[])
{
char keypad[4][3] = {{'1','2','3'},
						{'4','5','6'},
						{'7','8','9'},
						{'*','0','#'}};
printf("Count for numbers of length %d: %dn \n", 1, getCount(keypad, 1));
printf("Count for numbers of length %d: %dn \n", 2, getCount(keypad, 2));
printf("Count for numbers of length %d: %dn \n", 3, getCount(keypad, 3));
printf("Count for numbers of length %d: %dn \n", 4, getCount(keypad, 4));
printf("Count for numbers of length %d: %dn", 5, getCount(keypad, 5));

return 0;
}











/*
    Time Complexity: O(N)
    Space complexity: O(1)
    
    Where N is the number of buttons to press.
*/

const int mod = 1000000007;

int generateNumbers(int n)
{
    vector<vector<int>> keypad{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    vector<int> dr{0, 0, -1, 0, 1};
    vector<int> dc{0, -1, 0, 1, 0};

    // Use long long to avoid int overflow.
    // Stores the total numbers that can be generated.
    long long int ans = 0;

    vector<vector<long long int>> dp(2, vector<long long int>(10,0));

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int r = 0; r < keypad.size(); r++)
        {
            for (int c = 0; c < keypad[0].size(); c++)
            {
                int j = keypad[r][c];
                if (j != -1)
                {
                    dp[i%2][j]=0;
                    for (int x = 0; x < dr.size(); x++)
                    {
                        int tr = r + dr[x];
                        int tc = c + dc[x];
                        if (tr >= 0 && tr < keypad.size() && tc >= 0 && tc < keypad[0].size() && keypad[tr][tc] != -1)
                        {
                            dp[i%2][j] = (dp[i%2][j] + dp[(i - 1)%2][keypad[tr][tc]]) % mod;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        ans = (ans + dp[n%2][i]) % mod;
    }

    return ans;
}



















// A Space Optimized C++ program to count number of possible numbers
// of given length
#include <bits/stdc++.h>
using namespace std;

// Return count of all possible numbers of length n
// in a given numeric keyboard
int getCount(char keypad[][3], int n)
{
	if (keypad == NULL || n <= 0)
		return 0;
	if (n == 1)
		return 10;

	// odd[i], even[i] arrays represent count of numbers starting
	// with digit i for any length j
	int odd[10], even[10];
	int i = 0, j = 0, useOdd = 0, totalCount = 0;

	for (i = 0; i <= 9; i++)
		odd[i] = 1; // for j = 1

	for (j = 2; j <= n; j++) // Bottom Up calculation from j = 2 to n
	{
		useOdd = 1 - useOdd;

		// Here we are explicitly writing lines for each number 0
		// to 9. But it can always be written as DFS on 4X3 grid
		// using row, column array valid moves
		if (useOdd == 1)
		{
			even[0] = odd[0] + odd[8];
			even[1] = odd[1] + odd[2] + odd[4];
			even[2] = odd[2] + odd[1] + odd[3] + odd[5];
			even[3] = odd[3] + odd[2] + odd[6];
			even[4] = odd[4] + odd[1] + odd[5] + odd[7];
			even[5] = odd[5] + odd[2] + odd[4] + odd[8] + odd[6];
			even[6] = odd[6] + odd[3] + odd[5] + odd[9];
			even[7] = odd[7] + odd[4] + odd[8];
			even[8] = odd[8] + odd[0] + odd[5] + odd[7] + odd[9];
			even[9] = odd[9] + odd[6] + odd[8];
		}
		else
		{
			odd[0] = even[0] + even[8];
			odd[1] = even[1] + even[2] + even[4];
			odd[2] = even[2] + even[1] + even[3] + even[5];
			odd[3] = even[3] + even[2] + even[6];
			odd[4] = even[4] + even[1] + even[5] + even[7];
			odd[5] = even[5] + even[2] + even[4] + even[8] + even[6];
			odd[6] = even[6] + even[3] + even[5] + even[9];
			odd[7] = even[7] + even[4] + even[8];
			odd[8] = even[8] + even[0] + even[5] + even[7] + even[9];
			odd[9] = even[9] + even[6] + even[8];
		}
	}

	// Get count of all possible numbers of length "n" starting
	// with digit 0, 1, 2, ..., 9
	totalCount = 0;
	if (useOdd == 1)
	{
		for (i = 0; i <= 9; i++)
			totalCount += even[i];
	}
	else
	{
		for (i = 0; i <= 9; i++)
			totalCount += odd[i];
	}
	return totalCount;
}

// Driver program to test above function
int main()
{
	char keypad[4][3] = {{'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'},
						{'*', '0', '#'}};
	cout << "Count for numbers of length 1: " << getCount(keypad, 1) << endl;
	cout << "Count for numbers of length 2: " << getCount(keypad, 2) << endl;
	cout << "Count for numbers of length 3: " << getCount(keypad, 3) << endl;
	cout << "Count for numbers of length 4: " << getCount(keypad, 4) << endl;
	cout << "Count for numbers of length 5: " << getCount(keypad, 5) << endl;

	return 0;
}

//This code is contributed by Mayank Tyagi
