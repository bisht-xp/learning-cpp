#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

int firstRecurring(vector<int> &arr) {
    //optimized solution using hashtable (unordered_map)
    unordered_map<int, int> firstRecurring;
    for(int i=0; i<arr.size(); i++) {
        if(firstRecurring[arr[i]]) 
            return arr[i];
        
        firstRecurring[arr[i]]++;
    }

    //Brute force solution
    for(int i=1; i<arr.size(); i++) {
        for(int j=i-1; j>=0; j-- ) {
            if(arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }

    return -1;
}


int main() {
    vector<int> arr = {2,1,2,4,5,6};
    cout << firstRecurring(arr) << endl;
    return 0;
}