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

void deleteAtBeg() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

int main() {
    Node* n1 = new Node{10, NULL, NULL};
    Node* n2 = new Node{20, NULL, NULL};
    Node* n3 = new Node{30, NULL, NULL};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    head = n1;

    cout << "Initial Linked List:" << endl;
    display();

    deleteAtBeg();

    cout << "Linked List after deletion at beginning:" << endl;
    display();

    return 0;
}
