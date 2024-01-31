#include<iostream>
#include<stack>

using namespace std;

class queue {
    stack<int> st;
    public:
        void push(int val) {
            st.push(val);
        }

        int pop() {
            if(st.empty()) {
                cout << "stack is empty: " << endl;
                return -1;
            }
            int ele =  st.top();
            st.pop();
            if(st.empty()) {
                return ele;
            }
            int item = pop();
            st.push(ele);
            return item;
        } 

        bool empty() {
            return st.empty();
        }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}