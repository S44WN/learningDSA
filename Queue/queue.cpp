#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    };
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    };
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};

// Queue::Queue(int size)
// {
//     this->size = size;
//     front = rear = -1;
//     Q = new int[this->size];
// }

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
};

bool Queue::isFull()
{
    if (rear == size - 1)
        return true;
    else
        return false;
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue Overflow" << endl;
    else
        Q[++rear] = x;
};

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue underflow(empty)" << endl;
    else
        x = Q[++front];

    return x;
};

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << "<-" << flush;
        }
    }
    cout << endl;
};

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    Queue q(sizeof(A) / sizeof(A[0]));

    // Enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
    }

    // Display
    q.display();

    // Overflow
    q.enqueue(10);
    q.display();
    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.dequeue();
    }
    q.display();
    // Underflow
    q.dequeue();

    return 0;
}