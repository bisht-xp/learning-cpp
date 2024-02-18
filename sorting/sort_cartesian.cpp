#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {
    if(p1.first != p2.first) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    // your code goes here
    sort(v.begin(), v.end(), compare);
    
    return v;
}

int main() {
    vector<pair<int,int>> v1 = { {3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4} };
    vector<pair<int,int>> ans = sortCartesian(v1);

    cout <<"{";
    for(auto x: ans) {
        cout << "("<< x.first<<","<<x.second<<"), ";
    }
    cout <<"}"<< endl;
    return 0;
}
