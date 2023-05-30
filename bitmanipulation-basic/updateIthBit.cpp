#include<iostream>

using namespace std;

void clearIthBit(int &n, int i) {
	int mask = ~(1<<i);
	n = (n&mask);
}

void updateIthBit(int &n, int i, int val) {
	clearIthBit(n,i);
	int mask = (val<<i);
	n = n|mask;
}

int main() {
	int n=11,i;
	cin >> i;
	updateIthBit(n, i, 1);
	cout << n << endl;
	return 0;
}
