#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string getHint(string secret, string guess) {
    string ans;
    int cows =0, bull=0;
    unordered_map<char, int> uMap;

    for(int i=0; i<secret.length(); i++) {
        uMap[secret[i]]++;
    }

    for(int i=0; i<secret.length(); i++) {
        if(secret[i] == guess[i]) {            
            bull++;
            uMap[guess[i]]--;
        }
    } 
    for(int i=0; i<secret.length(); i++) {
        if(secret[i] != guess[i]) {
            if(uMap[guess[i]]) {
                cows++;
                uMap[guess[i]]--;
            }
        }
    }
    ans+=to_string(bull);
    ans+="A";
    ans+=to_string(cows);
    ans+="B";
    return ans;
}


int main() {
    string secret = "1122", guess = "1222";
    cout << getHint(secret, guess) << endl;
    return 0;
}