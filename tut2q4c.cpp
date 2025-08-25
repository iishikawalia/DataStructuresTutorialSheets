#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    char str[100], strWithoutVowels[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    int j = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!isVowel(str[i]))
        {
            strWithoutVowels[j] = str[i];
            j++;
        }
    }
    strWithoutVowels[j] = '\0';
    cout <<endl<<"String without vowels: " << strWithoutVowels << endl;
    return 0;
}
