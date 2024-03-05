#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    if (s >= e)
    {
        return -1;
    }

    int mid = (s+e) / 2;

    if (arr[mid] == key)
    {
        return mid + 1;
    }
    else if (arr[mid] > key)
    {
        return binarySearch(arr, s, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    return -1;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,9};
    int n = v.size();
    cout << binarySearch(v,0,n-1,7) << endl;
    return 0;
}