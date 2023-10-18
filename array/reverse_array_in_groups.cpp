#include <iostream>
#include <vector>

using namespace std;

vector<long> reverseArrayInGroups(vector<long> &arr, int n, int k)
{
    long repeat = n / k;
    int i = 0;
    int j = k;
    if(n < k) {
        j = k;
    }
    // while(k < n-1) {
    //     while(i < j-1) {
    //         long temp = arr[i];
    //         arr[i] = arr[j-1];
    //         arr[j-1] = temp;
    //         i++;
    //         j--;
    //     }
    //     i
    // }
    int start = 0;
    int end = k;
   for(int i=0; i<n; i += k) {
    int start = i;
    int end = min(i+k-1, n-1);
    while(start < end) {
        long temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
   }

    return arr;
}

int main()
{
    vector<long> v{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // vector<long> v{35, 56, 48, 21, 87, 1, 23, 43, 12, 8, 89, 24, 10, 20, 30, 40, 19, 18, 29, 30, 39, 49, 40};
    int size = v.size();
    vector<long> reverseArray;
    // cout << size;
    reverseArray = reverseArrayInGroups(v, size, 3);
    for (auto i : reverseArray)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}