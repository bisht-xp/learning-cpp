#include<iostream>
#include<queue>

using namespace std;

class Compare {
    public: 
    bool operator()(int a, int b) {
        return a < b;
    }
};


int main() {
    int arr[] = {13, 20, 4, 30, 10, 15};
    priority_queue<int, vector<int>, Compare> pq;

    for(int x: arr) {
        pq.push(x);
    }
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}