#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//learn with gfg method easy to understand using pre-define function such as (substr );
void findingSubset(string input, string output ) {
    if(input.empty()) {
        if(output.empty()) {
            cout << "NULL "<< endl;
            return;
        }
        cout << output << endl;
        return;
    }
    findingSubset(input.substr(1, input.length()), output+input[0]);
    findingSubset(input.substr(1,input.length()), output);
    return;
}


// modifing existing code try to make it easy to understand
void findSubset(string input, string output, int i, vector<string> &list) {
    if(i>input.length()-1) {
        // if(output.empty()) {
        //     cout << "NULL "<< endl;
        //     return;
        // }
        // cout << output << endl;
        list.push_back(output);
        return;
    }

    findSubset(input, output+input[i], i+1, list); 
    findSubset(input, output, i+1, list);
    return;
}

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    string input = "ABC";
    vector<string> s;
    
    string output = "";
    // findingSubset(input, output);

    findSubset(input, output,0, s);

    sort(s.begin(), s.end(), compare);


    for(string str: s) {
        cout << str << ", ";
    }
    cout << endl;
    return 0;
}