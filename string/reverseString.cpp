#include<iostream>
#include<string>

using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

string reverseString(string &str) {
    if(str.length() < 2) {
        return str;
    }
    int low = 0;
    int high = str.length()-1;
    while(low < high) {
        swap(str[low], str[high]);
        low++;
        high--;
    }

    return str;
}

int main() {
    string str = "Hi, My Name is Kamal";
    cout << reverseString(str) << endl;
    return 0;
}