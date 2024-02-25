#include<iostream>

using namespace std;

string spell[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

void numberSpell(int n) {
    if(n==0) {
        return;
    }
    int x = n%10;
    numberSpell(n/10);
    cout << spell[x] << " ";
}


int main() {
    int n;
    cin >> n;
    numberSpell(n);
    return 0;
}