#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    double A[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    int distinct = n;
    for (int i = 0; i < n; i++)
    {
        bool counted = false;
        for (int j = 0; j < i; j++)
        {
            if (A[i] == A[j]) // checking if A[i] already appeared in previous elements
            {
                counted = true;
                break;
            }
        }
        if (counted)
            distinct--; // subtract only once you see that the element has occured previously in the positions < the position of current element being checked
    }

    cout << "Number of distinct elements: " << distinct << endl;
    return 0;
}
