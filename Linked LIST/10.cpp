/* solution

class Solution
{
    public:
    //Function to reverse the linked list.
    Node* reverse(Node *head) 
    {
        Node * prev = NULL;
        Node * current = head;
        Node * next;
        
        while (current != NULL) 
        { 
            next = current->next;     
            current->next = prev;     
            prev = current;          
            current = next;
        }
        
        return prev; 
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reversing both lists to simplify addition.
        first = reverse(first);             
        second = reverse(second);            
        
        Node *sum=NULL;
        int carry=0;
        
        //using a loop till both lists and carry gets exhausted.
        while( first!=NULL || second!=NULL || carry!=0 )
        {
            //using a variable to store sum of two digits along with carry.
            int newVal = carry;
            
            //if nodes are left in any list, we add their data in newVal.
            if(first) newVal += first->data;
            if(second) newVal += second->data;
        
            //updating carry.
            carry = newVal/10;
            
            //using modulus to store only a single digit at that place.
            newVal = newVal%10;             
            
            //creating new node which gets connected with other nodes that 
            //we get after calculating sum of respective digits.
            Node* newNode = new Node(newVal);
            
            //storing the previously made nodes in the link part of new node.
            newNode->next = sum;
            
            //making the new node as the first node of all previously made node.
            sum = newNode;
            
            //moving ahead in both lists.
            if(first) first = first->next; 
            if(second) second = second->next;
        }
        return sum;
    }
};
*/

// C++ Code to add two nodes by reversing the two lists

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};

Node* newNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = newNode(new_data);
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(Node* n)
{
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node* reverseList(struct Node* list)
{
    Node *prev = NULL, *cur = list, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//----------------------------------------------------------------------------

Node* addTwoLists(Node* first, Node* second)
{
    // code here
    first = reverseList(first);
    second = reverseList(second);

    int carry = 0;
    Node *head = NULL, *prev = NULL;
    Node* sum = NULL;
    // if any one of these is left we are stil left with addition
    while (first != NULL or second != NULL or carry == 1)
    {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;
        // to be used in the next node calculation
        carry = newVal / 10;
        newVal = newVal % 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newVal;
        // appending in the beginning of the final ans list,
        // this way we do not have to reverse in the end
        newNode->next = sum;
        sum = newNode;
        // initialising nodes for next iteration

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    return sum;
}

//----------------------------------------------------------------------------

// { Driver Code Starts.

int main()
{
    Node* first = NULL;
    Node* second = NULL;

    push(&first, 9);
    push(&first, 8);
    push(&first, 7);

    push(&second, 1);
    push(&second, 2);
    push(&second, 3);

    Node* ans = addTwoLists(first, second);

    cout << "Sum is : ";
    printList(ans);

    return 0;
}
