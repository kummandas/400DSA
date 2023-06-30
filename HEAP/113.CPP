/*/*
    Time Complexity  : O(N) 
    Space Complexity: O(log(N))

    where 'N' is the number of elements in the array.


// Recursive function to heapify ith node
void heapify(vector<int> &arr, int n, int i)
{
    // Defining the pointer the index of node having smallest value among node and its children
    int smallestNode = i;

    // Finding left and right child of current node
    int left = 2 * i + 1, right = 2 * i + 2;

    // Checking if left child is smaller than the current node
    if (left < n && arr[left] < arr[smallestNode])
    {
        smallestNode = left;
    }

    // Checking if right child is smaller than the current node
    if (right < n && arr[right] < arr[smallestNode])
    {
        smallestNode = right;
    }

    // Checking if the current node has the smallest value
    if (smallestNode != i)
    {
        swap(arr[smallestNode], arr[i]);
        heapify(arr, n, smallestNode);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    // Finding the firt non - leaf node from right
    int firstNonLeaf = (n / 2) - 1;

    // Heapifying every non-leaf node
    for (int i = firstNonLeaf; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    return arr;
}
*/


/*
// C++ program for building Heap from Array

#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int N)
{
	// Index of last non-leaf node
	int startIdx = (N / 2) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
	cout << "Array representation of Heap is:\n";

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{
	// Binary Tree Representation
	// of input array
	//			 1
	//		 / \
	//		 3	 5
	//	 / \	 / \
	//	 4	 6 13 10
	// / \ / \
	// 9 8 15 17
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	buildHeap(arr, N);
	printHeap(arr, N);

	// Final Heap:
	//			 17
	//		 / \
	//		 15	 13
	//		 / \	 / \
	//	 9	 6 5 10
	//	 / \ / \
	//	 4 8 3 1

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 
// Data structure to store a max-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> A;
 
    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int PARENT(int i) {
        return (i - 1) / 2;
    }
 
    // return left child of `A[i]`
    int LEFT(int i) {
        return (2*i + 1);
    }
 
    // return right child of `A[i]`
    int RIGHT(int i) {
        return (2*i + 2);
    }
 
    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        // get left and right child of node at index `i`
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int largest = i;
 
        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size() && A[left] > A[i]) {
            largest = left;
        }
 
        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }
 
        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }
 
    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {
        // check if the node at index `i` and its parent violate the heap property
        if (i && A[PARENT(i)] < A[i])
        {
            // swap the two if heap property is violated
            swap(A[i], A[PARENT(i)]);
 
            // call heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }
 
public:
    // return size of the heap
    unsigned int size() {
        return A.size();
    }
 
    // Function to check if the heap is empty or not
    bool empty() {
        return size() == 0;
    }
 
    // insert key into the heap
    void push(int key)
    {
        // insert a new element at the end of the vector
        A.push_back(key);
 
        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }
 
    // Function to remove an element with the highest priority (present at the root)
    void pop()
    {
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
 
            // replace the root of the heap with the last element
            // of the vector
            A[0] = A.back();
            A.pop_back();
 
            // call heapify-down on the root node
            heapify_down(0);
        }
        // catch and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
 
    // Function to return an element with the highest priority (present at the root)
    int top()
    {
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
 
            // otherwise, return the top (first) element
            return A.at(0);        // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
};
 
// Max Heap implementation in C++
int main()
{
    PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
 
    return 0;
}
