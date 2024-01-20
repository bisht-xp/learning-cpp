#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int value) {
            data = value;
            next = NULL;
        }
};

void insertAtBegining(Node *&head, int value) {
    Node *node = new Node(value);
    if(head == NULL) {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void insertAtEnd(Node *&head, int value) {
    Node *node = new Node(value);
    if(head == NULL) {
        head = node;
        return;
    } 
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void insertAtMiddle(Node *&head, int value, int pos) {
    Node *n = new Node(value);
    Node *temp = head;
    for(int i=0; i<pos-1; i++) {
        temp = temp->next;
    }
    Node *node = temp->next;
    temp->next = n;
    n->next = node;
}

void deleteNode(Node *&head, int pos) {
    if(head == NULL) {
        return;
    }
    Node *temp = head;
    for(int i=0; i<pos-2; i++) {
        temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = n->next;

    delete n;
}

void reverse(Node *&head) {
    if(head == NULL) {
        return;
    }
    Node *prev = NULL;
    Node* curr = head;
    Node *temp;

    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

Node* reverseRecussive(Node* &head) {
    if( head == NULL || head->next == NULL ) {
        return head;
    } 

    Node *newNode = reverseRecussive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

void display(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

int main() {
    Node *head = NULL;
    // insertAtBegining(head, 8);
    insertAtEnd(head, 8);
    insertAtEnd(head, 10);
    insertAtEnd(head, 9);
    insertAtMiddle(head, 32, 1);
    insertAtBegining(head, 1);
    display(head);
    // deleteNode(head, 1);
    Node *newNode =  reverseRecussive(head);

    display(newNode);
    return 0;
}