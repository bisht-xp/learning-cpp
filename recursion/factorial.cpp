#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    int result = 0;
    result = n*factorial(n-1);
    return result;
}


int main() {
    cout << factorial(5) << endl;
    return 0;
}