// Reverse Linked List using explicit stack.
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * head;

class LinkedList
{
public:
    void insert(int x) // insert element at the beginning
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node *temp = head;
        cout << "List:  ";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseList()
    {
        Node *temp = head;
        stack<Node *> S;
        if (temp == NULL)
            return;
        while (temp != NULL)
        {
            S.push(temp);
            temp = temp->next;
        }
        temp = S.top();
        head = temp;
        S.pop();
        while (!S.empty())
        {
            temp->next = S.top();
            S.pop();
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

int main()
{
    head = NULL; // empty list
    LinkedList L;
    L.insert(2);
    L.insert(4);
    L.insert(6);
    L.insert(8);
    L.insert(10);
    L.print();
    L.reverseList();
    L.print();

    return 0;
}