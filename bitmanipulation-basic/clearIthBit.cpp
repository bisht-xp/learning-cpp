#include<iostream>
using namespace std;

int clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    return n&mask;
}



int main() {
    int n=13, i;
    cin >> i;
    cout << clearIthBit(n, i) << endl;
    return 0;
}