#include<iostream>

using namespace std;

int power(int a, int n) {
    if(n==1) {
        return a;
    }
    int ans = a * power(a,n-1);
    return ans;
}

int fastPower(int a, int n) {
    if(n==0) {
        return 1;
    }
    int sq = fastPower(a,n/2);
    int sqPower = sq*sq;
    if(n&1) {
        return a*sqPower;
    }
    return sqPower;
}

int main() {
    cout<< fastPower(2,4) << endl;
    return 0;
}

