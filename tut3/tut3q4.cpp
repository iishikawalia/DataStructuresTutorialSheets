#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.length();
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && ((s[i] != '^' && priority(s[i]) <= priority(st.top())) || (s[i] == '^' && priority(s[i]) < priority(st.top()))))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    // pop all the remaining elements from stack st
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}