#include<iostream>
using namespace std;

void clearRangeOfBits(int &n, int i, int j) {
	int a= -1<<(j+1);
	int b = (1<<i)-1;
	int mask = a+b;

	n = n&mask;
}

int main() {
	int n=31,i,j;
	cin >> i >> j;
	clearRangeOfBits(n,i,j);
	cout << n << endl;
	return 0;
}
