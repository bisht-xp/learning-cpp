#include<iostream>

using namespace std;

double fastPower(double a, int n) {
    if(n==0) {
        return 1;
    }
    double sqrProb = fastPower(a,n/2);
        double sqrProbsq = sqrProb*sqrProb;

    if(n&1) {
        return  a*sqrProbsq;
    }
    return sqrProbsq;
}

double pow(double x, int n) {
    return n>0? fastPower(x,n): 1/fastPower(x,n);
}

int main() {
    double ans = fastPower(2.000, -2);
    cout << ans << endl;
    return 0;
}