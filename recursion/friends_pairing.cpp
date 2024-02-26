#include<iostream>

using namespace std;

int friendsPairing(int n){
    if(n<=1) {
        return 1;
    }    
    int x = friendsPairing(n-1);
    int y = (n-1)*friendsPairing(n-2);
    return  x+y ;
}

int main() {
    cout << "friends pairing ways: "<< friendsPairing(3) << endl;
    return 0;
}
