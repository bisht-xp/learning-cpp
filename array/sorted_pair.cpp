#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<math.h>

using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
    int min = INT_MAX;
    pair<int, int> pr;
    int l=0, h=arr.size()-1;
    while(l < h) {
        int sum = arr[l]+arr[h];
        int val = abs(x-sum);
        if(min > val) {
            min = val;
            pr = {arr[l], arr[h]};
        }
        if(sum > x) {
            h--;
        }
        else if(sum < x) {
            l++;
        }

    }
    return pr;
}

int main() {
    vector<int> v = {1, 3, 4, 7, 10 };
    pair<int, int> pr = closestSum(v,15);
    cout << pr.first << " "<< pr.second << endl;
    return 0;
}