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

void deleteAtPos(int pos) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    Node* temp = head;
    int count = 1;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

int main() {
    Node* n1 = new Node{10, NULL, NULL};
    Node* n2 = new Node{20, NULL, NULL};
    Node* n3 = new Node{30, NULL, NULL};
    Node* n4 = new Node{40, NULL, NULL};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    head = n1;

    cout << "Initial Linked List:" << endl;
    display();

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    deleteAtPos(pos);

    cout << "Linked List after deletion:" << endl;
    display();

    return 0;
}
