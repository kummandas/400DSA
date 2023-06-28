class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
			sort(v.begin(),v.end());
			int ans ;
			// if size is odd
			if(v.size() & 1)
				ans = v[v.size() / 2];
			// If size is even
			else
				ans = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
			return ans;
		}
};