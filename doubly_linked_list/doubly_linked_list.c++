#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

void insertAtBegining(Node *&head, int val) {
    Node *n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    // Node *temp = head;
    head->prev = n;
    n->next = head;
    head = n;
}

void insertAtEnd(Node *&head, int val) {
    Node *n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    n->prev = temp;
    temp->next = n;
}

void deleteNode(Node* &head, int val) {
    if(head == NULL) {
        return;
    }
    Node *temp = head;
    while(temp->data != val) {
        temp = temp->next;
    }
    Node *n = temp;
    n->prev->next = temp->next;
    if(temp->next != NULL) 
        n->next->prev = temp->prev;
    delete n;
}

void display(Node* head) {
    Node *temp = head;
    while (temp != NULL) 
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = NULL;
    insertAtBegining(head, 3);
    insertAtBegining(head, 2);
    insertAtBegining(head,1);
    // insertAtEnd(head, 1);
    // insertAtEnd(head, 2);
    // insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    deleteNode(head, 3);

    display(head);
    return 0;
}