/* C++ Program to remove duplicates in an unsorted
linked list 
#include <bits/stdc++.h>
using namespace std;

/* A linked list node 
struct Node {
	int data;
	struct Node* next;
};

// Utility function to create a new Node
struct Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Function to remove duplicates from a
unsorted linked list 
void removeDuplicates(struct Node* start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	/* Pick elements one by one 
	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		/* Compare the picked element with rest
		of the elements 
		while (ptr2->next != NULL) {
			/* If duplicate then delete it 
			if (ptr1->data == ptr2->next->data) {
				/* sequence of steps is important here 
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete (dup);
			}
			else /* This is tricky 
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

/* Function to print nodes in a given linked list 
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

// Driver code
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10
	struct Node* start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next = newNode(11);
	start->next->next->next->next->next->next = newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);
	return 0;
}
*/




#include <bits/stdc++.h>
using namespace std;

// structure of a node in the linked list
struct Node {
int data;
struct Node* next;
};

// function to insert a node in the linked list
void push(struct Node** head_ref, int new_data)
{
struct Node* new_node = new Node;
new_node->data = new_data;
new_node->next = (*head_ref);
(*head_ref) = new_node;
}

// function to sort the linked list
void sortList(struct Node* head)
{
// pointer to traverse the linked list
struct Node* current = head;
struct Node* index = NULL;

// loop to traverse the linked list
while (current != NULL) {

// loop to compare current node with all other nodes
index = current->next;
while (index != NULL) {

// checking for duplicate values
if (current->data == index->data) {

// deleting the duplicate node
current->next = index->next;
free(index);
index = current->next;
}
else {
index = index->next;
}
}
current = current->next;
}
}

// function to display the linked list
void printList(struct Node* node)
{
while (node != NULL) {
cout << node->data << " ";
node = node->next;
}
cout << endl;
}

// main function
int main()
{
struct Node* head = NULL;
push(&head, 20);
push(&head, 13);
push(&head, 13);
push(&head, 11);
push(&head, 11);
push(&head, 11);

cout << "Linked List before removing duplicates : \n";
printList(head);

sortList(head);

cout << "Linked List after removing duplicates : \n";
printList(head);

return 0;
}
//This code is contributed by Veerendra Singh Rajpoot













/* C++ Program to remove duplicates in an unsorted
linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
struct Node {
	int data;
	struct Node* next;
};

// Utility function to create a new Node
struct Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Function to remove duplicates from a
unsorted linked list */
void removeDuplicates(struct Node* start)
{
	// Hash to store seen values
	unordered_set<int> seen;

	/* Pick elements one by one */
	struct Node* curr = start;
	struct Node* prev = NULL;
	while (curr != NULL) {
		// If current value is seen before
		if (seen.find(curr->data) != seen.end()) {
			prev->next = curr->next;
			delete (curr);
		}
		else {
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above function */
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10*/
	struct Node* start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next = newNode(11);
	start->next->next->next->next->next->next = newNode(10);

	printf("Linked list before removing duplicates : \n");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates : \n");
	printList(start);

	return 0;
}
