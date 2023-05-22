#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int maximumScore(int a, int b, int c) {
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans = 0;
    while(pq.top()) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a > 0 && b > 0) {
            ans++;
            a--;
            pq.push(a);
            b--;
            pq.push(b);
        }
    }
    return ans;
}


int main() {
    cout << maximumScore(2, 4, 6) << endl;
    return 0;
}