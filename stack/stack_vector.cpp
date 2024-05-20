#include<iostream>
#include "stackV.h"

using namespace std;


int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}