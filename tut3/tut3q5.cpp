#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (c == ' ')
        {
            continue;
        }


        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();


            switch (c)
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string exp = "6 3 2 + * 2 /";
    cout << "Expression: " << exp<<endl;
    cout << "Postfix evaluation: " << evaluatePostfix(exp) << endl;
    return 0;
}
