#include<iostream>
#include<stack>
#include<vector>

using namespace std;
 
int getMaxArea(vector<int> hist){
    stack<int> st;
    int maxArea = 0;
    int i=0;
    int n = hist.size();
    while(i < n) {
        if(st.empty() || hist[st.top()] <= hist[i]) {
            st.push(i);
            i++;
        } else {
            int top = st.top();
            st.pop();
            int area = hist[top] * (st.empty()? i: i-st.top()-1 );
            maxArea = max(maxArea, area);
        }
    }

    while(!st.empty()) {
        int top = st.top();
        st.pop();
        int area = hist[top] * (st.empty()? i: i-st.top()-1 );
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> hist = {6,2,5,4,5,1,6};
    cout << getMaxArea(hist);
    return 0;
}