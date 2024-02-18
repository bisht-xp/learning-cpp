#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
using ll = long long;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<ll>x, y;
    ll maxX= INT_MIN, maxY = INT_MIN;
    
    for(auto &pos: position) {
        x.push_back(pos.first);
        y.push_back(pos.second);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i=1; i<x.size(); i++) maxX = max(maxX, (x[i] - x[i-1]-1));
    for(int i=1; i<x.size(); i++) maxY = max(maxX, (y[i] - y[i-1]-1));

    maxX = max(maxX, (W-x[x.size()-1]));
    maxY = max(maxY, (H-y[y.size()-1]));

    return maxX*maxY;
}

int main() {
    
    return 0;
}