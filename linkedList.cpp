#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *insert(Node *head, int x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
        return head;
    }
    Node *insert(Node *head, int x, int pos)
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

int main()
{
    Node N;
    Node *head = NULL; // empty list
    head = N.insert(head, 2);
    head = N.insert(head, 4);
    head = N.insert(head, 5);
    head = N.insert(head, 3);
    head = N.insert(head, 1);
    head = N.insert(head, 10);
    N.print(head);
    cout << "How many numbers?" << endl;
    int size, input, pos;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number " << endl;
        cin >> input;
        cout << "Enter Position " << endl;
        cin >> pos;
        head = N.insert(head, input, pos);
        N.print(head);
    }

    return 0;
}