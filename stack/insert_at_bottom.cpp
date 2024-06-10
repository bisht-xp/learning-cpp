#include<iostream>
#include <stack>

using namespace std;


void insertAtBottom(stack<int> &st, int num) {
    if(st.empty()) {
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(temp);
    return;
}



int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    insertAtBottom(st, 6);
    while(!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }
    return 0;
}