#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr) {
    for(int &i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void permuation(vector<int> input, int l, int r) {
    if(l == r) {
        print(input);
        return;
    }
    for(int i=l; i<=r; i++) {
        swap(input[l], input[i]);
        permuation(input,l+1,r);
        swap(input[l], input[i]);
    }
    return;
}

int main() {
    vector<int> input = {1,2,3};
    string output = "";

    permuation(input,0,input.size()-1);
    return 0;
}