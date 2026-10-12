#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = NULL;
    }
};

class OrderStack {
private:
    Node* top;

public:
    OrderStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Processing order: "
             << temp->orderID << endl;

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
            return;
        }

        Node* current = top;

        cout << "Orders TOP to bottom:" << endl;

        while (current != NULL) {
            cout << current->orderID << endl;
            current = current->next;
        }
    }

    void showTop() {
        if (top == NULL)
            cout << "No current order." << endl;
        else
            cout << "Current TOP order: "
                 << top->orderID << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    OrderStack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    restaurant.display();

    cout << "\nProcessing two orders:" << endl;
    restaurant.pop();
    restaurant.pop();

    restaurant.showTop();

    cout << "\nRemaining orders:" << endl;
    restaurant.display();

    cout << "\nIs stack empty? ";

    if (restaurant.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
