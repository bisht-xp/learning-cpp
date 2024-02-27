#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int s, int mid, int e) {
    int i = s;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else  {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid) {
        temp.push_back(arr[i++]);
    }
    while(j<=e) {
        temp.push_back(arr[j++]);
    }
    arr.clear();
    for(int &i: temp) {
        arr.push_back(i);
    }
    temp.clear();
    return;
}

void mergeSort(vector<int> &arr, int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr,mid+1, e);
    merge(arr, s, mid, e);
}

int main() {
    vector<int> v = {9,6,1,3,4,8,2};
    int h = v.size()-1;
    mergeSort(v,0,h);
    for(auto i: v) {
        cout << i << " ";
    }
    return  0;
}