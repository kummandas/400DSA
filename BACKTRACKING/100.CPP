//Back-end complete function Template for C++
/*
class Solution {
  public:
    // A utility function to check if str is palindroem 
    bool isPalindrome(string str, int low, int high) 
    { 
        while (low < high) 
        { 
            if (str[low] != str[high]) 
                return false; 
            low++; 
            high--; 
        } 
        return true; 
    }

    // Recursive function to find all palindromic partitions of str[start..n-1] 
    // allPart --> A vector of vector of strings. Every vector inside it stores 
    //             a partition 
    // currPart --> A vector of strings to store current partition  
    void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,  
                       int start, int n, string str) 
    { 
        // If 'start' has reached len 
        if (start >= n) 
        { 
            allPart.push_back(currPart); 
            return; 
        } 
      
        // Pick all possible ending points for substrings 
        for (int i=start; i<n; i++) 
        { 
            // If substring str[start..i] is palindrome 
            if (isPalindrome(str, start, i)) 
            { 
                // Add the substring to result 
                currPart.push_back(str.substr(start, i-start+1)); 
      
                // Recur for remaining remaining substring 
                allPalPartUtil(allPart, currPart, i+1, n, str); 
                  
                // Remove substring str[start..i] from current  
                // partition 
                currPart.pop_back(); 
            } 
        } 
    }

    vector<vector<string>> allPalindromicPerms(string S) {
        int n = S.length(); 
  
        // To Store all palindromic partitions 
        vector<vector<string> > allPart; 
      
        // To store current palindromic partition 
        vector<string> currPart;  
      
        // Call recursive function to generate all partiions 
        // and store in allPart 
        allPalPartUtil(allPart, currPart, 0, n, S); 

        return allPart;
    }
};*/



/*class Solution {
  public:
  void solve(int index,string s, vector<string>&path,vector<vector<string>>&ans){
      if(index>=s.size()){
          ans.push_back(path);
          return;
      }
        
    for(int i=index;i<s.size();i++){
        if(isPalind(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            solve(i+1,s,path,ans);
            //backtrack
            path.pop_back();
        }
    }
  }
  bool isPalind(string s,int start,int end){
      while(start<=end){
          if(s[start++]!=s[end--]){
              return false;
          }
      }
      return true;
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,S,path,ans);
        return ans;
    }
};*/



// C++ program to print all palindromic partitions
// of a given string.
#include <bits/stdc++.h>
using namespace std;

// Returns true if str is palindrome, else false
bool checkPalindrome(string str)
{
    int len = str.length();
    len--;
    for (int i=0; i<len; i++)
    {
        if (str[i] != str[len])
            return false;
        len--;
    }
    return true;
}

void printSolution(vector<vector<string> > partitions)
{
    for (int i = 0; i < partitions.size(); ++i)
    {
        for(int j = 0; j < partitions[i].size(); ++j)
            cout << partitions[i][j] << " ";
        cout << endl;
    }
    return;
}

// Goes through all indexes and recursively add remaining
// partitions if current string is palindrome.
void addStrings(vector<vector<string> > &v, string &s,
                vector<string> &temp, int index)
{
    int len = s.length();
    string str;
    vector<string> current = temp;
    if (index == 0)
        temp.clear();
    for (int i = index; i < len; ++i)
    {
        str = str + s[i];
        if (checkPalindrome(str))
        {
            temp.push_back(str);
            if (i+1 < len)
                addStrings(v,s,temp,i+1);
            else
                v.push_back(temp);
            temp = current;
        }
    }
    return;
}

// Generates all palindromic partitions of 's' and
// stores the result in 'v'.
void partition(string s, vector<vector<string> >&v)
{
    vector<string> temp;
    addStrings(v, s, temp, 0);
    printSolution(v);
    return;
}

// Driver code
int main()
{
    string s = "geeks";
    vector<vector<string> > partitions;
    partition(s, partitions);
    return 0;
}