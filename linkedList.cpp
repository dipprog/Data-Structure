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
    cout << "How many numbers?" << endl;
    int size, input;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number" << endl;
        cin >> input;
        head = N.insert(head, input);
        N.print(head);
    }
    return 0;
}