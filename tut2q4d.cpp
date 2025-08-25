#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: " << endl;
    getline(cin, str);
    cout << "String in Alphabetic order: " << endl;
    sort(str.begin(), str.end());
    cout << str;
    return 0;
}