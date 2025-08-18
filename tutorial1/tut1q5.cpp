#include <iostream>
using namespace std;
int matrix[4][6] = {{1, 1, 1, 1, 1, 1}, {3, 7, 0, 1, 20, 7}, {0, 0, 0, 0, 0, 0}, {9, 9, 9, 9, 9, 9}};
int rowsum = 0, colsum = 0;

void Display()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "[";
        for (int j = 0; j < 6; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void csum()
{
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            colsum += matrix[i][j];
        }
        cout << "Sum of column " << (j + 1) << " is: " << colsum << endl;
        colsum = 0;
    }
}

void rsum()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rowsum += matrix[i][j];
        }
        cout << "Sum of row " << (i + 1) << " is: " << rowsum << endl;
        rowsum = 0;
    }
}

int main()
{
    cout << "Matrix:" << endl;
    Display();
    cout << "Sum of rows:" << endl;
    rsum();
    cout << "Sum of columns:" << endl;
    csum();
    return 0;
}