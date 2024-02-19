#include<iostream>
#include <string>
#include<cmath>

using namespace std;

int binaryToDecimal(string s)
{
    // your code goes here
    int ans=0;
    int p=0;
    for(int i=s.size()-1; i>=0; i--) {
        int val = s[i]-'0';
        ans += (val*pow(2,p));
        p++;
    }
    return ans;
}

int main() {
    cout << binaryToDecimal("111") << endl;
    return 0;
}