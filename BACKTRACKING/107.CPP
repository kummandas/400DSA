// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string& a, int l, int r)
{
	// Base case
	if (l == r)
		cout << a << endl;
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	int n = str.size();

	// Function call
	permute(str, 0, n - 1);
	return 0;
}

// This is code is contributed by rathbhupendra



/*void sol(int i, int j, int N, string S, vector<string>& d) {
    if (i > N || j <0) return;

    sol(i, j -1, N, S, d);
    swap(S[i], S[j]);
    d.push_back(S);

    sol(i + 1, j, N, S, d);
}

vector<string> find_permutation(string S) {
    int n = S.length() - 1;
    vector<string> d;
    sol(0, n, n, S, d);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    return d;
}*/




/*class Solution
{
    public:
        vector<string>find_permutation(string S)
        {
            vector<string>res;
            // sort the string in lexicographically order
            sort(S.begin(), S.end());
            do
            {
                // keep adding while there is next permutation
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));
            return res;
        }
};*/