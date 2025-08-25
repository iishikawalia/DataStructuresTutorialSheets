#include <iostream>
using namespace std;

int main()
{
    char c;
    cout<<"Enter the character to be converted into lower case: "<<endl;
    cin>>c;
    char cl;
    cout << c << " in lowercase is represented as: ";
    cl = tolower(c);
    cout << cl;
}