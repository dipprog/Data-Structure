#include "reverseSLL.h"

Node *reverseSLL(Node *head)
{
    Node *current, *prev, *nextt;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        nextt = current->next;
        current->next = prev;
        prev = current;
        current = nextt;
    }
    head = prev;
    return head;
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
    head = reverseSLL(head);
    cout << "After reversal---" << endl;
    N.print(head);
}