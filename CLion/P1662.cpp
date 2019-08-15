//
// Created by HyunI on 2019-06-25.
//

#include <string>
#include <iostream>

using namespace std;

int unzip_rec(const string & str, int & index) {
    int length = 0;
    while(index < str.length()) {
        switch(str[index++]) {
            case '(':
                length += (str[index-2] - '0') * unzip_rec(str, index) - 1;
                break;
            case ')':
                return length;
            default:
                length++;
                break;
        }
    }
    return length;
}

int unzip(const string & str) {
    int index = 0;
    return unzip_rec(str, index);
}

int main() {
    string str;
    cin >> str;
    cout << unzip(str);
    return 0;
}