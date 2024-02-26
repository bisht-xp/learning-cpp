#include<iostream>
#include<vector>

using namespace std;

vector<string> v;

void generateBinaryStrings(int n, string current, vector<string> &result) {
    // Base case: If the length of the current string is equal to n, add it to the result vector
    if (current.length() == n) {
        result.push_back(current);
        return;
    }

    // Recursive step:
    // If the last digit of the current string is '1', we can only append '0' to avoid consecutive ones
    if (current.empty() || current.back() == '0') {
        generateBinaryStrings(n, current + '0', result);
        generateBinaryStrings(n, current + '1', result);
    } else {
        generateBinaryStrings(n, current + '0', result);
    }
}

vector<string> binaryStrings(int n){
    vector<string> result;
    generateBinaryStrings(n, "", result); // Start with an empty string
    return result;  
}

int main() {
    vector<string> s = binaryStrings(3);
    for(auto &i: s) {
        cout << i << " ";
    }
    return 0;
}