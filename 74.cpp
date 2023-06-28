// C++ program to find out the second
// most repeated word
#include <bits/stdc++.h>
using namespace std;

// Function to find the word
string secMostRepeated(vector<string> seq)
{

	// Store all the words with its occurrence
	unordered_map<string, int> occ;
	for (int i = 0; i < seq.size(); i++)
		occ[seq[i]]++;

	// find the second largest occurrence
	int first_max = INT_MIN, sec_max = INT_MIN;
	for (auto it = occ.begin(); it != occ.end(); it++) {
		if (it->second > first_max) {
			sec_max = first_max;
			first_max = it->second;
		}

		else if (it->second > sec_max &&
				it->second != first_max)
			sec_max = it->second;
	}

	// Return string with occurrence equals
	// to sec_max
	for (auto it = occ.begin(); it != occ.end(); it++)
		if (it->second == sec_max)
			return it->first;
}

// Driver program
int main()
{
	vector<string> seq = { "ccc", "aaa", "ccc",
						"ddd", "aaa", "aaa" };
	cout << secMostRepeated(seq);
	return 0;
}





class Solution
{
  public:
    string secFrequent (string arr[], int n){
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;}
        int maxi=mp[arr[0]];
        int smaxi=-1;
        string s1;
        string s2;
        for(int i=0;i<n;i++){
          if(mp[arr[i]]>maxi){
               maxi=mp[arr[i]];
               s1=arr[i];}
            
        }
        for(int i=0;i<n;i++){
            if(mp[arr[i]]>smaxi and mp[arr[i]]<maxi){
                smaxi=mp[arr[i]];
                s2=arr[i];}
        }
        return s2;}
};