#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> kClosestElement(vector<int> arr, int k, int x)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = abs(arr[i] - x);
        pq.push({diff, arr[i]});
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    for (int x : kClosestElement(arr, k, x))
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}