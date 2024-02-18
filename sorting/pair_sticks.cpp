#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pairSticks(vector<int> length, int D)
{
    // your code goes here
    sort(length.begin(), length.end());

    int i = 0, count = 0;
    int n = length.size();
    for(int i=0; i<n-1; i++) 
    {
        if (D >= (length[i + 1] - length[i]))
        {
            count++;
            i++;
        }
    }
    return count;
}

int main()
{
    vector<int> v = {1, 3, 3, 9, 4};
    cout << pairSticks(v, 2) << endl;
    return 0;
}