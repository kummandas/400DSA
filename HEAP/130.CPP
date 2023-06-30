/*
class Solution{   
public:
    // Function for finding sum of larger numbers
    string findSum(string str1, string str2) {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length()) swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1 - 1; i >= 0; i--) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining digits of str2[]
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry) str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }


    string solve(int arr[], int n) {
        // sort the array
        sort(arr, arr + n);

        // let two numbers be a and b
        string a, b;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && i!=n-1) continue;
            // fill a and b with every alternate digit
            // of input array
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }

        // return the sum
        return findSum(a, b);
    }
};*/
      
// C++ implementation of above approach
/*
#include<bits/stdc++.h>
using namespace std;

// Function to return the required minimum sum
int minSum(vector<int> arr, int n)
{

	// Array to store the
	// frequency of each digit
	int MAX = 10;
	int *freq = new int[MAX];
	for (int i = 0; i < n; i++) {

		// Store count of every digit
		freq[arr[i]]++;
	}

	// Update arr[] such that it is
	// sorted in ascending
	int k = 0;
	for (int i = 0; i < MAX; i++) {

		// Adding elements in arr[]
		// in sorted order
		for (int j = 0; j < freq[i]; j++) {
			arr[k++] = i;
		}
	}

	int num1 = 0;
	int num2 = 0;

	// Generating numbers alternatively
	for (int i = 0; i < n; i++) {

		if (i % 2 == 0)
			num1 = num1 * MAX + arr[i];
		else
			num2 = num2 * MAX + arr[i];
	}

	// Return the minimum possible sum
	return num1 + num2;
}

// Driver code
int main(void)
{
	vector<int>arr = { 6, 8, 4, 5, 2, 3 };
	int n = arr.size();
	cout << minSum(arr, n);
}
// This code is contributed by ankush_953
*/







// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

string solve(int arr[], int n)
{

	sort(arr, arr + n);

	// Two String for storing our two minimum numbers
	string a = "", b = "";

	for (int i = 0; i < n; i += 2) {
		a += (arr[i] + '0');
	}
	for (int i = 1; i < n; i += 2) {
		b += (arr[i] + '0');
	}

	int j = a.length() - 1;
	int k = b.length() - 1;

	// as initial carry is zero
	int carry = 0;
	string ans = "";
	while (j >= 0 && k >= 0) {
		int sum = 0;
		sum += (a[j] - '0') + (b[k] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		j--;
		k--;
	}

	// If string b is over and string a is left
	// here we don't need to put here while condition
	// as it would run at max one time. Because the
	// difference between both the strings could be at
	// max 1.
	while (j >= 0) {
		int sum = 0;
		sum += (a[j] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		j--;
	}

	// If string a is over and string b is left
	while (k >= 0) {
		int sum = 0;
		sum += (b[k] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		k--;
	}
	// if carry is left
	if (carry) {
		ans += to_string(carry);
	}

	// to remove leading zeroes as they will be ahead of our
	// sum
	while (!ans.empty() and ans.back() == '0')
		ans.pop_back();

	// reverse our final string because we were storing sum
	// from left to right
	reverse(ans.begin(), ans.end());
	return ans;
}

// Driver's Code
int main()
{
	int arr[] = { 6, 8, 4, 5, 2, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Sum is " << solve(arr, N);
	return 0;
} // Driver Code Ends
