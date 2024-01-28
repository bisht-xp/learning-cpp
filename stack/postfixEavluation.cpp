// postfix evaluation start with the starting of the string and prefix start with the ending of the string
#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int postfixEvaluation(string s) {
	stack<int> st;
	for(int i=0; i<s.length(); i++) {
		if(s[i]>='0' && s[i] <= '9') {
			st.push(s[i]-'0');
		} else {
			int opt1 = st.top();
			st.pop();
			int opt2 = st.top();
			st.pop();
			switch(s[i]) {
				case '+': st.push(opt2+opt1);
					 break;
				case '-': st.push(opt2-opt1);
					 break;
				case '*': st.push(opt2*opt1);
					 break;
				case '/': st.push(opt2/opt1);
					 break;
				case '^': st.push(opt2^opt1);
					 break;
			}
		}
	}
	return st.top();
}

int main() {
	cout << postfixEvaluation("46+2/5*7+") << endl;
	return 0;
}
