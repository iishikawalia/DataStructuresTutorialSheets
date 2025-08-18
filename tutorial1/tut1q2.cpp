#include <iostream>
using namespace std;

int array[] = {2, 3, 4, 5, 7, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 2, 4, 3, 5, 7, 8, 9, 8, 8};
int size = sizeof(array) / sizeof(array[0]);

void DeleteDuplicateElements()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                Delete(j);
                j--;
            }
        }
    }
};

void display()
{
    cout << "[";
    for (int l = 0; l < size; l++)
    {
        cout << array[l];
        if (l < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
};

int main()
{
    cout << "Original Array: " << endl;
    display();
    DeleteDuplicateElements();
    display();

}

