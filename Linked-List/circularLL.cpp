#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *Head;

void CreateCircularLL(int A[], int n)
{
    int i;
    Node *temp, *last;

    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

// length of CLL

int Length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != Head);
    return len;
}

void Display(Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
}

void RecDisply(Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RecDisply(p->next);
    }
    flag = 0;
}

void Insert(Node *p, int index, int val)
{
    Node *temp;
    int i;

    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        temp = new Node;
        temp->data = val;
        if (Head == NULL)
        {
            Head = temp;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = Head;
            Head = temp;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        temp = new Node;
        temp->data = val;
        temp->next = p->next;
        p->next = temp;
    }
}

int Delete(Node *p, int index)
{
    Node *q;
    int i, x;

    if (index < 0 || index > Length(Head))
    {
        return -1;
    }

    if (index == 0)
    {
        while (p->next != Head)
        {
            p = p->next;
        }
        if (Head == p)
        {
            x = Head->data;
            delete Head;
            Head == NULL;
        }
        else
        {
            p->next = Head->next;
            x = Head->data;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[] = {11, 24, 36, 48, 53, 56, 67, 78, 89};

    CreateCircularLL(A, 9);

    // Insert(Head, 3, 39);
    Delete(Head, 3);
    Display(Head);
    // RecDisply(Head);

    return 0;
}