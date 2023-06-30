/*
    Time Complexity  : O(N ^ 2)
    Space Complexity : O(N)

    Where N is the length of target string.
*/

#include<unordered_set>
#include<vector>
#include<iostream>

// Declare a hash map.
unordered_set < string > hashMap;

bool wordBreakHelper(string & s, int start, vector < int > & dp) {
    // Base case
    if (start == s.size()) {
        return dp[start] = 1;
    }

    // If result is already calculated then return it.
    if (dp[start] != -1) {
        return dp[start];
    }

    // Run a loop from 1 to length of target string.
    for (int i = start + 1; i <= s.size(); i++) {
        /*
            If substring from 0 to i exist in hash map
            And remaining string recurs true.
        */
        if (hashMap.find(s.substr(start, i - start)) != hashMap.end()) {
            if (wordBreakHelper(s, i, dp)) {
                return dp[start] = 1;
            }
        }
    }

    // If no solution exist then return false.
    return dp[start] = 0;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Clear hash map for current test case.
    hashMap.clear();

    // Insert all strings of a into hashmap.
    for (string s: arr) {
        hashMap.insert(s);
    }

    // Declare dp array and initialize all values with -1.
    vector < int > dp(target.size() + 1, -1);

    // Call wordBreakHelper to return answer.
    return wordBreakHelper(target, 0, dp);
}












 bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        
        vector<bool> dp(n+1,false);
        dp[0] = true; //You can make empty string with any wordDict
        
        //From every i position check if you can make word ending here
        for(int i=0;i<n;i++)
        {
            //If we can make a word from j->i
            //We need to check if we can make a word till j first
            for(int j=i;j>=0;j--)
            {
                string curr = s.substr(j,i-j+1); //pos,noOfChars
                
                if(dict.find(curr)!=dict.end())
                    dp[i+1] = dp[i+1] || dp[j]; //dp[j] means can be make words before j(dp is 1 indexed)
                
                if(dp[i+1])
                    break;
            }
        }
        
        return dp[n];
    }