// C++ program to count number of balanced
// binary trees of height h.
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int countBT(int h) {
	
	long long int dp[h + 1];
	//base cases
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= h; i++) {
		dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod;
	}
	return dp[h];
}


// Driver program
int main()
{
	int h = 3;
	cout << "No. of balanced binary trees"
			" of height h is: "
		<< countBT(h) << endl;
}









// C++ program to count number of balanced
// binary trees of height h.
#include <bits/stdc++.h>
using namespace std;

long long int countBT(int h) {
	if(h<2){
	return 1;
	}
	const int BIG_PRIME = 1000000007;
	long long int dp0 = 1, dp1 = 1,dp2;

	for(int i = 2; i <= h; i++) {

		dp2 = (dp1 * ((2 * dp0)%BIG_PRIME + dp1)%BIG_PRIME) % BIG_PRIME;
	
		// update dp1 and dp0
		dp0 = dp1;
		dp1 = dp2;

		// Don't commit following simple mistake
		// dp1 = dp0;
		// dp0 = dp1;
	}
	return dp2;
}


// Driver program
int main()
{
	int h = 3;
	cout << "No. of balanced binary trees"
			" of height h is: "
		<< countBT(h) << endl;
}
// This code is contributed by Kadapalla Nithin Kumar
