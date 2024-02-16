#include <vector>
#include <iostream>

using namespace std;

vector<int> insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n -1; i++)
    {
        // int temp = arr[i];
        for (int j = i + 1; j >= 0; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                break;
            }
            int temp = arr[j-1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            // temp = arr[j - 1 - 1];
        }
    }
    return arr;
}

vector<int> insertionSortAlgo(vector<int> arr) {
    int n = arr.size();
    for(int i=1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    return arr;
}

int main()
{
    vector<int> v = {3, 4, 2, 5, 1};
    vector<int> ans = insertionSortAlgo(v);
    for (int &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}