#include <bits/stdc++.h>
using namespace std;
//OPTION 1
void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}
//OPTION 2
void remove_space(string str) {
    cout << str<<endl;
    int len = str.length();
    int space_c = count(str.begin(), str.end(), ' ');
    remove(str.begin(), str.end(), ' ');
    str.resize((len-space_c));
    cout << str<<endl;
}

int main()
{
    string s = "g e e k s f o r";
    remove_space(s);
    return 0;
}
