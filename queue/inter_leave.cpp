#include<iostream>
#include<queue>

using namespace std;

queue<int> interLeave(queue<int> q){
    queue<int> q1;
    queue<int> q2;
    int n = q.size();
    for(int i=0; i<n/2; i++) {
        q1.push(q.front());
        q.pop();
    }

    for(int i=n/2; i<n; i++) {
        q2.push(q.front());
        q.pop();
    }

    for(int i=0; i<n/2; i++) {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
    return q;
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    queue<int> ans = interLeave(q);
    while(!ans.empty()) {
        cout << ans.front() << ",";
        ans.pop();
    }

    cout << endl;
}