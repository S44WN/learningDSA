#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

} *first = NULL;

void Creat(int A[], int n)
{
    Node *temp, *last;

    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 0; i < n; i++)
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

int main()
{
}