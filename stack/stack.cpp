#include<iostream>
using namespace std;

#define n 100

class Stack {
	int* arr;
	int topIndex;
	public:
		Stack() {
			arr = new int[n];
			topIndex = -1;
		}
		void push(int val) {
			if(topIndex == n-1) {
				cout << "Stack is overflow !!" << endl;
				return;
			}
			topIndex++;
			arr[topIndex] = val;
		}
		void pop();
		int top() {
			return arr[topIndex];
		}
		bool empty() {
			return topIndex == -1;
		}

		void display() {
			for(int i=0; i<=topIndex; i++) {
				cout << arr[i] << " ";
			}

			cout << endl;
		}
};

void Stack::pop() {
	if(topIndex == -1) {
		cout << "Stack is empty or underflow!!" << endl;
		return;
	}
	topIndex--;
}

int main() {
	
	Stack s;
	s.pop();
	cout << s.empty() << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	cout << s.empty() << endl;
	cout << s.top() << endl;
	s.pop();
	s.display();

	return 0;
}


