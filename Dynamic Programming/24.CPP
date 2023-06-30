#include <bits/stdc++.h>
using namespace std;

struct val
{
	int first;
	int second;
};

//function that helps to sort the structure p in increasing order of second values
bool static comp(val fst, val sec){
		return fst.second<sec.second;
	}

//function to calculate the max length chain
int maxChainLen(struct val p[],int n){
		//Your code here
		sort(p,p+n,comp);
		int prev=-1e9;
		int ans=0;
		for(int i=0;i<n;i++){
			if(p[i].first>prev){
				ans++;
				prev=p[i].second;
			}
		}
		return ans;
	}

int main() {


	int n = 5;
	val p[n];
	p[0].first = 5;
	p[0].second = 24;

	p[1].first = 39;
	p[1].second = 60;

	p[2].first = 15;
	p[2].second = 28;

	p[3].first = 27;
	p[3].second = 40;

	p[4].first = 50;
	p[4].second = 90;
	
	// Function Call
	cout << maxChainLen(p, n) << endl;
	return 0;
}








/*
	Time Complexity: O(N ^ 2)
    Space complexity: O(N)

    Where 'N' is the number of pairs given in input.
*/

#include <algorithm>
#include <vector>

int solve(int i, vector<pair<int, int>> p, vector<int> dp) {
    // Base case: when we reach end of the array then there is no pair available hence we return 0.
    if (i == p.size()) {
        return 0;
    }
    // If the result of index i is already calculated then we simply return it.
    if (dp[i] != -1) {
        return dp[i];
    }

    // Now we have two options: first one is to skip the current pair.
    int option1 = solve(i + 1, p, dp);
    int option2 = 1;

    // Second option is to include this pair in our chain and recur for next possible pair.
    for (int j = i + 1; j < p.size(); ++j) {
        if (p[i].second < p[j].first) {
            option2 = max(option2, 1 + solve(j, p, dp));
        }
    }
    // Store the max length which we can get from both the options.
    return dp[i] = max(option1, option2);
}

int maxLengthChain(vector<pair<int, int>> &p, int n) {
    // Sort the array according to first element.
    sort(p.begin(), p.end());

    // Definition: dp[i] will store the maximum length of chain starting at index i.
    vector<int> dp(n, -1);

    int maxLength = solve(0, p, dp);
    return maxLength;
}