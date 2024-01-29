#include<iostream>
#include<stack>

using namespace std;

bool balancedParenthesis(string s) {
	stack<char> st;
	for(int i=0; i<s.length(); i++) {
		switch(s[i]) {
			case '{': st.push(s[i]);
				  break;
			case '[': st.push(s[i]);
				  break;
			case '(': st.push(s[i]);
				  break;
			case '}': if(!st.empty() and st.top() != '{') {
				  	return false;
				  }
				  st.pop();
				  break;
			case ']': if(!st.empty() and st.top() != '[') {
				  	return false;
				  }
				  st.pop();
				  break;
			case ')': if(!st.empty() and st.top() != '(') {
				  	return false;
				  }
				  st.pop();
				  break;
		}
	}

	return st.empty();
}

int main() {

	cout << balancedParenthesis("{{[](}}") << endl;
	return 0;

}
