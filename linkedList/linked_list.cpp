#include<iostream>
using namespace std;

struct Node { 
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtBeginning(Node *&head, int value) {
    Node *node = new Node(value);
    if(head == NULL) {
        node->next = head;
        head = node;
        return;
    }

    node->next = head;
    head = node;
    return;
}


void print(Node *head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
    return;
}

int main() {
    Node *head = NULL;
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    print(head);
    insertAtBeginning(head, 3);
    print(head);
    return 0;
}