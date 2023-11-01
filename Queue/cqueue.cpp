#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    };
    CircularQueue(int size);
    ~CircularQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    front = rear = 0;
    Q = new int[this->size];
}

CircularQueue::~CircularQueue()
{
    delete[] Q;
}

bool CircularQueue::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
};

bool CircularQueue::isFull()
{
    if ((rear + 1) % size == front)
        return true;
    else
        return false;
};

void CircularQueue::enqueue(int x)
{
    if ((rear + 1) % size == front)
        cout << "Queue Overflow" << endl;
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
};

int CircularQueue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue underflow(empty)" << endl;
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }

    return x;
};

void CircularQueue::display()
{
    int i = front + 1;
    do
    {
        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << "<-" << flush;
        }
        i = (i + 1) % size;
    } while (1 != (rear + 1) % size);

    cout << endl;
};

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    CircularQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // Enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cq.enqueue(A[i]);
    }

    // Display
    cq.display();
    cout << endl;

    // Overflow
    cq.enqueue(10);

    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cq.dequeue();
    }

    // Underflow
    cq.dequeue();

    return 0;
}