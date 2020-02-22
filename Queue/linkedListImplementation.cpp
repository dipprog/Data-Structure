/*Queue - Linked List implementation*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Two glboal variables to store address of front and rear nodes.
Node *front = NULL;
Node *rear = NULL;

class Queue
{
public:
    // To Enqueue an integer
    void Enqueue(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    // To Dequeue an integer.
    void Dequeue()
    {
        Node *temp = front;
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear)
            front = rear = NULL;
        else
            front = front->next;

        delete temp;
    }
    // Returning front element of the Queue
    int Front()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    // Printing element of the Queue
    void Print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

/* Drive code to test the implementation. */
// Printing elements in Queue after each Enqueue or Dequeue
int main()
{
    Queue Q;
    Q.Enqueue(2);
    Q.Print();
    Q.Enqueue(8);
    Q.Print();
    Q.Enqueue(6);
    Q.Print();
    Q.Enqueue(4);
    Q.Print();
    Q.Enqueue(10);
    Q.Print();
    Q.Dequeue();
    Q.Print();
    int fron = Q.Front();
    cout << "Front of the Queue: " << fron << endl;
}
