#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: "<<endl;
    getline(cin, s);
    cout<<"String in Alphabetic order: "<<endl;
    sort(s.begin(),s.end());
    cout<<s;
    return 0;
}