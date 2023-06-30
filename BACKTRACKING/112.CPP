/*/*
    Time Complexity: O(N*N!)
    Space Complexity: O(N*N!),

    where N is the number whose Kth permutation sequence is to be found.


void kthPermutationHelper(int i, vector<int> &v, int n, vector<vector<int>> &answer )
{
    // If vector sizes reaches n, push back that vector into answer vector.
    if (i == n)
    {
        answer.push_back(v);
        return;
    }

    // Array to mark the occurences
    bool visited[n + 1] = {false};
    for (int x : v)
    {
        visited[x] = true;
    }

    for (int j = 1; j <= n; j++)
    {
        // If the number doesn't lie in the vector v then we can place the number at this position.
        if (visited[j] == 0)
        {
            // Placing j at this position
            v.push_back(j);
            kthPermutationHelper(i + 1, v, n, answer);
            v.pop_back();
        }

    }

    return;
}

vector<int> kthPermutation(int n, int k)
{
    vector<vector<int>> answer;
    vector<int>v;
    kthPermutationHelper(0, v, n, answer);
    return answer[k - 1];
}*/
// C++ program to Find the kth Permutation
// Sequence of first n natural numbers
#include <bits/stdc++.h>
using namespace std;

// recursive function to generate all
// possible permutations of a string
void generate_permutations(string& str, int idx, vector<string>& result) {
	// base case
	if (idx == str.size()) {
		result.push_back(str);
		return;
	}
	
	// traverse string from idx to end
	for (int i = idx; i < str.size(); i++) {
		swap(str[i], str[idx]);
		generate_permutations(str, idx + 1, result);
		swap(str[i], str[idx]);
	}
}

// Function to find the
// kth permutation of n numbers
string findKthPermutation(int n, int k) {
	string str = "";
	vector<string> result;
	
	// Insert all natural number
	// upto n in string
	for (int i = 1; i <= n; i++) {
		str.push_back(i + '0');
	}
	
	generate_permutations(str, 0, result);
	// sort the generated permutations
	sort(result.begin(), result.end());
	
	// make k 0-based indexed to point to kth sequence
return result[k-1];
}

// Driver code
int main() {
	int n = 3, k = 4;
	
	// function call
	string kth_perm_seq = findKthPermutation(n, k);
	cout << kth_perm_seq << endl;

	return 0;
}

// This code is contributed by Tapesh(tapeshdua420)
