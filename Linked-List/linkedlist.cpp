#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // pointer to next node
} *first = NULL;       //*first = NULL  // global pointer to first node of linked list. why? because we need to access the first node from anywhere in the program

/*
class Node
{
public: // access specifier
    int data;
    Node *next;
} *first = NULL;
*/

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

void RDisplay(struct Node *n)
{
    if (n != NULL)
    {
        cout << n->data << " ";
        RDisplay(n->next);
        /*
        //prints llist in reverse
        RDisplay(n->next)
        cout << n->data << " ";
        */
    }
}

// counting nodes
int Count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int RCount(struct Node *p)
{
    if (p != NULL)
        return RCount(p->next) + 1;
    else
        return 0;

    /*

    //recursively but with variable
    int x = 0;
        if(p){
        x = RCount(p->next);
        return x+1;
    }
    else{
        return 0;
    }
    */
}

// adding nodes
int Sum(struct Node *p)
{
    int s = 0;

    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RSum(p->next) + p->data;
}

int Max(struct Node *n)
{
    int max = INT32_MIN; // base don 2 byte int;  MIN_INT;

    while (n != 0)
    {
        if (n->data > max)
            max = n->data;
        else
            return 0;
    }

    return max;
}

int RMax(struct Node *n)
{
    int x = 0;
    /*
    if (n == 0)
    {
        return INT32_MIN;
    }
    else
    {
        x = RMax(n->next);
        if (x > n->data)
            return x;
        else
            return n->data;
    }
    */
    if (n == 0)
        return INT32_MIN;
    x = RMax(n->next);
    return (x > n->data) ? x : n->data;
}

Node *Search(struct Node *n, int key)
{
    while (n != 0)
    {
        if (key == n->data)
            return n;
        n = n->next;
    }
    return 0;
}

Node *RSearch(struct Node *n, int key)
{
    if (n == 0)
        return 0;
    if (key == n->data)
        return n;
    return RSearch(n->next, key);
}

Node *ImprSearch(struct Node *n, int key)
{
    Node *m = NULL;
    while (n != NULL)
    {
        if (key == n->data)
        {
            m->next = n->next; // node before "key containg node" points to the next node to key node;
            n->next = first;   // key node's next node is first node. so key node becomes first node.
            first = n;         // first has to point to first.. right?
            return n;
        }
        m = n;
        n = n->next;
    }
}

void Insert(struct Node *n, int pos, int insrtData)
{
    // inserting at first
    if (pos < 0 || pos > Count(n))
        return;

    // new node adding data
    struct Node *t;
    t = new Node;
    t->data = insrtData;

    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            n = n->next;
        }
        t->next = n->next;
        n->next = t;
    }
}

void InsertLast(struct Node *n, int insrtData)
{
    Node *t = new Node, *last;
    t->data = insrtData;
    t->next = NULL;

    if (first == NULL)
    {
        first = last;
        last = t;
    }
    else
    {
        while (n->next != NULL)
        {
            last = n->next;
        }
        last->next = t;
        last = t;
    }
}

void InsertInSorted(struct Node *n, int insertData)
{
    struct Node *temp, *trailingP = NULL;
    temp = new Node;
    temp->data = insertData;
    temp->next = NULL;

    while (n && n->data < insertData)
    {
        trailingP = n;
        n = n->next;
    }
    if (n == first)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        temp->next = trailingP->next;
        trailingP->next = temp;
    }
}

// void Delete(struct Node *n, int pos)
// {
//     Node *tailP = NULL, *leadp;

//     if (pos == 1)
//     {
//         leadp = first;
//         first = first->next;
//         delete leadp;
//     }
//     else
//     {
//         leadp = first;

//         for (int i = 0; i < pos - 1; i++)
//         {
//             tailP = leadp;
//             leadp = n->next;
//         }
//         tailP->next = leadp->next;
//         // int x = leadp->data; //store deleted data in a variable if needed
//         delete leadp;
//     }
// }

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > Count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q); // delete q; is also fine
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

void RemoveDuplicates(struct Node *n)
{
    n = first;
    Node *q = first->next;

    if (n == NULL)
        return;
    else
    {
        while (q != NULL)
        {
            if (n->data != q->data)
            {
                n = q;
                q = q->next;
            }
            else
            {
                n->next = q->next;
                delete q;
                q = n->next;
            }
        }
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