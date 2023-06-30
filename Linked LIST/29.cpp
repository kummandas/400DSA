/*
class Solution
{
    public:

//#Approach 2 function
    void insertAtTail(Node* &tail,Node* curr){
        tail->next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        //#Approach 1
    // int zeroCount = 0;
    // int oneCount = 0;
    // int twoCount = 0;
    // Node* temp = head;
    // while(temp!=NULL){
    //     if(temp->data == 0){
    //         zeroCount++;
    //     }
    //     else if (temp->data == 1){
    //         oneCount++;
    //     }
    //     else if(temp->data == 2){
    //         twoCount++;
    //     }
    //     temp = temp->next;
    // }
    // temp = head;
    // while(temp != NULL){
    //     if(zeroCount != 0){
    //         temp->data = 0;
    //         zeroCount--;
    //     }
    //     else if(oneCount != 0){
    //         temp->data = 1;
    //         oneCount--;
    //     }
    //     else if(twoCount != 0){
    //         temp->data = 2;
    //         twoCount--;
    //     }
    //     temp=temp->next;
    // }
    // return head;
    //#Approach 2
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr != NULL){
        int value = curr->data;
        if(value ==0){
            insertAtTail(zeroTail,curr);
        }
        else if(value == 1){
            insertAtTail(oneTail,curr);
        }
        else if(value==2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    //is list not Empty
    if(oneHead ->next != NULL){
        zeroTail->next = oneHead ->next;
    }
    else{
        //is list->empty
        zeroTail ->next =twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next=NULL;
    
    //setup head
    head = zeroHead->next;
    
    //delete a dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    
    }
};















*/
// CPP Program to sort a linked list 0s, 1s
// or 2s by changing links
#include <bits/stdc++.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data);

// Sort a linked list of 0s, 1s and 2s
// by changing pointers.
Node* sortList(Node* head)
{
	if (!head || !(head->next))
		return head;

	// Create three dummy nodes to point to beginning of
	// three linked lists. These dummy nodes are created to
	// avoid many null checks.
	Node* zeroD = newNode(0);
	Node* oneD = newNode(0);
	Node* twoD = newNode(0);

	// Initialize current pointers for three
	// lists and whole list.
	Node *zero = zeroD, *one = oneD, *two = twoD;

	// Traverse list
	Node* curr = head;
	while (curr) {
		if (curr->data == 0) {
			zero->next = curr;
			zero = zero->next;
		}
		else if (curr->data == 1) {
			one->next = curr;
			one = one->next;
		}
		else {
			two->next = curr;
			two = two->next;
		}
		curr = curr->next;
	}

	// Attach three lists
	zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
	one->next = twoD->next;
	two->next = NULL;

	// Updated head
	head = zeroD->next;

	// Delete dummy nodes
	delete zeroD;
	delete oneD;
	delete twoD;

	return head;
}

// Function to create and return a node
Node* newNode(int data)
{
	// allocating space
	Node* newNode = new Node;

	// inserting the required data
	newNode->data = data;
	newNode->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Driver program to test above function*/
int main(void)
{
	// Creating the list 1->2->4->5
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(0);
	head->next->next->next = newNode(1);

	printf("Linked List Before Sorting\n");
	printList(head);

	head = sortList(head);

	printf("Linked List After Sorting\n");
	printList(head);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
