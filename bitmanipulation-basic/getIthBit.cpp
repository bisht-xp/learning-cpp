#include<iostream>
using namespace std;

void getIthBit(int n, int pos) {
	int afterShift = n >> pos;
	cout << (afterShift&1) << endl;
	return;
}

int main() {
	int n, pos;
	cin >> n >> pos;
	getIthBit(n, pos);
	return 0;
}
