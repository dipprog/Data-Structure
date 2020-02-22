// Circular Array implementation of Queue..
#include <iostream>
#define N 101 // maximum size of the array that will store queue

using namespace std;

class Queue
{
private:
    int A[N];
    int front, rear;

public:
    // Constructor - set front and rear as -1.
    // We are assuming that for an empty Queue, both front and rear will be -1.
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // To check wheter Queue is empty or not
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // To check whether Queue is full or not
    bool isFull()
    {
        return ((rear + 1) % N == front);
    }

    // Inserts an element in queue at rear end
    void enqueue(int x)
    {
        cout << "Enqueuing " << x << endl;
        if (isFull())
        {
            cout << "Error: Queue is full\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % N;
        A[rear] = x;
    }

    // Removes an element in Queue from front end.
    void dequeue()
    {
        cout << "Dequeuing " << endl;
        if (isEmpty())
        {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % N;
    }

    // Returns element at front of queue.
    int frontt()
    {
        if (front == -1)
        {
            cout << "Error: cannot return front from empty queue\n";
            return -1;
        }
        return A[front];
    }

    /* 
	   Printing the elements in queue from front to rear. 
	   This function is only to test the code. 
	   This is not a standard function for Queue implementation. 
	*/
    void print()
    {
        // Finding number of elements in queue
        int count = (rear + N - front) % N + 1;
        cout << "Queue:   ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % N; // Index of element while travesing circularly from front
            cout << A[index] << " ";
        }
        cout << "\n\n";
    }
};

/*  
    Driver Code to test the implementation
    Printing the elements in Queue after each Enqueue or Dequeue 
*/
int main()
{
    Queue Q; // creating an instance of Queue.
    Q.enqueue(2);
    Q.print();
    Q.enqueue(4);
    Q.print();
    Q.enqueue(6);
    Q.print();
    Q.enqueue(8);
    Q.print();
    Q.enqueue(10);
    Q.print();
    Q.dequeue();
    Q.dequeue();
    int front = Q.frontt();
    cout << "Top: " << front << endl;
}