// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
bool isValidPart(string str)
{
    cout << str<< endl;
    int len = str.length();
    if (len ==0 || len>3){
        cout << "length issue" <<endl;
        return false;
    }
    for(char c:str){
        if (c < '0' || c > '9'){
            cout << "not a digit issue" <<endl;
            return false;
        }
    }
    if (str[0] == '0' && len > 1){
        cout << "str[]0 is 0"<<endl;
        return false;
    }
    int num = 0;
    for (char c:str){
        num = num * 10 + (c - '0');
    }
    return num >=0 && num <= 255;
}
int isValid(string str)
{
    string substr;
    stringstream ss(str);
    int segmentCount = 0;
    while(getline(ss, substr, '.'))
    {
        cout << substr <<endl;
        if (!isValidPart(substr))
            return 0;
        segmentCount++;
    }
    if(segmentCount != 4)
        return 0;
    return 1;
}

int main() {
    // Write C++ code here
    string str1 = "12.12.12.256";
    int ret = isValid(str1);
    if (ret == 1)
        cout << "valid IP"<<endl;
    else
        cout << "Not a valid IP"<<endl;

    return 0;
}
