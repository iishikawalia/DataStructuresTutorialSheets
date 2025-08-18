#include <iostream>
using namespace std;
int size = 0, elm, pos;
int array[100000];
void menu();
void Create()
{
    cout << "Enter the number of elements: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of index " << i << ": " << endl;
        cin >> array[i];
    }
    menu();
};
void Display()
{
    if (size == 0)
    {
        cout << "Empty array!" << endl;
    }
    else
    {
        cout << "{";
        for (int i = 0; i < size; i++)
        {
            cout << array[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
    menu();
};
void Insert()
{
    cout << "Enter the index at which the element has to be inserted: ";
    cin >> pos;
    if (pos < 0 || pos > size)
    {
        cout << "Invalid position!"<<endl;
        menu();
        return;
    }
    cout << "Enter the element: ";
    cin >> elm;
    for (int i = size - 1; i > pos; i--)
    {
        array[i + 1] = array[i];
    }
    array[pos] = elm;
    size++;
    menu();
};
void Delete()
{
    cout << "Enter the index at which the element has to be deleted: ";
    cin >> pos;
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!"<<endl;
        menu();
        //return;
    }
    for (int i = pos; i < size - 1; i++)
    {
        array[i] = array[i+1];
    }
    size--;
    menu();
};
void LinearSearch()
{
    cout << "Enter the element to be searched: ";
    cin >> elm;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == elm)
        {
            cout << "Element found at index " << i << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Element not found!" << endl;
    }
    menu();
};
void Exit()
{
    cout << "Exiting...";
};
void menu()
{

    int operations;
    cout << "MENU:" << endl
         << "1. CREATE" << endl
         << "2. DISPLAY" << endl
         << "3. INSERT" << endl
         << "4. DELETE" << endl
         << "5. LINEAR SEARCH" << endl
         << "6. EXIT" << endl;
    cin >> operations;
    switch (operations)
    {
    case 1:
        Create();
        break;
    case 2:
        Display();
        break;
    case 3:
        Insert();
        break;
    case 4:
        Delete();
        break;
    case 5:
        LinearSearch();
        break;
    case 6:
        Exit();
        break;
    default:
        cout << "Invalid choice!" << endl;
        menu();
    }
};
int main()
{
    menu();
    return 0;
}
