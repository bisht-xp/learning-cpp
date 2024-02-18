#include<iostream>

using namespace std;

int main() {
    // char temp = cin.get();
    // // cout<<temp << endl;
    // while(temp!='\n') {
    //     cout<<temp;
    //     temp = cin.get();
    // }
    char sentence[1000];
    cin.getline(sentence,1000,'.');
    cout << sentence << endl;

    return 0;
}