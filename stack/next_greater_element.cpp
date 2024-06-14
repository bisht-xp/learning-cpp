#include<vector>
#include<iostream> 
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    stack<int> st;
    vector<int> ans(v.size(), 0);
    for(int i=v.size()-1; i>=0; i--) {
        while(!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(v[i]);
    }
    return ans;
    
}

int main() {
    vector<int> elements = {4,5,2,25};
    vector<int> nxGrtElements = nextGreaterElement(elements);
    for(int nxGrtElement: nxGrtElements) {
        cout << nxGrtElement << ",";
    }
    cout << endl;
    return 0;
}