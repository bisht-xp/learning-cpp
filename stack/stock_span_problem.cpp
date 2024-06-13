#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpanner(vector<int> &stocks){
	vector<int> spans;
    stack<pair<int, int>> st;
    for(int i=0; i<stocks.size(); i++) {
        while(!st.empty() && st.top().first <= stocks[i]) {
            st.pop();
        }
        if(st.empty()) {
            spans.push_back(i+1);
        } else {
            spans.push_back(i-st.top().second);
        }
        st.push({stocks[i], i});
    }
    return spans;
}

int main() {
    vector<int> stocks={100, 80, 60, 70, 60, 75, 85};
    vector<int> spans = stockSpanner(stocks);
    for(int span: spans) {
        cout << span << " ";
    }
    cout << endl;
    return 0;
}