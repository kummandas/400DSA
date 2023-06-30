/*/*
   Time Complexity:O(n)
   Space Complexity:O(1)

   where 'n' is the number of elements in the array

void heapify(vector<int>&arr, int n, int index)
{
	int largest = index;

	// If left child is greater than replace it with node
	if (2 * index + 1 < n && arr[largest] < arr[2 * index + 1])
	{
		largest = 2 * index + 1;
	}

	// If right child is greater than replace it with node
	if (2 * index + 2 < n && arr[largest] < arr[2 * index + 2])
	{
		largest = 2 * index + 2;
	}

	// If any child has more value call heapify on corresponding sub-tree.
	if (largest != index)
	{
		swap(arr[largest], arr[index]);
		heapify(arr, n, largest);
	}


}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
    
	// Calling heapify process in bottom-up manner.
	for (int i = n / 2; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	return arr;
}*/

// A C++ program to convert min Heap to max Heap

#include <bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < N && arr[l] > arr[i])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, N);
    }
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int N)
{
    // Start from bottommost and rightmost
    // internal node and heapify all internal
    // nodes in bottom up way
    for (int i = (N - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}

// A utility function to print a given array
// of given size
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

// Driver's code
int main()
{
    // array representing Min Heap
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Min Heap array : ");
    printArray(arr, N);

    // Function call
    convertMaxHeap(arr, N);

    printf("\nMax Heap array : ");
    printArray(arr, N);

    return 0;
}