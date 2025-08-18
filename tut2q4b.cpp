#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    char revstr[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        revstr[len-i-1]=str[i];
    }
    cout << revstr<<endl;
    return 0;
}
