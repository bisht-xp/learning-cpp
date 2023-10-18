#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool checkArrayEqual(vector<int> &a, vector<int> &b, int n) {
    unordered_map<int, int> map;
    for(auto i: a) {
        map[i]++;
    }

    for(auto i: map) {
        cout << i.first << " " << i.second << endl;
    }

    for(auto i: b) {
        if(!map[i]) {
            return false;
        }
        map[i] -= 1;
    }

    return true;
}

int main() {
    vector<int> a{1,2,8, 9,9};
    vector<int> b{1,2,9,9,8};

    if(checkArrayEqual(a, b, a.size())) {
        cout << "Yes: all the pairs are equal" << endl;
    } else {
        cout << "NO, sry man";
    }

    return 0;
}