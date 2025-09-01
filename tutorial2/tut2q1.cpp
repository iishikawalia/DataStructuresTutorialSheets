#include <iostream>
using namespace std;

int BinarySearch(int n, int A[100], int key)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (A[mid] == key) // element found
            return mid;    // return index

        else if (A[mid] < key)
            l = mid + 1; // search right half
        else
            h = mid - 1; // search left half
    }
    return -1; // not found
}

int main()
{
    int n, key;
    cout << "Enter array size: ";
    cin >> n;
    int A[100]; // use int, since we’re searching int key

    cout << "Enter array elements (sorted):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int pos = BinarySearch(n, A, key);

    if (pos != -1)
        cout << "Element found at index: " << pos << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
