// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum number of
// characters of the given binary string
// to be replaced to make the string alternating
int minReplacement(string s, int len)
{
	int ans = 0;
	for (int i = 0; i < len; i++) {

		// If there is 1 at even index positions
		if (i % 2 == 0 && s[i] == '1')
			ans++;

		// If there is 0 at odd index positions
		if (i % 2 == 1 && s[i] == '0')
			ans++;
	}
	return min(ans, len - ans);
}

// Driver code
int main()
{
	string s = "1100";
	int len = s.size();
	cout << minReplacement(s, len);

	return 0;
}
