/*
        Time Complexity: O(NlogN + N)
        Space Complexity: O(N)

        Where N is the size of the array.
*/

void inorderTraversal(vector<int>arr, vector<int>&inorder, int n, int idx)
{
	// Base case.
	if (idx >= n)
	{
		return;
	}

	inorderTraversal(arr, inorder, n, 2 * idx + 1);
	inorder.push_back(arr[idx]);
	inorderTraversal(arr, inorder, n, 2 * idx + 2);
}


int minimumSwaps(vector<int>&arr, int n) {

	// Finding the inorder.
	vector<int>inorder;
	inorderTraversal(arr, inorder, n, 0);


	int ans = 0;
	vector<pair<int, int>>toSwap(n);
	
	for (int i = 0; i < n; i++)
	{
		toSwap[i].first = inorder[i], toSwap[i].second = i;
	}

	sort(toSwap.begin(), toSwap.end());
	
	// Finding the minimum number of swaps.
	for (int i = 0; i < n; i++)
	{
		if (i == toSwap[i].second)
		{
			continue;
		}

		else
		{
			swap(toSwap[i].first, toSwap[toSwap[i].second].first);
			swap(toSwap[i].second, toSwap[toSwap[i].second].second);
		}

		if (toSwap[i].second != i)
		{
			--i;
		}
		ans++;
	}

	
	return ans;

}