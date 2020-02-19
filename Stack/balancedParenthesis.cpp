#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool arePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    if (opening == '[' && closing == ']')
        return true;
    if (opening == '{' && closing == '}')
        return true;
    return false;
}

bool areParenthesesBalanced(string expr)
{
    stack<char> S;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            S.push(expr[i]);
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            if (S.empty() || !arePair(S.top(), expr[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main()
{
    string expression;
    cout << "Enter an expression:  ";
    cin >> expression;
    if (areParenthesesBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
