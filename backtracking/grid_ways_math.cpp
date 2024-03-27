#include<iostream>

using namespace std;

//solving grid ways problem using mathematical ways (permuation and combination).
int factorial(int n) {
    if(n==1) {
        return 1;
    }
    return n*factorial(n-1);
}

int main() {
    int n,m;
    cin >> m>> n;
    int ans = ((factorial(m+n-2)) /(factorial(m-1)*factorial(n-1)));
    cout << ans << endl;
    return 0;
}