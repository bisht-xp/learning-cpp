#include<iostream>
#include<stack>

using namespace std;


int main() {
	string s = "Hey, how are you doing?";
	stack<string> st;
	string word = "";
	for(int i=0; i<s.length(); i++) {
		if(s[i] == ' ') {
			// cout << "word: " << word;
			st.push(word);
			word = "";
		} else {
			// word = word + s[i];
		 word.push_back(s[i]);
		}
	}
	st.push(word);

	while(!st.empty()) {
		cout <<st.top() << " ";
		st.pop();
	}
	return 0;	
}
