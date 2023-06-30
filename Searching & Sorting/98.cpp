/*
    Time Complexity: O(N^2)
    Space complexity: O(N^2)

    Where 'N' is the number of element present in the given array.
*/
/*
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool commonIdx(pair < int, int > p1, pair < int, int > p2) {
    return p1.first == p2.first || p1.first == p2.second || p1.second == p2.first || p1.second == p2.second;
}

string fourSum(vector < int > arr, int target, int n) {
    unordered_map < int, pair < int, int >> mp;
    
    /*
        Preparing a HashMap which will store sum of 
        two elements of array arr[] as key and their 
        indexes as value.
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mp[arr[i] + arr[j]] = {
                i,
                j
            };
        }
    }

    // Check on all possible pair sum which can be found in HashMap.
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int requiredSum = target - (arr[i] + arr[j]);
            /* 
                If HashMap contains required sum then we must 
                ensure that both pairs does not contain common indexes.
        
            if (mp.find(requiredSum) != mp.end() && !commonIdx(mp[requiredSum], {
                    i,
                    j
                })) {
                return "Yes";
            }
        }
    }
    // If we can not found the target sum then we return No.
    return "No";
}


*/


// C++ program to find if there exist 4 elements
// with given sum
#include <bits/stdc++.h>
using namespace std;

// function to check if there exist four
// elements whose sum is equal to k
bool findfour(int arr[], int n, int k)
{
	// map to store sum and indexes for
	// a pair sum
	unordered_map<int, vector<pair<int, int> > > hash;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			// calculate the sum of each pair
			int sum = arr[i] + arr[j];

			// if k-sum exist in map
			if (hash.find(k - sum) != hash.end()) {
				auto num = hash.find(k - sum);
				vector<pair<int, int> > v = num->second;

				// check for index coincidence as if
				// there is a common that means all
				// the four numbers are not from
				// different indexes and one of the
				// index is repeated
				for (int k = 0; k < num->second.size();
					k++) {

					pair<int, int> it = v[k];

					// if all indexes are different then
					// it means four number exist
					// set the flag and break the loop
					if (it.first != i && it.first != j
						&& it.second != i && it.second != j)
						return true;
				}
			}

			// store the sum and index pair in hashmap
			hash[sum].push_back(make_pair(i, j));
		}
	}
	hash.clear();
	return false;
}

// Driver code
int main()
{
	int k = 7;
	int arr[] = { 1, 5, 1, 0, 6, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (findfour(arr, n, k))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
