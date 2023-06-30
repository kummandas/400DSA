/*
	Time Complexity: O(N)
	Space Complexity: O(N / K)

	Where 'N' is the number of nodes in the doubly linked list and 'K' is the group size.
*/

Node* reverseDLLInGroups(Node* head, int k)
{	
	// Base condition.
	if(head == NULL)
	{
		return NULL;
	}
	
	Node* curr = head, *last = NULL, *ahead;
	int count = k;
	
	// Reversing the first K nodes.
	while(curr != NULL and count > 0)
	{
		ahead = curr->next;
		curr->next = last;
		if(last != NULL)
		{
			last->prev = curr;
		}
		last = curr;
		curr = ahead; 
		count -= 1;
	}
	
	// Recursively calling for the the remaining list.
	head->next = reverseDLLInGroups(curr, k); 
	
	// Returning the new head.
	return last;
     
}



/*
	Time Complexity: O(N)
	Space Complexity: O(1)
	
	Where 'N' is the number of nodes in the doubly linked list.
*/

Node* reverseDLLInGroups(Node* head, int k)
{	
    Node* last = NULL, *curr = head, *ahead = NULL; 
    Node* tail = NULL, *join = NULL; 
    
    Node* newHead = NULL; 
    int count = 0; 
  
    // Traverse the linked list to the end.
    while (curr != NULL) 
	{ 
        count = k; 
        join = curr; 
        last = NULL; 
  
        // Reversing the k nodes.
        while (curr && count > 0) 
		{ 
            ahead = curr->next; 
            curr->next = last;
            if(last != NULL)
            {
            	last->prev = curr;
            }
            last = curr; 
            curr = ahead; 
            count -= 1;
        } 
  
        // Update the new head for the modified linked list.
        if (newHead == NULL) 
        {
            newHead = last; 
        }
  
        //  Tail pointer is joined with the first node of the remaining linked list.
        if (tail)
        {
            tail->next = last; 
            last->prev = tail;
        }
        
        // Updating tail for the next iteration. 
        tail = join;  
    } 
  
    // New head of the modified list is returned.
    return newHead;
}

















// C++ implementation to reverse a doubly linked list
// in groups of given size
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocate space
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list of the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	Node *current = head;
	Node* next = NULL;
	Node* newHead = NULL;
	int count = 0;
	
	// reversing the current group of k
	// or less than k nodes by adding
	// them at the beginning of list
	// 'newHead'
	while (current != NULL && count < k)
	{
		next = current->next;
		push(&newHead, current);
		current = next;
		count++;
	}
	
	// if next group exists then making the desired
	// adjustments in the link
	if (next != NULL)
	{
		head->next = revListInGroupOfGivenSize(next, k);
		head->next->prev = head;
	}
	
	// pointer to the new head of the
	// reversed group
	// pointer to the new head should point to NULL, otherwise you won't be able to traverse list in reverse order using 'prev'
	newHead->prev = NULL;
	return newHead;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	push(&head, getNode(2));
	push(&head, getNode(4));
	push(&head, getNode(8));
	push(&head, getNode(10));
	
	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);

	return 0;
}
















// C++ implementation to reverse a doubly linked list
// in groups of given size without recursion
// Iterative Method

#include <iostream>
using namespace std;

// Represents a node of doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocating node
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
Node* push(Node* head, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list of the new node
	new_node->next = head;
	// change prev of head node to new node
	if (head != NULL)
		head->prev = new_node;

	// move the head to point to the new node
	head = new_node;
	return head;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	if (!head)
		return head;

	Node* st = head;
	Node* globprev = NULL;
	Node* ans = NULL;
	while (st) {
		int count = 1; // to count k nodes
		Node* curr = st;
		Node* prev = NULL;
		Node* next = NULL;
		while (curr && count <= k) { // reversing k nodes
			next = curr->next;
			curr->prev = next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}

		if (!ans) {
			ans = prev; // to store ans i.e the new head
			ans->prev = NULL;
		}

		if (!globprev)
			globprev = st; // assigning the last node of the
						// reversed k nodes
		else {
			globprev->next = prev;
			prev->prev
				= globprev; // connecting last node of last
							// k group to the first node of
							// present k group
			globprev = st;
		}

		st = curr; // advancing the pointer for the next k
				// group
	}
	return ans;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver code
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	head = push(head, getNode(2));
	head = push(head, getNode(4));
	head = push(head, getNode(8));
	head = push(head, getNode(10));

	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);
	return 0;
}

// This code is contributed by Tapesh (tapeshdua420)
