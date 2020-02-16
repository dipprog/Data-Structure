#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
} * top;
class Stack
{
public:
    void push(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->link = top;
        top = newNode;
    }
    void pop()
    {
        Node *temp = top;
        if (temp == NULL)
            return;
        top = top->link;
        delete temp;
    }
    int topElement()
    {
        return top->data;
    }
    void isEmpty()
    {
        if (top == NULL)
            cout << "Stack is empty" << endl;
        else
            cout << "Stack is not empty" << endl;
    }
    void Print()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "--";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    top = NULL;
    Stack S;
    S.push(2);
    S.Print();
    S.push(4);
    S.Print();
    S.push(6);
    S.Print();
    S.push(8);
    S.Print();
    S.push(10);
    S.Print();
    S.pop();
    S.Print();
    cout << "Top element is: " << S.topElement() << endl;
    S.pop();
    S.Print();
    S.isEmpty();
}