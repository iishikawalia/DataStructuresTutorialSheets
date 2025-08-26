#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int BubbleSort(int n, int A[100], int key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}

int main()
{
    int n, key;
    cout << "Enter array size: ";
    cin >> n;
    int A[100];

    cout << "Enter array elements (sorted):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    cout << "Sorted Array: " << endl;
    BubbleSort(n, A, key);
    for (int i = 0; i < n; ++i)
    {
        cout << A[i];
    }

    return 0;
}
