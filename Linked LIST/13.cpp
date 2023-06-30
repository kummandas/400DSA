// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to insert a node at the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	MergeSort(&a);

	cout << "Sorted Linked List is: \n";
	printList(a);

	return 0;
}

// This is code is contributed by rathbhupendra








/*

    Time Complexity : O(N*LogN)

    Space Complexity :  O(LogN)

    

    Where N is the size of LinkedList.

*/



node* findMid(node *head) {

	if(head == NULL) {

		return head;

	}

	node *slow = head, *fast = head;

	while(fast -> next != NULL && fast -> next -> next != NULL) {

		slow = slow -> next;

		fast = fast -> next -> next;

	}

	return slow;

}



node* merge(node *head1, node *head2) {

	if(head1 == NULL) {

		return head2;

	}

	if(head2 == NULL) {

		return head1;

	}

	node *head = NULL, *tail = NULL;

	if(head1 -> data < head2 -> data) {

		head = head1;

		tail = head1;

		head1 = head1 -> next;

	}

	else {

		head = head2;

		tail = head2;

		head2 = head2 -> next;

	}



	while(head1 != NULL && head2 != NULL) {

		if(head1 -> data < head2 -> data) {

			tail -> next = head1;

			tail = head1;

			head1 = head1 -> next;

		}

		else {

			tail -> next = head2;

			tail = head2;

			head2 = head2 -> next;

		}

	}

	if(head1 != NULL) {

		tail -> next = head1;

	}

	if(head2 != NULL) {

		tail -> next = head2;

	}

	return head;

}



node* mergeSort(node *head) {

	if(head == NULL || head -> next == NULL) {

		return head;

	}

	node *mid = findMid(head);

	node *half1 = head;

	node *half2 = mid -> next;

	mid -> next = NULL;

	half1 = mergeSort(half1);

	half2 = mergeSort(half2);



	node *finalHead = merge(half1, half2);

	return finalHead;

}

