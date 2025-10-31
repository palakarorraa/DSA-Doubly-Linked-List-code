#include <iostream>
using namespace std;

#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "Deleted element: " << stack[top] << endl;
    top--;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();

    return 0;
}
