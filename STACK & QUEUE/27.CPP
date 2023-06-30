// CPP program to reverse a Queue
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

// Function to reverse the queue
void reverseQueue(queue<int>& q)
{
	// base case
	if (q.size() == 0)
		return;
	// storing front(first element) of queue
	int fr = q.front();

	// removing front
	q.pop();

	// asking recursion to reverse the
	// leftover queue
	reverseQueue(q);

	// placing first element
	// at its correct position
	q.push(fr);
}

// Driver code
int main()
{
	queue<int> Queue;
	Queue.push(10);
	Queue.push(20);
	Queue.push(30);
	Queue.push(40);
	Queue.push(50);
	Queue.push(60);
	Queue.push(70);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);

	reverseQueue(Queue);
	Print(Queue);
}
// This code is contributed by Nakshatra Chhillar


/*/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the size of the queue


void reverse(queue < int > & q) {

    // Size of the given queue.
    int n = q.size();

    // Initialise vector.
    vector < int > nums(n);

    for (int i = n - 1; i >= 0; --i) {

        // Fill the vector from back.
        nums[i] = q.front();
        q.pop();
    }

    for (int i = 0; i < n; i++) {

        // Now push the elements from vector back to the queue.
        q.push(nums[i]);
    }
}*/






/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the size of the queue
*/

void reverse(queue < int > & q) {

    // Size of the given queue.
    int n = q.size();

    // Initialise vector.
    vector < int > nums(n);

    for (int i = n - 1; i >= 0; --i) {

        // Fill the vector from back.
        nums[i] = q.front();
        q.pop();
    }

    for (int i = 0; i < n; i++) {

        // Now push the elements from vector back to the queue.
        q.push(nums[i]);
    }
}