




// C++ program to find all combinations that
// sum to a given value
#include <bits/stdc++.h>
using namespace std;

// Print all members of ar[] that have given
void findNumbers(vector<int>& ar, int sum,
                 vector<vector<int> >& res, vector<int>& r,
                 int i)
{
    // if we get exact answer
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that
    // have value smaller than sum.
    while (i < ar.size() && sum - ar[i] >= 0) {

        // Till every element in the array starting
        // from i which can contribute to the sum
        r.push_back(ar[i]); // add them to list

        // recursive call for next numbers
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;

        // Remove number from list (backtracking)
        r.pop_back();
    }
}

// Returns all combinations 
// of ar[] that have given
// sum.
vector<vector<int> > combinationSum(vector<int>& ar,
                                    int sum)
{
    // sort input array
    sort(ar.begin(), ar.end());

    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, sum, res, r, 0);

    return res;
}

// Driver code
int main()
{
    vector<int> ar;
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);
    int n = ar.size();

    int sum = 8; // set value of sum
    vector<vector<int> > res = combinationSum(ar, sum);

    // If result is empty, then
    if (res.size() == 0) {
        cout << "Empty";
        return 0;
    }

    // Print all combinations stored in res.
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }
  return 0;
}








// C++ program to find all combinations that
// sum to a given value
//#include <bits/stdc++.h>
//using namespace std;
/*
// Print all members of ar[] that have given
void findNumbers(vector<int>& ar, int sum,
				vector<vector<int> >& res, vector<int>& r,
				int i)
{
	// if we get exact answer
	if (sum == 0) {
		res.push_back(r);
		return;
	}

	// Recur for all remaining elements that
	// have value smaller than sum.
	while (i < ar.size() && sum - ar[i] >= 0) {

		// Till every element in the array starting
		// from i which can contribute to the sum
		r.push_back(ar[i]); // add them to list

		// recursive call for next numbers
		findNumbers(ar, sum - ar[i], res, r, i);
		i++;

		// Remove number from list (backtracking)
		r.pop_back();
	}
}

// Returns all combinations
// of ar[] that have given
// sum.
vector<vector<int> > combinationSum(vector<int>& ar,
									int sum)
{
	// sort input array
	sort(ar.begin(), ar.end());

	// remove duplicates
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int> > res;
	findNumbers(ar, sum, res, r, 0);

	return res;
}

// Driver code
int main()
{
	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();

	int sum = 8; // set value of sum
	vector<vector<int> > res = combinationSum(ar, sum);

	// If result is empty, then
	if (res.size() == 0) {
		cout << "Empty";
		return 0;
	}

	// Print all combinations stored in res.
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
return 0;
}


*/













/*/*
    Time Complexity: O(2^N)
    Space Complexity: O(N*2^N)

    where N is the total number of elements in the aray.



#include <algorithm>


void solve(vector<vector<int>> &result, int currIndex, int currSum, 
			vector<int> &currList, int B, vector<int> &ARR)
{
	if (currSum == B)
	{
		result.push_back(currList);
		return ;
	}
	if (currIndex == ARR.size())
	{
		return ;
	}

	solve(result, currIndex + 1, currSum, currList, B, ARR);


	int count = 0;

	while (currSum <= B)
	{
		count++;

		currSum += ARR[currIndex];

		currList.push_back(ARR[currIndex]);

		solve(result, currIndex + 1, currSum, currList, B, ARR);
	}

	/* We remove ARR[currIndex] from currList, 'count'
	   number of times for backtracking 
	while (count--)
	{
		currList.pop_back();
	}
}


vector<vector<int>> combSum(vector<int> &ARR, int B)
{
	sort(ARR.begin(), ARR.end());
	
	vector<vector<int>> result;

	vector<int> currList;

	solve(result, 0, 0, currList, B, ARR);

	return result;
}*/