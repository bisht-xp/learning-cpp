#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> dq(10, 2);

    dq.push_front(1);
    dq.push_back(1);


    for(int x: dq) {
        cout << x << ",";
    }

    cout << dq.size() << endl;

    dq.pop_back();
    dq.pop_front();
    
    cout << "\n";

    for(auto x: dq) {
        cout << x << ",";
    }

    return 0;
}