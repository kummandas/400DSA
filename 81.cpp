/*This is a complete C++ function template for solving the problem of grouping anagrams in a given vector of strings.

The function takes a vector of strings named 'string_list' as input and returns a 2D vector of strings named 'result', where each sub-vector contains a group of anagrams.

The function first creates an unordered map named 'umap' to store groups of anagrams. It then iterates over each string in the input vector and sorts it to create a key for the unordered map. If the key already exists, the string is added to the corresponding group of anagrams. If the key does not exist, a new key is created with the sorted string as the key and the original string is added to the corresponding group.

Finally, the function iterates over the unordered map and appends each group of anagrams to the 'result' vector. The resulting 2D vector is then returned.

Overall, the function has a time complexity of O(n k log k), where n is the number of strings in the input vector and k is the maximum length of a string in the vector. This is due to the time complexity of sorting each string. The space complexity is also O(nk) due to the storage of the unordered map.


//Back-end complete function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        vector<vector<string> > result;
    
        // hash map to maintain groups of anagrams
        unordered_map <string,vector<string> > umap; 
        
        for(int i =0; i<string_list.size(); i++ )
        {
            string s = string_list[i];
         
            // sort each string
            sort(s.begin(),s.end());
            
            // add original string to corresponding sorted string in hash map
            umap[s].push_back(string_list[i]);
        }
        for(auto itr= umap.begin(); itr!=umap.end(); itr++)
            result.push_back(itr->second);
        
        return result;
    }
};

*/

// C++ program for finding all anagram
// pairs in the given array
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Utility function for
// printing anagram list
void printAnagram(unordered_map<string,vector<string> >& store)
{
	for (auto it:store)
	{
		vector<string> temp_vec(it.second);
		int size = temp_vec.size();
	
		for (int i = 0; i < size; i++)
		cout << temp_vec[i] << " ";
		
		cout << "\n";
	}
}

// Utility function for storing
// the vector of strings into HashMap
void storeInMap(vector<string>& vec)
{
	unordered_map<string,vector<string> > store;

	for (int i = 0; i < vec.size(); i++)
	{
		string tempString(vec[i]);
	
		// sort the string
		sort(tempString.begin(),tempString.end());
	
		// make hash of a sorted string
		store[tempString].push_back(vec[i]);
	}

	// print utility function for printing
	// all the anagrams
	printAnagram(store);
}

// Driver code
int main()
{
	// initialize vector of strings
	vector<string> arr;
	arr.push_back("geeksquiz");
	arr.push_back("geeksforgeeks");
	arr.push_back("abcd");
	arr.push_back("forgeeksgeeks");
	arr.push_back("zuiqkeegs");
	arr.push_back("cat");
	arr.push_back("act");
	arr.push_back("tca");

	// utility function for storing
	// strings into hashmap
	storeInMap(arr);
	return 0;
}
