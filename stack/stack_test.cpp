#include<iostream>
#include "stackLL.h"

using namespace std;


int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while(!st.empty()) {
        // cout << st.top() << endl;
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}