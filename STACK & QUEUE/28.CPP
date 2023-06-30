// C++ program to reverse first
// k elements of a queue.
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse the first
K elements of the Queue */
void reverseQueueFirstKElements(int k, queue<int>& Queue)
{
	if (Queue.empty() == true || k > Queue.size())
		return;
	if (k <= 0)
		return;

	stack<int> Stack;

	/* Push the first K elements
	into a Stack*/
	for (int i = 0; i < k; i++) {
		Stack.push(Queue.front());
		Queue.pop();
	}

	/* Enqueue the contents of stack
	at the back of the queue*/
	while (!Stack.empty()) {
		Queue.push(Stack.top());
		Stack.pop();
	}

	/* Remove the remaining elements and
	enqueue them at the end of the Queue*/
	for (int i = 0; i < Queue.size() - k; i++) {
		Queue.push(Queue.front());
		Queue.pop();
	}
}

/* Utility Function to print the Queue */
void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
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

	int k = 5;
	reverseQueueFirstKElements(k, Queue);
	Print(Queue);
}

// C++ program to reverse first
// k elements of a queue using dequeue.
#include <deque>
#include <iostream>
#include <queue>

using namespace std;
// Function to reverse first k element of the queue
void reverseFirstK(queue<int>& q, int k)
{
	deque<int> d;

	// Dequeue the first k elements of the queue and push
	// them onto a deque
	for (int i = 0; i < k; i++) {
		d.push_front(q.front());
		q.pop();
	}

	// Pop the elements from the deque and enqueue them back
	// into the queue
	while (!d.empty()) {
		q.push(d.front());
		d.pop_front();
	}

	// Dequeue the remaining elements from the queue and
	// enqueue them back into the queue
	for (int i = 0; i < q.size() - k; i++) {
		q.push(q.front());
		q.pop();
	}
}
// Driver code.
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	q.push(100);

	int k = 5;

	// function call.
	reverseFirstK(q, k);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
