#include "reverseSLL.h"

void printList(Node *p)
{
    if (p == NULL)
        return;
    cout << p->data << "  ";
    printList(p->next);
}

void reversePrintList(Node *p)
{
    if (p == NULL)
        return;
    reversePrintList(p->next);
    cout << p->data << "  ";
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
    N.print(head);
    printList(head);
    cout << endl;
    reversePrintList(head);
    return 0;
}