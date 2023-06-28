// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

bool checkString(string& s1, string& s2, int indexFound,
				int Size)
{
	for (int i = 0; i < Size; i++) {
		// check whether the character is equal or not
		if (s1[i] != s2[(indexFound + i) % Size])
			return false;
		// %Size keeps (indexFound+i) in bounds, since it
		// ensures it's value is always less than Size
	}

	return true;
}

int main()
{

	string s1 = "abcd";
	string s2 = "cdab";

	if (s1.length() != s2.length()) {
		cout << "s2 is not a rotation on s1" << endl;
	}
	else {
		// store occurrences of the first character of s1
		vector<int> indexes;

		int Size = s1.length();

		char firstChar = s1[0];

		for (int i = 0; i < Size; i++) {
			if (s2[i] == firstChar) {
				indexes.push_back(i);
			}
		}

		bool isRotation = false;

		// check if the strings are rotation of each other
		// for every occurrence of firstChar in s2
		for (int idx : indexes) {
			isRotation = checkString(s1, s2, idx, Size);

			if (isRotation)
				break;
		}

		if (isRotation)
			cout << "Strings are rotations of each other"
				<< endl;
		else
			cout
				<< "Strings are not rotations of each other"
				<< endl;
	}
	return 0;
}







// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

bool check_rotation(string s, string goal)
{
	if (s.size() != goal.size())
		return false;

	queue<char> q1;
	for (int i = 0; i < s.size(); i++) {
		q1.push(s[i]);
	}

	queue<char> q2;
	for (int i = 0; i < goal.size(); i++) {
		q2.push(goal[i]);
	}

	int k = goal.size();
	while (k--) {
		char ch = q2.front();
		q2.pop();
		q2.push(ch);
		if (q2 == q1)
			return true;
	}
	return false;
}

// Driver code
int main()
{
	string str1 = "AACD", str2 = "ACDA";

	if (check_rotation(str1, str2))
		printf("Strings are rotations of each other");
	else
		printf("Strings are not rotations of each other");
	return 0;
}
