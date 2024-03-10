#include<iostream>

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
void findSubset(string input, string output, int i) {
    if(i>input.length()-1) {
        if(output.empty()) {
            cout << "NULL "<< endl;
            return;
        }
        cout << output << endl;
        return;
    }

    findSubset(input, output+input[i], i+1); 
    findSubset(input, output, i+1);
    return;
}


int main() {
    string input = "ABC";
    
    string output = "";
    // findingSubset(input, output);
    findSubset(input, output,0);
    return 0;
}