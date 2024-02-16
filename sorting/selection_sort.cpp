#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int current = arr[i];
        int min_pos = i;
        for(int j=i+1; j<n; j++) {
            if(arr[min_pos] > arr[j]) {
                min_pos = j;
            }
        }
        arr[i] = arr[min_pos];
        arr[min_pos] = current;
    }

    return arr;
}

int main()
{
    vector<int> v = {3, 4, 2, 5, 1};
    vector<int> ans = selectionSort(v);
    for (int &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}