#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stack[top--] << "\n";
}

void isEmpty()
{
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Stack is not Empty\n";
}

void isFull()
{
    if (top == MAX - 1)
        cout << "Stack is Full\n";
    else
        cout << "Stack is not Full\n";
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << "\n";
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top Element: " << stack[top] << "\n";
}

int main()
{
    int ch, val;
    while (true)
    {
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid Choice\n";
        }
    }
}
