#include<iostream>
#include<stack>

using namespace std;

// void insertAtBottom(stack<int> &st, int n) {
//     if(st.empty()) {
//         st.push(n);
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     insertAtBottom(st, n);
//     st.push(temp);
// }

// void reverseStack(stack<int> &st) {
//     if(st.empty()) {
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     reverseStack(st);
//     insertAtBottom(st, temp);
//  }


int reverse(int n){
	stack<int> st;
	while(n > 0) {
	    int lastNumber = n%10;
	    st.push(lastNumber);
	    n = n/10;
	}
    int rev = 0;
    int i = 1;
      
    while (!st.empty()) 
    {
        rev = rev + (st.top() * i);
        st.pop();
        i = i * 10;
    }
    return rev;
}


int main() {
    int n = 456;
    cout << reverse(n) << endl;
    return 0;
}