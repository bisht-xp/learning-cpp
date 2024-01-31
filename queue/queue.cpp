#include<iostream>
#define n 100

using namespace std;

class Queue {
	int* arr;
	int front;
	int back;
	public:
		Queue() {
			arr = new int[n];
			front= -1;
			back = -1;
		}	

		void enqueue(int val) {
			if(front = -1) {
		       		front++;
			}
			back++;
			arr[back] = val;
		}

		void dequeue() {
			if(front == back) {
				front = -1;
				back = -1;
				return;
			}
			front++;
		}
		int peek() {
			if(front == -1) {
				return -1;
			}
			return arr[front];
		}
		bool empty() {
			return front > back;	
		}

		void display(Queue q);
};

void Queue::display(Queue q) {
	for(int i= q.front; i<=q.back && front != -1; i++) {
		cout << q.arr[i] << " ";
	}
	cout << endl;
}


int main() {
	Queue q;
	q.enqueue(3);
	q.enqueue(69);
	q.enqueue(34);
	q.enqueue(1);
	q.enqueue(2);
	q.display(q);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	printf("%d\n", q.peek());
	printf("%d\n", q.empty());
	q.display(q);

	// printf("\n%d", q.front);

	return 0;
}
