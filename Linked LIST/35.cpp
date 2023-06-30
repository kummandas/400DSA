// C++ program to find N'th node from end
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to get the Nth node from
   the last of a linked list*/
void printNthFromLast(struct Node* head, int N)
{
    int len = 0, i;
    struct Node* temp = head;

    // Count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    // Check if value of N is not
    // more than length of the linked list
    if (len < N)
        return;

    temp = head;

    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;

    cout << temp->data;

    return;
}

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Driver's Code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    
      // Function call
    printNthFromLast(head, 4);
    return 0;
}




Output
35
Time complexity: O(M) where M is the size of the linked list
Auxiliary Space: O(1)

Below is a recursive code for the same method. Thanks to Anuj Bansal for providing the following code.

void printNthFromLast(struct Node* head, int N)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, N);
    if (++i == N)
        cout<<head->data;
}










/*

 Time Complexity : O(n) 
 Space complexity: O(1)
 where n is number of nodes in linked list.
   
*/

node *findKthFromLast(node *head, int k)
{
	/*Initialize back and front pointer to head*/
	node *back = head;
	node *front = head;

	//Move front pointer k steps ahead
	for (int i = 0; i < k; i++)
	{
		front = front->next;
	}

	//Move back and front pointer in parallel
	while (front != NULL)
	{
		back = back->next;
		front = front->next;
	}

	//Back will be pointing to k-th node from last
	return back;
}