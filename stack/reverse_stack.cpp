#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(temp);
}


void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }    
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

void print(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << ",";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    print(st);
    reverseStack(st);
    print(st);
    return 0;
}