#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

} *first = NULL;

void Create(int A[], int n)
{
    Node *temp, *last;

    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
}

int Length(Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int index, int val)
{
    Node *temp;

    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        temp = new Node;
        temp->data = val;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        temp = new Node;
        temp->prev = p;
        temp->next = p->next; // is set to NULL even if doesnt exist
        if (p->next)
            p->next->prev = temp;
        p->next = temp;
    }
}

int Delete(Node *p, int pos)
{
    int delVal = 0;

    if (pos < 0 || pos > Length(p))
        return -1;

    if (pos == 0)
    {
        first = first->next;
        delVal = p->data;
        delete p;
        if (first)
            first->prev = NULL;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        delVal = p->data;
        delete p;
    }
}
int main()
{
    int A[] = {11, 32, 43, 54, 75, 76, 78, 89};
    Create(A, 8);

    // Insert(first, 3, 47);

    Display(first);
}