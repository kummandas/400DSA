// C++ program for solution of
// friends pairing problem
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	int dp[n + 1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

// Driver code
int main()
{
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	return 0;
}














#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	int a = 1, b = 2, c = 0;
	if (n <= 2) {
		return n;
	}
	for (int i = 3; i <= n; i++) {
		c = b + (i - 1) * a;
		a = b;
		b = c;
	}
	return c;
}

// Driver code
int main()
{
	int n = 4;
	cout << countFriendsPairings(n);
	return 0;
}

// This code is contributed by mits






/*/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is given integer.


int numberOfWays(int n)
{
	// Base Conditions.
	if (n == 1 || n == 2)
	{
		return n;
	}

	int mod = 1e9 + 7;

	// total number of ways for n = 1 and n = 2 respectively.
	int lastSecondAnswer = 1, lastAnswer = 2;

	int currentAnswer;

	// Iterating and calculating for every value of i = 3 to n.
	for (int i = 3; i <= n; i++)
	{
		currentAnswer = (lastAnswer % mod + (1l * (i - 1) * lastSecondAnswer) % mod) % mod;
		lastSecondAnswer = lastAnswer;
		lastAnswer = currentAnswer;
	}

	return currentAnswer;
}
*/