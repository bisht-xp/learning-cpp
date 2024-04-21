#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;



vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int start = 0, end = -1, currentSum = 0;
    int n = a.size();
    vector<vector<int>> ans;
    while(start < n) {
        while(end+1 < n && currentSum + a[end+1] <= k) {
            currentSum += a[end+1];
            end++;
            if(currentSum == k) {
                vector<int> temp;
                for(int i=start; i<=end; i++) {
                    temp.push_back(a[i]);
                }
                ans.push_back(temp);
            }
        }
        currentSum -= a[start];
        start++;
    }

    return ans;
   
}

int main() {
    vector<int> vec = {9,5,6,5,5};
    int vecSize = 6;
    int k = 16;

    vector<vector<int>> subArray  = subarraysWithSumK(vec, k);

    for(vector<int> v: subArray) {
        for(int i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}