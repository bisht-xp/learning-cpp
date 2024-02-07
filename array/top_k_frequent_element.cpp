// Leetcode : 347
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> map;

    for(auto &num: nums) {
        map[num]++;
    }

    for(auto &m: map) {
        pq.push(make_pair(m.second, m.first));
    }
    vector<int> ans;

    while(k--) {
        pair<int, int> top = pq.top();
        ans.push_back(top.second);
        pq.pop();
    }

    return ans;

}

int main() {
    vector<int> v = {1,1,1,2,2,3};
    vector<int> res = topKFrequent(v, 2);

    return 0;
}