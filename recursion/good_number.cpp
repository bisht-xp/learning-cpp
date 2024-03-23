#include<iostream>
#include<vector>

using namespace std;

bool isGoodNumber(int n, int digit) {
    if(n%10 == digit) {
        return false;
    }
    int sum = n%10;
    n = n/10;
    while(n != 0) {
        if(n%10 == digit || n%10 <= sum) {
            return false;
        }
        sum += n%10;
        n /=10;
    }

    return true;
}

vector<int> helper(int a, int b, int digit, vector<int>& ans) {
    if(a>b) {
        return ans;
    }
    if(isGoodNumber(a, digit)) {
        ans.push_back(a);
    }

    return helper(a+1, b, digit, ans);
     
}

vector<int> goodNumbers(int a, int b, int digit) {
	// Write your code here.
    vector<int> ans = {};
    return helper(a,b,digit,ans);
}

int main() {
    int a = 20, b=45;
    int digit = 1;

    vector<int> ans = goodNumbers(a,b,digit);

    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}