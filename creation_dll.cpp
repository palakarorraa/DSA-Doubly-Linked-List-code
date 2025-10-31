#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void createDLL(int n) {
    if (n <= 0) {
        cout << "Number of nodes must be greater than 0." << endl;
        return;
    }

    Node* newNode, *temp;
    int value;

    cout << "Enter data for node 1: ";
    cin >> value;

    head = new Node();
    head->data = value;
    head->prev = NULL;
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = temp;

        temp->next = newNode;
        temp = newNode;
    }
}

void display() {
    Node* temp = head;
    cout << "NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    createDLL(n);

    cout << "\nDoubly Linked List created successfully!" << endl;
    display();

    return 0;
}
