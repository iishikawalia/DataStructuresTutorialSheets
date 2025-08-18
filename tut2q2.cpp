#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void displayArray(int arr[],int size){
    cout<<"[";
    for(int i=0; i<size; i++){
        cout<<" "<<arr[i];
    }
    cout<<"]";
}

int main() {
    int arr[] = {64,34,25,12,22,11,90};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: "<<endl;
    displayArray(arr,size);
    cout<<endl<<"Sorted Array: "<<endl;
    bubbleSort(arr, size);
    displayArray(arr,size);
    return 0;
}
