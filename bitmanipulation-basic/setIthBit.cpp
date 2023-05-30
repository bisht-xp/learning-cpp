#include<iostream>

using namespace std;

void setIthBit(int &n, int i) {
    int mask = (1<<i);
    cout << (n|mask) << endl;
}


int main() {
    int n=5, i;
    cin >> i;
    setIthBit(n, i);
    return 0;
}