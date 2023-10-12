/*
    Always divide the problem into smaller sub-problem.
    Think about the end cases.
    Always think about the correct data-Structure.
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool findTheSamePair(vector<int> &vec1, vector<int> &vec2) {
    unordered_map<int, int> unMap;
    
    for(int i=0; i<vec1.size(); i++) {
        if(!unMap[vec1[i]]) {
            unMap[vec1[i]] = 1;
        }       
    }

    for(auto pair : vec2) {
        if(unMap[pair]) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 6, 33, 81, 59, 69};
    vector<int> arr2 = {90, 12, 43, 39, 132, 9, 69};
    cout << findTheSamePair(arr1, arr2) << endl;

    return 0;
}