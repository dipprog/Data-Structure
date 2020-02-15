#include "reverseSLL.h"

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = reverse(head->next);
    // Node *q = head->next;
    // q->next = head;
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

int main()
{
    Node *head = NULL;
    Node N;
    head = N.insert(head, 2);
    head = N.insert(head, 4);
    head = N.insert(head, 6);
    head = N.insert(head, 8);
    head = N.insert(head, 10);
    cout << "Before reversal---" << endl;
    N.print(head);
    head = reverse(head);
    cout << "After reversal---" << endl;
    N.print(head);
}