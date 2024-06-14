#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool checkStack(stack<char> st) {
    return st.empty();
}

bool duplicateParentheses(string str){
    stack<char> Stack;
  
    for (char ch : str)
    {
        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();
  
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside < 1) {
                return true;
            }
        }
  
        else
            Stack.push(ch);
    }
  
    return false;
}

int main() {
    string strs = "((a+b)+((c+d)))";
    cout << duplicateParentheses(strs) << endl;
    return 0;
}