// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
	int n = str.length();

	// if string is empty or having one char
	if (n <= 1)
		return str;

	// Count all distinct characters.
	int dist_count = 0;
	bool visited[MAX_CHARS] = { false };
	for (int i = 0; i < n; i++) {
		if (visited[str[i]] == false) {
			visited[str[i]] = true;
			dist_count++;
		}
	}

	// Now follow the algorithm discussed in below
	// post. We basically maintain a window of characters
	// that contains all characters of given string.
	int start = 0, start_index = -1, min_len = INT_MAX;

	int count = 0;
	int curr_count[MAX_CHARS] = { 0 };
	for (int j = 0; j < n; j++) {
		// Count occurrence of characters of string
		curr_count[str[j]]++;

		// If any distinct character matched,
		// then increment count
		if (curr_count[str[j]] == 1)
			count++;

		// if all the characters are matched
		if (count == dist_count) {
			// Try to minimize the window i.e., check if
			// any character is occurring more no. of times
			// than its occurrence in pattern, if yes
			// then remove it from starting and also remove
			// the useless characters.
			while (curr_count[str[start]] > 1) {
				if (curr_count[str[start]] > 1)
					curr_count[str[start]]--;
				start++;
			}

			// Update window size
			int len_window = j - start + 1;
			if (min_len > len_window) {
				min_len = len_window;
				start_index = start;
			}
		}
	}

	// Return substring starting from start_index
	// and length min_len
	return str.substr(start_index, min_len);
}

// Driver code
int main()
{
	string str = "aabcbcdbca";
	cout << "Smallest window containing all distinct"
			" characters is: "
		<< findSubString(str);
	return 0;
}



/*












class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int i=0, j=0;
        map<char,int>mp,mp1;
        for(auto x:str)
        mp[x]++;
        int ans=str.size();
        while(j<str.size()){
            mp1[str[j]]++;
           
            if(mp.size()==mp1.size()){
                ans= min(ans, j-i+1);
                while(mp.size()==mp1.size()){
                    ans= min(ans, j-i+1);
                    mp1[str[i]]--;
                    if(mp1[str[i]]==0)
                    mp1.erase(str[i]);
                    i++;
                }
                  //cout<<i<<" "<<j<<" "<<ans<<endl;
            }
             j++;
          
            
        }
        if(mp.size()==mp1.size())
                ans= min(ans, j-i+1);
        return ans;
        
    }
};





lass Solution{
    public:
    int findSubString(string str)

    {

        int ans = INT_MAX;

        int n = str.size();

        unordered_map<char, int> mp1, mp2;

        for(int i=0; i<str.size(); i++){

            mp1[str[i]]++;

        }

        int i=0; int j=0;

        while(j<n){

            mp2[str[j]]++;

            while(mp1.size()==mp2.size()){

                ans = min(ans, j-i+1);

                mp2[str[i]]--;

                if(mp2[str[i]]==0) mp2.erase(str[i]);

                i++;

            }

            j++;

        }

        return ans;

 

    }
};
*/