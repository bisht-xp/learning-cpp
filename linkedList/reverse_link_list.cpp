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


void reverse(Node *&head) {
    Node *temp = head;
    Node *current = head;
    Node *prev = NULL;
    while(temp != NULL) {
        current = temp->next;
        temp->next = prev;
        prev = temp;
        temp = current;
    }
    head = prev;
}

int main() {
    Node *head = NULL;
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    print(head);
    reverse(head);
    print(head);
    // print(head);
    return 0;
}