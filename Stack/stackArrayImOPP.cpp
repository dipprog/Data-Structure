#include <iostream>
#define MAX_SIZE 101
using namespace std;

class Stack
{
private:
    int A[MAX_SIZE]; // For storing stack
    int top;         // variable to mark the top index of stack.
public:
    Stack()
    {
        top = -1; // setting intially -1 for empty stack;
    }
    void push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Error: stack overflow" << endl;
            return;
        }
        A[++top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Error: No element to pop" << endl;
            return;
        }
        top--;
    }
    int topp()
    {
        return A[top];
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }

    // Only for testing
    void print()
    {
        cout << "Stack is: ";
        for (int i = 0; i <= top; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack S;
    S.push(2);
    S.print();
    S.push(4);
    S.print();
    S.push(6);
    S.print();
    S.push(8);
    S.print();
    S.pop();
    S.print();
    int top = S.topp();
    cout << "Top is: " << top << endl;
    S.print();
    int empty = S.isEmpty();
    string result = (empty == 1) ? "Stack is empty" : "Stack is not empty";
    cout << result << endl;
    S.print();

    return 0;
}
