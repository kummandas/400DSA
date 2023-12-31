/*class Solution
{
    public:
    void helper(string s,string &largestNumber,int k,int idx)
    {
        // agar number of swaps khatam hogaye toh return hojao
        if(k==0) 
        {
            return;
        }
        int n = s.size();
        // current string ka first character hum maan rahe hai ki largest character hai string mein
        char maxChar = s[idx];
        // ab string mein aage traverse karke find karne ki koshish karenge ki current max character max hai ya aage koyi aur character hai 
        // jo ki maximum character ban sakta hai toh usse appne paas rakhlenge
        for(int i=idx+1;i<n;i++)
        {
            if(maxChar<s[i])
            {
                maxChar = s[i];
            }
        }
        // agar current character jisse humne max character maana tha intially maximum character nahi hai toh iska matlab swap karna padega
        if(maxChar!=s[idx])
        {
            k -= 1;
        }
        for(int i=idx;i<n;i++)
        {
            // ab hum string mein traverse karke maximum character ki position tak jaayenge and phir current character and maximum character
            //  ko swap karke check karenge ki current string maximum hai ya phir largestNumber waala string maximum hai
            if(s[i]==maxChar)
            {
                swap(s[i],s[idx]);
                if(s.compare(largestNumber)>0)
                {
                    largestNumber = s;
                }
                helper(s,largestNumber,k,idx+1);
                // backtracking step
                swap(s[i],s[idx]);
            }
        }
    }
    
    
    string findMaximumNum(string str, int k)
    {
    //   Hum initially yehi maan kar chal rahe hai ki hamara given string hi maximum string hai
       string largestNumber = str;
       helper(str,largestNumber,k,0);
       return largestNumber;
    }
};*/


// C++ program to find maximum
// integer possible by doing
// at-most K swap operations on
// its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap operations
// on its digits
void findMaximumNum(
	string str, int k,
	string& max, int ctr)
{
	// return if no swaps left
	if (k == 0)
		return;

	int n = str.length();

	// Consider every digit after
	// the cur position
	char maxm = str[ctr];
	for (int j = ctr + 1; j < n; j++) {
		// Find maximum digit greater
		// than at ctr among rest
		if (maxm < str[j])
			maxm = str[j];
	}

	// If maxm is not equal to str[ctr],
	// decrement k
	if (maxm != str[ctr])
		--k;

	// search this maximum among the rest from behind
	//first swap the last maximum digit if it occurs more than 1 time
//example str= 1293498 and k=1 then max string is 9293418 instead of 9213498
	for (int j = n-1; j >=ctr; j--) {
		// If digit equals maxm swap
		// the digit with current
		// digit and recurse for the rest
		if (str[j] == maxm) {
			// swap str[ctr] with str[j]
			swap(str[ctr], str[j]);

			// If current num is more than
			// maximum so far
			if (str.compare(max) > 0)
				max = str;

			// recurse other swaps after cur
			findMaximumNum(str, k, max, ctr + 1);

			// Backtrack
			swap(str[ctr], str[j]);
		}
	}
}

// Driver code
int main()
{
	string str = "129814999";
	int k = 4;

	string max = str;
	findMaximumNum(str, k, max, 0);

	cout << max << endl;

	return 0;
}
