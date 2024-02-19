#include<iostream>
#include<set>

using namespace std; 

string removeDuplicate(string s){
    // your code goes here
    set<char> ss (s.begin(), s.end());
    s.clear();
    for(char ch: ss) {
        s+=ch;
    }

    return s;

}

int main() {
    cout << removeDuplicate("geeksforgeeks") << endl;
    return 0;
}