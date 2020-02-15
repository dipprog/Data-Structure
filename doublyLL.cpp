#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
} * head;

class doubleLL
{
public:
    Node *getNewNode(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
    void insertAtHead(int x)
    {
        Node *newNode = getNewNode(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(int x)
    {
        Node *newNode = getNewNode(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void print()
    {
        Node *temp = head;
        if (temp == NULL) // Empty List, Exit
            return;
        cout << "Forword: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    void reversePrint()
    {
        Node *temp = head;
        if (temp == NULL) // Empty List, Exit
            return;
        // Going to last node
        while (temp->next != NULL)
            temp = temp->next;
        // Traversing backword using prev pointer
        cout << "Reverse: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << "<-";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    head = NULL; // initially empty list..
    doubleLL dll;
    dll.insertAtHead(2);
    dll.print();
    dll.reversePrint();

    dll.insertAtHead(4);
    dll.print();
    dll.reversePrint();

    dll.insertAtHead(6);
    dll.print();
    dll.reversePrint();

    dll.insertAtHead(8);
    dll.print();
    dll.reversePrint();

    dll.insertAtHead(10);
    dll.print();
    dll.reversePrint();

    dll.insertAtTail(12);
    dll.print();
    dll.reversePrint();

    dll.insertAtTail(14);
    dll.print();
    dll.reversePrint();

    dll.insertAtTail(16);
    dll.print();
    dll.reversePrint();

    dll.insertAtTail(18);
    dll.print();
    dll.reversePrint();

    return 0;
}