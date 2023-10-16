#include <iostream>
using namespace std;

/*
struct Node
{
    int data;
    struct Node *next; // pointer to next node
};                     //*first = NULL  // global pointer to first node of linked list. why? because we need to access the first node from anywhere in the program
*/

class Node
{
public: // access specifier
    int data;
    Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    Node *temp, *last;

    // first node
    first = new Node;
    first->data = A[0];
    first->next = nullptr; // last node
    last = first;          // why? 👇
    /*
    first->next = nullptr;
    sets the next field of the first node to nullptr
    to indicate that it is the last node in the linked list.

    last = first;
    assigns the address of the first node to the pointer last.
    This is because the last pointer is used to keep track of
    the last node in the linked list. Initially, the first node
    is the only node in the linked list, so it is also the last node.
    */

    // rest of the nodes
    for (i = 1; i < n; i++)
    {
        temp = new Node;      // create a temproary node
        temp->data = A[i];    // poulate the temporary node with data
        temp->next = nullptr; // set the next field of the temporary node to nullptr
        last->next = temp;    // set the next field of the last node to the address of the temporary node
        last = temp;          // set the last pointer to the temporary node
    }
}

void Display(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    /*
    // creating one node
    struct Node *p; // pointer to node
    p = new Node;
    p->data = 10;
    p->next = NULL;
    */

    /*
        // creating multiple nodes
        struct Node *first, *second, *third;
        first = new Node;
        second = new Node;
        third = new Node;

        first->data = 10;
        first->next = second;
        second->data = 20;
        second->next = third;
        third->data = 30;
        third->next = NULL; // last node
    */

    int A[] = {3, 5, 7, 10, 15};
    Create(A, 5);
    Display(first);

    return 0;
}