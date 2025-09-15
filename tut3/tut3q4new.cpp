#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

// function to check if operator is left associative
bool isLeftAssociative(char op)
{
    if (op == '^')
        return false; // ^ is right-associative
    return true;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (char c : infix)
    {
        // if operand, add to postfix
        if (isalnum(c))
        {
            postfix += c;
        }
        // if opening bracket, push to stack
        else if (c == '(')
        {
            st.push(c);
        }
        // if closing bracket, pop until '('
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // remove '('
        }
        // if operator
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                if (precedence(st.top()) > precedence(c) ||
                    (precedence(st.top()) == precedence(c) && isLeftAssociative(c)))
                {
                    postfix += st.top();
                    st.pop();
                }
                else
                    break;
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
