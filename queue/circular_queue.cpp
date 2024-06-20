#include<iostream>
#include"cirular_queue.h"

using namespace std;

int main() {
    Queue q(6);
    q.push(1);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    return 0;
}