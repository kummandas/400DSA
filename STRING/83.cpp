// Recursive Program to remove consecutive
// duplicates from string S.
#include <bits/stdc++.h>
using namespace std;

// A recursive function that removes
// consecutive duplicates from string S
void removeDuplicates(char* S)
{
	// When string is empty, return
	if (S[0] == '\0')
		return;

	// if the adjacent characters are same
	if (S[0] == S[1]) {

		// Shift character by one to left
		int i = 0;
		while (S[i] != '\0') {
			S[i] = S[i + 1];
			i++;
		}

		// Check on Updated String S
		removeDuplicates(S);
	}

	// If the adjacent characters are not same
	// Check from S+1 string address
	removeDuplicates(S + 1);
}

// Driver Program
int main()
{
	char S1[] = "geeksforgeeks";
	removeDuplicates(S1);
	cout << S1 << endl;

	char S2[] = "aabcca";
	removeDuplicates(S2);
	cout << S2 << endl;

	return 0;
}






/*


#include <iostream>
#include <string>

using namespace std;

string deleteConsecutiveStrings(string s)
{
	// Initialize start and stop pointers
	int i = 0;
	int j = 0;

	// Initialize an empty string for new elements
	string newElements = "";

	// Iterate string using j pointer
	while (j < s.length()) {
		// If both elements are same then skip
		if (s[i] == s[j]) {
			j++;
		}
		// If both elements are not same then append new element
		else if (s[j] != s[i] || j == s.length() - 1) {
			newElements += s[i];

			// After appending, slide over the window
			i = j;
			j++;
		}
	}

	// Append the last string
	newElements += s[j - 1];
	return newElements;
}

int main()
{
	// Input
	string s = "geeks for geeks is best";

	// Printing original string
	cout << "Input : " << s << endl;

	// Printing result
	cout << "Output : " << deleteConsecutiveStrings(s) << endl;

	return 0;
}
*/
