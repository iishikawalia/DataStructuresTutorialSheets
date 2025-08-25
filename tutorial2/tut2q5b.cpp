#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size(n) for the square matrix(nXn): ";
    cin >> n;
    int dmatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j) || (i + 1 == j) || (j + 1 == i))
            {
                cout << "Enter element at position (" << i << ", " << j << "): ";
                cin >> dmatrix[i][j];
            }
            else
            {
                dmatrix[i][j] = 0;
            }
        }
    }

    cout << "Tri-Diagonal matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dmatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}