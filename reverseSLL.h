#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *insert(Node *head, int x) // insert element at the beginning
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
        return head;
    }
    Node *insert(Node *head, int x, int pos) // insert element at ith position
    {
        Node *temp1 = new Node();
        temp1->data = x;
        temp1->next = NULL;
        if (pos == 1)
        {
            temp1->next = head;
            head = temp1;
            return head;
        }
        Node *temp2 = head;
        for (int i = 0; i < pos - 2; i++) // pos-2 not pos-1 since initially pos = 1 (temp2 = head)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        return head;
    }
    Node *deletee(Node *head, int pos)
    { // Delete nth node
        Node *temp1 = head;
        if (pos == 1)
        {
            head = temp1->next;
            delete temp1;
            return head;
        }
        for (int i = 0; i < pos - 2; i++)
            temp1 = temp1->next;
        // After for loop, temp1 points to (n-1)th node
        Node *temp2 = temp1->next; // nth node
        temp1->next = temp2->next; // (n+1)th node
        delete temp2;
        return head;
    }
    void print(Node *head)
    {
        cout << "List is: " << endl;
        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
        cout << endl;
    }
};