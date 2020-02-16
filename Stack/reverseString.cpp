#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void reverse(char *C, int length)
{
    stack<char> S;
    for (int i = 0; i < length; i++)
        S.push(C[i]);
    for (int i = 0; i < length; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}
int main()
{
    char String[51];
    cout << "Enter a string: " << endl;
    cin >> String;
    reverse(String, strlen(String));
    cout << String << endl;
    return 0;
}