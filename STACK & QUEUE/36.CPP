/*/*
    Time Complexity: O(K*26*Log26 + N)
    Space Complexity: O(1),

    where N is the length of the string and K is the number of characters to be removed.

int minimumValueFunction(string &s, int n, int k) {

	// frequency array to store the count of all unique characters
	int freqArr[26] = {0};
	for (int i = 0; i < n; i++) {
		freqArr[s[i] - 'a']++;
	}

	// K times sort the frequency array and,
	// decrementing the highest element by 1.
	while (k--)
	{
		sort(freqArr, freqArr + 26);
		freqArr[25]--;
	}

	// To store the fianl answer.
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += freqArr[i] * freqArr[i];
	}

	return ans;
}*/





/*/*
    Time Complexity: O(K*Log(26)+N)
    Space Complexity: O(1),

    where N is the length of the string and K is the number of characters to be removed.

int minimumValueFunction(string &s, int n, int k) {

	// frequency array to store the count of all unique characters
	int freqArr[26] = {0};
	for (int i = 0; i < n; i++) {
		freqArr[s[i] - 'a']++;
	}

	// priority queue for maintaining the decreasing order after every removal.
	priority_queue<int>pq;
	for (int i = 0; i < 26; i++) {
		pq.push(freqArr[i]);
	}

	// K times we are decrementing the highest frequency element by 1.
	while (k--) {
		int highestFrequency = pq.top();
		pq.pop();
		highestFrequency--;
		pq.push(highestFrequency);
	}

	// To store the answer.
	int ans = 0;
	// Run a loop till pq become empty to add the squares to the answer.
	while (!pq.empty()) {
		int highestFrequency = pq.top();
		pq.pop();
		ans += highestFrequency * highestFrequency;
	}

	return ans;
}*/



// C++ program to find min sum of squares
// of characters after k removals
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Main Function to calculate min sum of
// squares of characters after k removals
int minStringValue(string str, int k)
{
	int l = str.length(); // find length of string

	// if K is greater than length of string
	// so reduced string will become 0
	if (k >= l)
		return 0;

	// Else find Frequency of each character and
	// store in an array
	int frequency[MAX_CHAR] = { 0 };
	for (int i = 0; i < l; i++)
		frequency[str[i] - 'a']++;

	// Push each char frequency into a priority_queue
	priority_queue<int> q;
	for (int i = 0; i < MAX_CHAR; i++)
		q.push(frequency[i]);

	// Removal of K characters
	while (k--) {
		// Get top element in priority_queue,
		// remove it. Decrement by 1 and again
		// push into priority_queue
		int temp = q.top();
		q.pop();
		temp = temp - 1;
		q.push(temp);
	}

	// After removal of K characters find sum
	// of squares of string Value
	int result = 0; // Initialize result
	while (!q.empty()) {
		int temp = q.top();
		result += temp * temp;
		q.pop();
	}

	return result;
}

// Driver Code
int main()
{
	string str = "abbccc"; // Input 1
	int k = 2;
	cout << minStringValue(str, k) << endl;

	str = "aaab"; // Input 2
	k = 2;
	cout << minStringValue(str, k);

	return 0;
}






















// N
// N
// C++ program to find min sum of squares
// of characters after k removals
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Main Function to calculate min sum of
// squares of characters after k removals
int minStringValue(string str, int k)
{
	int alphabetCount[MAX_CHAR]= {0};

	// Here the array stored frequency the number of
	// occurrences in string m[frequency]=number of alphabets
	// with frequency i.e, in our example abbccc m[1]=1(1
	// a's occur),m[2]=1(2 b's occur),m[3]=1(3 c'soccur)
	int m[str.length()] = { 0 };
	
	for (int i = 0; i < str.length(); i++) {
		alphabetCount[str[i] - 'a']++;
	}
	// Store the maximum
	int maximum = 0;
	
	for (int i = 0; i < MAX_CHAR; i++) {
		m[alphabetCount[i]]++;
		maximum = max(maximum, alphabetCount[i]);
	}

	while (k > 0) {
		int z = m[maximum];
		if (z <= k) {
			// Remove one occurrence of alphabet from each
			// with frequency as maximum.
			// So we will have k-z more remove operations to
			// perform as z is number of characters and we
			// perform one removal from each of the alphabet
			// with that frequency.
			k = k - z;
			// As we removed one occurrence from each the
			// alphabets will no longer have the frequency
			// of maximum their frequency will be decreased
			// by one so add these number of alphabets to
			// group with frequency one less than maximum.
			// Remove them from maximum count.
			m[maximum] = 0;
			// Add those to frequency one less.
			m[maximum - 1] += z;
			// new maximum will be one less.
			maximum--;
		}
		else {
			// if all the elements of that frequency cannot
			// be removed we should partially remove them.
			m[maximum] -= k;
			maximum--;
			m[maximum] += k;
			k = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		//(square of frequency)*(number of
		// characters corresponding to that frequency)
		ans += (i * i) * m[i];
	}

	return ans;
}

// Driver Code
int main()
{
	string str = "abbccc"; // Input 1
	int k = 2;
	cout << minStringValue(str, k) << endl;

	str = "aaab"; // Input 2
	k = 2;
	cout << minStringValue(str, k);

	return 0;
}

// This code is contributed by Kasina Dheeraj.
