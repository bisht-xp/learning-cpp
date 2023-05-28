#include<iostream>

using namespace std;

int leftShift(int &a) {
    a = a << 2;
    return a;
}

int rightShift(int &a) {
    a = a>>2;
    return a;
}

int main() {
    int a = 5;
    cout << leftShift(a) << endl;
    cout << rightShift(a) << endl;
    return 0;
}