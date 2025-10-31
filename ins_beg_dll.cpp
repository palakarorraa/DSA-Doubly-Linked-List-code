#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void display() {
    Node* temp = head;
    cout << "NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

int main() {
    Node* n1 = new Node{20, NULL, NULL};
    Node* n2 = new Node{30, NULL, NULL};
    Node* n3 = new Node{40, NULL, NULL};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    head = n1;

    cout << "Initial Doubly Linked List:" << endl;
    display();

    int value;
    cout << "Enter value to insert at beginning: ";
    cin >> value;

    insertAtBeginning(value);

    cout << "Doubly Linked List after insertion at beginning:" << endl;
    display();

    return 0;
}
