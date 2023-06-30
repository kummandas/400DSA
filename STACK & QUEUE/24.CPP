/*/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(N)
	
	Where 'N' is the size of the array,    

class NQueue
{
    // Array to implement the queues.
    vector<int> arr;

    // Array to keep track of the indices of the front elements of every queue.
    vector<int> start;

    // Array to keep track of the indices of the rear elements of every queue.
    vector<int> end;

    // Array to store the next pointers/indices.
    vector<int> next;

    int n, s;

    // Variable to store the starting index of the empty list.
    int temp;

public:
    // Initialize your data structure.
    NQueue(int N, int S)
    {
        n = N;
        s = S;

        // Create the arrays.
        arr = vector<int>(s);
        start = vector<int>(n);
        end = vector<int>(n);
        next = vector<int>(s);

        // Initialize all queues as empty.
        for (int i = 0; i < n; i++)
        {
            start[i] = -1;
            end[i] = -1;
        }

        // Initialize all spaces as empty as initially the complete array is empty.
        for (int i = 0; i < s - 1; i++)
        {
            next[i] = i + 1;
        }

        // Set the last pointer of the empty list to -1 to indicate the end of empty list.
        next[s - 1] = -1;

        // Initialize the starting index of the empty list.
        temp = 0;
    }

    // Enqueues 'X' into the Mth Queue. Returns true if it gets enqueued into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (temp == -1)
        {
            // Array is full. So, element cannot be inserted.
            return false;
        }

        // Store the index of the first empty slot in a temporary variable.
        int index = temp;

        // Update the starting index of the empty list.
        temp = next[index];

        // Check if queue is empty.
        if (start[m - 1] == -1)
        {
            
            // Update start array.
            start[m - 1] = index;
        }
        else
        {

            // Update next element of end.
            next[end[m - 1]] = index;
        }

        // Update next element.
        next[index] = -1;

        // Update end element for the given queue.
        end[m - 1] = index;

        // Put the value to be enqueued into the array.
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth Queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
    int dequeue(int m)
    {
        if (start[m - 1] == -1)
        {
            // Queue is empty. So, return -1.
            return -1;
        }

        // Find the index of the front element of the queue.
        int index = start[m - 1];

        // Remove the element from the queue by updating the front of the stack list.
        start[m - 1] = next[index];

        // Add the empty slot to the empty list.
        next[index] = temp;
        temp = index;

        // Return the popped element.
        return arr[index];
    }
};*/






// A C++ program to demonstrate implementation
// of k queues in a single
// array in time and space efficient way
#include<iostream>
#include<climits>
using namespace std;

// A C++ class to represent k queues
// in a single array of size n
class kQueues
{
	// Array of size n to store actual
	// content to be stored in queue
	int *arr;

	// Array of size k to store indexes
	// of front elements of the queue
	int *front;

	// Array of size k to store indexes
	// of rear elements of queue
	int *rear;

	// Array of size n to store next
	// entry in all queues		
	int *next;
	int n, k;

	int free; // To store the beginning index of the free list

public:
	//constructor to create k queue
	// in an array of size n
	kQueues(int k, int n);

	// A utility function to check if
	// there is space available
	bool isFull() { return (free == -1); }

	// To enqueue an item in queue number
	// 'qn' where qn is from 0 to k-1
	void enqueue(int item, int qn);

	// To dequeue an from queue number
	// 'qn' where qn is from 0 to k-1
	int dequeue(int qn);

	// To check whether queue number
	// 'qn' is empty or not
	bool isEmpty(int qn) { return (front[qn] == -1); }
};

// Constructor to create k queues
// in an array of size n
kQueues::kQueues(int k1, int n1)
{
	// Initialize n and k, and allocate
	// memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number
// 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
	// Underflow checkSAS
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	// Change top to store next of previous top
	front[qn] = next[i];

	// Attach the previous front to the
	// beginning of free list
	next[i] = free;
	free = i;

	// Return the previous front item
	return arr[i];
}

/* Driver program to test kStacks class */
int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}
