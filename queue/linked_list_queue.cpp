#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* back;
	public:
	Queue() {
		front = NULL;
		back = NULL;
	}
	void enqueue(int val) {
		Node* n = new Node(val);
		if(front == NULL) {
			front = n;
			back = front;
			return;
		}	
		back->next = n;
		back = back->next;
	}

	void dequeuq() {
		if(front == NULL) {
			cout << "Queue is empty" << endl;
			return;
		}
		Node* temp = front;
		front = front->next;
		delete temp;
	}

	int peek() {
		if(front == NULL) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		return front->data;
	}

	bool empty() {
		return front == NULL;
	}

    void display() {
        Node* temp = front;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
	Queue 	q;
    Queue q1;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    q1.display();
    q.display();
	// cout << q.peek() << endl;
    // q.dequeuq();
	// cout << q.peek() << endl;
    // cout << q.empty();
	return 0;
}

