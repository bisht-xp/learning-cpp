#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> &s, int ele) {
    if(s.empty() or ele > s.top()) {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s,ele);
    s.push(temp);
}

void helper(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int temp =  s.top();
    s.pop();
    helper(s);
    sortedInsert(s,temp);
}

stack<int> sortStack(stack<int> &s) {
    helper(s);
    return s;
}

int main() {
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(1);

    stack<int> s = sortStack(st);

    while(!s.empty()) {
        cout<< s.top() << endl;
        s.pop();
    }

    return 0;
}