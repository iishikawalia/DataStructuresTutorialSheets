#include <iostream>
using namespace std;


int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i+1)
            return i+1;
    }
    return n;
}


int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;  // Range is 1 to n
    cout << "Missing Number (using Linear time): " << findMissingLinear(arr, n);
    return 0;
}

