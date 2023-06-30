/*/*
    Time Complexity : O(2^N * N)
    Space Complexity : O(2^N * N)

    where 'N' is the size in the given array.


int getMinDistance(int mask, int currentCity, vector<vector<int>> &dp, vector<vector<int>> &distance)
{
    int n = distance.size();

    // All cities being visited.
    if (mask == (1 << n) - 1)
    {
        return distance[currentCity][0];
    }

    // If the current state (mask, currentCity) is visited before.
    if (dp[mask][currentCity] != -1)
    {
        return dp[mask][currentCity];
    }

    int ans = 1e9 + 5;

    // Trying for every possible city and computing the shortest possible route.
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int tmpAns = distance[currentCity][city] + getMinDistance(mask | (1 << city), city, dp, distance);
            ans = min(ans, tmpAns);
        }
    }

    // Memorizing and return the ans.
    return dp[mask][currentCity] = ans;
}

int shortestRoute(vector<vector<int>> &distance)
{
    int n = distance.size();

    vector<vector<int>> dp((1 << n) + 1, vector<int>(n + 1, -1));

    // Return the ans returned by getMinDistance.
    return getMinDistance(1, 0, dp, distance);

}

*/


#include <iostream>

using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

// This code is contributed by Serjeel Ranjan
