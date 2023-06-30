// A C++ program to count number of
// possible ways to a given score
// can be reached in a game where a
// move can earn 3 or 5 or 10
#include <iostream>
using namespace std;

// Returns number of ways
// to reach score n
int count(int n)
{
	// table[i] will store count
	// of solutions for value i.
	int table[n + 1], i;

	// Initialize all table
	// values as 0
	for (int j = 0; j < n + 1; j++)
		table[j] = 0;

	// Base case (If given value is 0)
	table[0] = 1;

	// One by one consider given 3 moves
	// and update the table[] values after
	// the index greater than or equal to
	// the value of the picked move
	for (i = 3; i <= n; i++)
		table[i] += table[i - 3];

	for (i = 5; i <= n; i++)
		table[i] += table[i - 5];

	for (i = 10; i <= n; i++)
		table[i] += table[i - 10];

	return table[n];
}

// Driver Code
int main(void)
{
	int n = 20;
	cout << "Count for " << n << " is " << count(n) << endl;

	n = 13;
	cout << "Count for " << n << " is " << count(n) << endl;
	return 0;
}

// This code is contributed
// by Shivi_Aggarwal















// A C++ program to count number of
// possible ways to a given score
// can be reached in a game where a
// move can earn 3 or 5 or 10
#include <iostream>
#include <vector>
using namespace std;

// Returns number of ways
// to reach score n
int countWays(int n)
{
// ways[i] will store count
// of solutions for value i.
vector<int> ways(n + 1, 0);


// Base case (If given value is 0)
ways[0] = 1;

// Consider all possible moves
int moves[] = {3, 5, 10};
for (int i = 0; i < 3; i++) {
	for (int j = moves[i]; j <= n; j++) {
		ways[j] += ways[j - moves[i]];
	}
}

return ways[n];
}

// Driver Code
int main(void)
{
int n = 20;
cout << "Count for " << n << " is " << countWays(n) << endl;
n = 13;
cout << "Count for " << n << " is " << countWays(n) << endl;
return 0;
}
