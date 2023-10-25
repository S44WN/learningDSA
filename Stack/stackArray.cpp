#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *array;
};

// create
void create(Stack *st)
{
    cout << "Enter Size : ";
    cin >> st->size;
    st->top = -1;
    st->array = new int[st->size];
}

// display
void display(Stack *st)
{
    for (int i = st->top; i >= 0; i--)
    {
        cout << st->array[i] << " ";
    }
}

// isEmpty
int isEmpty(Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull
int isFull(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// peek at some pos
int peek(Stack *st, int pos)
{
    int x;
    if (st->top - pos + 1 < 0)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        x = st->array[st->top - pos + 1];
        return x;
    }
}

// push
void push(Stack *st, int x)
{
    if (st->top > st->size - 1)
    {
        cout << "Stack Overflow";
    }
    else
    {
        st->top++;
        st->array[st->top] = x;
    }
}

// pop
int pop(Stack *st)
{
    int x;
    if (st->top < -1)
    {
        cout << "Stack underflow";
    }
    else
    {
        x = st->array[st->top];
        st->top--;
        return x;
    }
}

int main()
{
    struct Stack st;

    create(&st);

    cout << isEmpty(&st) << endl;
    cout << isFull(&st) << endl;

    push(&st, 12);
    push(&st, 32);
    push(&st, 102);
    push(&st, 128);
    push(&st, 178);
    push(&st, 928);

    peek(&st, 4);

    cout << pop(&st) << endl;
    cout << pop(&st) << endl;

    cout << isEmpty(&st) << endl;
    cout << isFull(&st) << endl;
}