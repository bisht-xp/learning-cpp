#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int s, int e) {
    int pivot = arr[e];
    int i=s-1;
    for(int j=s; j<e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quickSort(vector<int> &arr, int s, int e) {
    if(s>=e) {
        return;
    }

    int j = partition(arr,s,e);
    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);
}
//trying to solve these question
// void quickSort(vector<int> &arr, int s, int e) {
//     if(s>=e) {
//         return;
//     }

//     // int l = arr[e];
//     int j = s-1;
//     // int i = s-1;
//     for(int i=s; i<e; i++) {
//         if(arr[i] < arr[e]) {
//             j++;
//             swap(arr[i], arr[j]);
        
//         }
//     }
//     swap(arr[j])
//     quickSort(arr,s,j-1);
//     quickSort(arr,j+1,e);
// }

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8};
    // vector<int> v = {9,6,1,3,4,8,2};
    int h = v.size()-1;
    quickSort(v, 0, h);
    for(auto i: v) {
        cout << i << " ";
    }
    return  0;
}