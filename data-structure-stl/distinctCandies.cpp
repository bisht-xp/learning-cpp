#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int distributeCandies(vector<int> &candies)
{
    unordered_set<int> unSet;
    int n = candies.size();
    for (int i = 0; i < n; i++)
    {
        unSet.insert(candies[i]);
    }
    if(n/2 < unSet.size()) {
        return n/2;
    }

    return unSet.size();
}

int main()
{
    vector<int> candiesType = {1, 1, 2, 2, 3, 4,4,4,4,4};
    cout << distributeCandies(candiesType) << endl;
    return 0;
}