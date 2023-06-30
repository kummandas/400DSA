#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
// Made a class node containing data and previous pointer as
// we are using tail pointer
class Node {
public:
	int data;
	Node* prev;
	Node(int n)
	{
		data = n;
		prev = NULL;
	}
};

void Multiply(Node* tail, int n)
{
	Node *temp = tail,
		*prevNode = tail; // Temp variable for keeping tail
	int carry = 0;
	while (temp != NULL) {
		int data = temp->data * n + carry;
		temp->data = data % 10; // stores the last digit
		carry = data / 10;
		prevNode = temp;
		temp = temp->prev; // Moving temp by 1 prevNode will
						// now denote temp
	}
	// If carry is greater than 0 then we create another
	// node for it.
	while (carry != 0) {
		prevNode->prev = new Node((int)(carry % 10));
		carry /= 10;
		prevNode = prevNode->prev;
	}
}

void print(Node* tail)
{
	if (tail == NULL) // Using tail recursion
		return;
	print(tail->prev);
	cout
		<< tail->data; // Print linked list in reverse order
}

// Driver code
int main()
{
	int n = 20;
	Node tail(1); // Create a node and initialise it by 1
	rep(i, 2, n)
		Multiply(&tail, i); // Run a loop from 2 to n and
							// multiply with tail's i
	print(&tail); // Print the linked list
	cout << endl;
	return 0;
}










// C++ program to compute factorial of big numbers
#include <iostream>
using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3
	// * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);

	cout << "Factorial of given number is \n";
	for (int i = res_size - 1; i >= 0; i--)
		cout << res[i];
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
	int carry = 0; // Initialize carry

	// One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[]
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

// Driver program
int main()
{
	factorial(100);
	return 0;
}
