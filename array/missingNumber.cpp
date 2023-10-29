#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int missingNumber(vector<int> &A, int N) {
    int n = N+1;
    int totalSumOfNplusOne = (n*(n+1))/2;
    int sum = 0;
    for(int i=0; i<N; i++) {
        sum += A[i];
    }

    return (totalSumOfNplusOne - sum);
}

int main() {
    vector<int> arr= {2, 5, 3, 1};
    cout << missingNumber(arr, arr.size());

    return 0;
}