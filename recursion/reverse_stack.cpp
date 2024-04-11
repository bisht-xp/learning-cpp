#include<iostream>
#include<stack>

using namespace std;

void insertBack(stack<int> &st, int ele) {
    if(st.empty()) {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insertBack(st, ele);
    st.push(temp);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    } 
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertBack(stack, temp);
}
int main() {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    reverseStack(st);

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;

}