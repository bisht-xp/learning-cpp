#include<iostream>

using namespace std;

bool isPalindrome(string str)
{
    int j = str.length()-1;
    int i=0;
    while(i<=j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    cout << isPalindrome("abcdecba");
    return 0;
}