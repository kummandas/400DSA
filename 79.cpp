/*
#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string S) {

  vector<int> freq(26);

  int mostFreq = 0, i = 0;

  for (int i = 0; i < S.length(); i++)
  {  freq[S[i] - 'a']++;
      if (freq[S[i] - 'a'] > freq[mostFreq])
        mostFreq = (S[i] - 'a');
  }


  if (freq[mostFreq] > (S.length() + 1) / 2) return "";

  while (freq[mostFreq]) {
      S[i] = ('a' + mostFreq);
      i = i + 2;
      freq[mostFreq]--;
  }

  for (int j = 0; j < 26; j++) {
      while (freq[j]) {
        if (i >= S.length())
            i = 1;
        S[i] = ('a' + j);
        freq[j]--;
        i = i + 2;
      }
  }

  return S;
}

int main()
{
  string s;
  cin >> s;
  cout << rearrangeString(s) << endl;
}
*/

// C code for the above approach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getMaxCountChar(int count[])
{
	int max = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			ch = 'a' + i;
		}
	}

	return ch;
}

char* rearrangeString(char S[])
{
	int N = strlen(S);
	if (N == 0)
		return "";

	int count[26] = { 0 };
	for (int i = 0; i < N; i++)
		count[S[i] - 'a']++;

	char ch_max = getMaxCountChar(count);
	int maxCount = count[ch_max - 'a'];

	char* res = malloc(N * sizeof(int));
	int ind = 0;

	// check if the result is possible or not
	if (maxCount > (N + 1) / 2)
		return res;

	// filling the most frequently occurring char in the
	// even indices
	while (maxCount) {
		res[ind] = ch_max;
		ind = ind + 2;
		maxCount--;
	}

	count[ch_max - 'a'] = 0;

	// Now filling the other Chars, first
	// filling the even positions and then
	// the odd positions
	for (int i = 0; i < 26; i++) {

		while (count[i] > 0) {

			ind = (ind >= N) ? 1 : ind;
			res[ind] = 'a' + i;
			ind += 2;
			count[i]--;
		}
	}

	return res;
}

// Driver's code
int main()
{
	char str[] = { "bbbaa" };

	// Function call
	char* res = rearrangeString(str);
	if (res == "")
		printf("Not possible \n");
	else
		printf("%s \n", res);

	return 0;
}
