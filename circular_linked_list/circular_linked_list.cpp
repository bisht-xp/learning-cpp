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

int lengthNode(Node* &head) {
	int count = 0;
	Node* temp = head;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}


void insertAtBeginning(Node* &head, int val) {
	Node* n = new Node(val);
	if(head == NULL) {
		n->next = n;
		head = n;
		return;
	}

        Node* temp = head;

        while(temp->next != head) {
                temp = temp->next;
        }
        temp->next = n;
        n->next = head;
	head = n;
}

void insertAtEnd(Node* &head, int val) {
	if(head == NULL) {
		insertAtBeginning(head, val);
		return;
	}
	
	Node* n = new Node(val);
	Node* temp = head;

	while(temp->next != head) {
		temp = temp->next;
	}
	n->next = head;
	temp->next = n;
}

void deleteStart(Node* &head) {
	Node* temp = head;
	while(temp->next != head) {
		temp = temp->next;
	}
	Node* n = head;
	temp->next = head->next;
	head = head->next;
	delete n;
}

void deleteAtEnd(Node* head) {
	Node* temp = head;
	while(temp->next->next != head) {
		temp = temp->next;
	}
	Node* n = temp->next;
	temp->next = head;
	delete n;
}

void deleteNode(Node* &head, int pos) {
	// if(lengthNode(head) < pos) {
	// 	return;
	// }
	// else if(pos == 1) {
	// 	deleteStart(head);
	// 	return;
	// }
	// else if(lengthNode(head) == pos) {
	// 	deleteAtEnd(head);
	// 	return;
	// }

	Node* temp = head;
	int count = 0;
	while(count != pos-1) {
		temp = temp->next;
		count++;
	}
	Node* n = temp->next;
	temp->next = temp->next->next;
	delete n;
}

void display(Node* head) {
	Node* temp = head;

	do
	{
		cout << temp->data << "->";
		temp = temp->next;
		
	} while (temp != head);
	cout << "NULL \n";
}

int main() {
	Node* head = NULL;
	insertAtEnd(head, 1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
    insertAtEnd(head, 6);
	insertAtBeginning(head, 0);
	display(head);
	// deleteAtEnd(head);
	deleteNode(head, 1);
	// deleteStart(head);
	display(head);
	return 0;
}
