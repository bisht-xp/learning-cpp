#include<iostream>

using namespace std;

void clearLastIthBits(int &n, int i) {
    int mask = -1<<(i+1);
    n = n&mask;
}



int main() {
    int n=15, i;
    cin >> i;
    clearLastIthBits(n, i);
    cout << n << endl;
    return 0;
}