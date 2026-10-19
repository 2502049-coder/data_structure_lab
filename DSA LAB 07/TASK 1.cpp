
#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
private:
    int customers[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        customers[rear] = token;
        cout << "Customer " << token << " added successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customer to serve.\n";
            return;
        }

        cout << "Customer " << customers[front] << " has been served.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No waiting customers.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << customers[i] << " ";
        }
        cout << endl;
    }

    void countCustomers() {
        if (isEmpty()) {
            cout << "Waiting customers: 0\n";
        } else {
            cout << "Waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    LinearQueue bank;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service ---\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customers\n";
        cout << "4. Count Customers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter token number: ";
            cin >> token;
            bank.enqueue(token);
            break;

        case 2:
            bank.dequeue();
            break;

        case 3:
            bank.display();
            break;

        case 4:
            bank.countCustomers();
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

