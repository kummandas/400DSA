/*#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	// Given Appointments.
	vector<vector<int> > v{
		{ 1, 5 }, { 3, 7 }, { 2, 6 },
		{ 10, 15 }, { 5, 6 }, { 4, 100 }
	};
	// sort according to start time of meet/appointment.
	// sort(v.begin(), v.end());
	// number of pair or appointments.
	int n = v.size();
	// for stoping the overlapping
	// vector<bool>vis(n,0);
	// traverse over and check for it.
	vector<pair<pair<int, int>, pair<int, int> > > result;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			// to reduce extra/unwanted comparisons.
			// if(v[j][0]>v[i][1])break;
			// else{
			if (v[j][0] < v[i][1]) {
				result.push_back({ { v[i][0], v[i][1] },
								{ v[j][1], v[j][0] } });
			}
			// }
		}
	}
	// final output.
	for (auto it : result) {
		cout << "[" << it.first.first << ","
			<< it.first.second
			<< "] having Conflict with [";
		cout << it.second.first << "," << it.second.second
			<< "]" << endl;
	}
	// code by Sanket Gode.
	return 0;
}
*/














// C++ program to print all conflicting appointments in a
// given set of appointments
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an interval
struct Interval
{
	int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
	Interval *i; // 'i' could also be a normal variable
	int max;
	ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
	ITNode *temp = new ITNode;
	temp->i = new Interval(i);
	temp->max = i.high;
	temp->left = temp->right = NULL;
	return temp;
};

// A utility function to insert a new Interval Search Tree
// Node. This is similar to BST Insert. Here the low value
// of interval is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
	// Base case: Tree is empty, new node becomes root
	if (root == NULL)
		return newNode(i);

	// Get low value of interval at root
	int l = root->i->low;

	// If root's low value is smaller, then new interval
	// goes to left subtree
	if (i.low < l)
		root->left = insert(root->left, i);

	// Else, new node goes to right subtree.
	else
		root->right = insert(root->right, i);

	// Update the max value of this ancestor if needed
	if (root->max < i.high)
		root->max = i.high;

	return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
	if (i1.low < i2.high && i2.low < i1.high)
		return true;
	return false;
}

// The main function that searches a given interval i
// in a given Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
	// Base Case, tree is empty
	if (root == NULL) return NULL;

	// If given interval overlaps with root
	if (doOVerlap(*(root->i), i))
		return root->i;

	// If left child of root is present and max of left child
	// is greater than or equal to given interval, then i may
	// overlap with an interval is left subtree
	if (root->left != NULL && root->left->max >= i.low)
		return overlapSearch(root->left, i);

	// Else interval can only overlap with right subtree
	return overlapSearch(root->right, i);
}

// This function prints all conflicting appointments in a given
// array of appointments.
void printConflicting(Interval appt[], int n)
{
	// Create an empty Interval Search Tree, add first
	// appointment
	ITNode *root = NULL;
	root = insert(root, appt[0]);

	// Process rest of the intervals
	for (int i=1; i<n; i++)
	{
		// If current appointment conflicts with any of the
		// existing intervals, print it
		Interval *res = overlapSearch(root, appt[i]);
		if (res != NULL)
			cout << "[" << appt[i].low << "," << appt[i].high
				<< "] Conflicts with [" << res->low << ","
				<< res->high << "]\n";

		// Insert this appointment
		root = insert(root, appt[i]);
	}
}


// Driver program to test above functions
int main()
{
	// Let us create interval tree shown in above figure
	Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15},
						{5, 6}, {4, 100}};
	int n = sizeof(appt)/sizeof(appt[0]);
	cout << "Following are conflicting intervals\n";
	printConflicting(appt, n);
	return 0;
}























/*/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    Where N is the number of meetings.


#include<algorithm>

vector < int > findConflictingMeetings(vector < vector < int >> & meetings) {
    
    // Finding the number of meetings.
    int n = meetings.size();

    // Defining the array to store the meetings in sorted order.
    vector < vector < int >> sortedMeetings(n, vector < int > (3));

    // Adding elements to the array.
    for (int i = 0; i < n; i++) {
        sortedMeetings[i][0] = meetings[i][0];
        sortedMeetings[i][1] = meetings[i][1];
        sortedMeetings[i][2] = i + 1;
    }

    // Sorting the array based on start time.
    sort(sortedMeetings.begin(), sortedMeetings.end());

    // Defining the variables to store the latest ending meeting and latest ending time.
    int index = sortedMeetings[0][2], highestEndTime = sortedMeetings[0][1];

    // Initializing all elements of output array as -1.
    vector < int > ans(n, -1);

    // Iterating through the sorted meeting intervals.
    for (int i = 1; i < n; i++) {

        // Checking if meeting overlap with the meeting with highest end time.
        if (sortedMeetings[i][0] < highestEndTime) {
            ans[sortedMeetings[i][2] - 1] = index;
            ans[index - 1] = sortedMeetings[i][2];
        }

        // Checking if the current meeting has the highest end time.
        if (sortedMeetings[i][1] > highestEndTime) {
            index = sortedMeetings[i][2];
            highestEndTime = sortedMeetings[i][1];
        }
    }

    return ans;
}*/