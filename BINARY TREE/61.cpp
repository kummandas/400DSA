/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the number of nodes in the tree.


#include<vector>

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    vector<vector<int>> treeA(n, vector<int>());
    vector<vector<int>> treeB(n, vector<int>());

    // Building Adjacency List for the TreeA and TreeB.
    for (vector<int> edge : edgesA){
        treeA[edge[0]].push_back(edge[1]);
    }

    for (vector<int> edge : edgesB){
        treeB[edge[0]].push_back(edge[1]);
    }

    for (int i = 0; i < n ; i++){

        // Unequal number of child,return false.
        if (treeA[i].size() != treeB[i].size()){
            return false;
        }

        int j = 0;
        int k = treeA[i].size()-1;
        while (k >= 0){

            if (treeA[i][j] != treeB[i][k]){
                // Order mismatched.
                return false;
            }

            j = j + 1;
            k = k - 1;
        }
    }

    return true;
}

*/






// C++ program to check if two n-ary trees are
// mirror.
#include <bits/stdc++.h>
using namespace std;

// Function to check given two trees are mirror
// of each other or not
int checkMirrorTree(int M, int N, int u1[ ],
					int v1[ ] , int u2[], int v2[])
	{
		// Map to store nodes of the tree
		unordered_map<int , stack<int>>mp;

		// Traverse first tree nodes
		for (int i = 0 ; i < N ; i++ )
		{
		mp[u1[i]].push(v1[i]);
		}
		
		// Traverse second tree nodes
		for (int i = 0 ; i < N ; i++)
		{
			if(mp[u2[i]].top() != v2[i])
				return 0;
			mp[u2[i]].pop();
		}

		return 1;
	}

// Driver code
int main()
{
	int M = 7, N = 6;
	
	//Tree 1
	int u1[] = { 1, 1, 1, 10, 10, 10 };
	int v1[] = { 10, 7, 3, 4, 5, 6 };

	//Tree 2
	int u2[] = { 1, 1, 1, 10, 10, 10 };
	int v2[] = { 3, 7, 10, 6, 5, 4 };

	if(checkMirrorTree(M, N, u1, v1, u2, v2))
	cout<<"Yes";
	else
	cout<<"No";

	return 0;
}
