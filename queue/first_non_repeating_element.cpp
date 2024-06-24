#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    queue<char> q;
    vector<char> ans;
    int alphabet[26] = {0};

    cout << (1 > 1) << endl ;
    for(int i=0; i<str.size(); i++) {
        alphabet[str[i] - 'a']++;
        q.push(str[i]);
        while(!q.empty() ) {
            if(alphabet[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) {
            ans.push_back('0');
        }
    }
    return ans;
}

int main() {
    vector<char> v = {'a','a','b','c'};
    vector<char> ans = firstnonrepeating(v);
    for(char ch: ans) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}