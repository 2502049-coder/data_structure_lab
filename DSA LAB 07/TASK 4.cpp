
#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
private:
    int passengers[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        passengers[front] = id;
        count++;

        cout << "Request " << id
             << " inserted at front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        passengers[rear] = id;
        count++;

        cout << "Request " << id
             << " inserted at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Nothing to remove.\n";
            return;
        }

        cout << "Removed request: "
             << passengers[front] << endl;

        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Nothing to remove.\n";
            return;
        }

        cout << "Removed request: "
             << passengers[rear] << endl;

        if (count == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No passenger requests available.\n";
            return;
        }

        cout << "Front -> ";

        for (int i = 0; i < count; i++) {
            cout << passengers[(front + i) % SIZE];

            if (i < count - 1) {
                cout << ", ";
            }
        }

        cout << " <- Rear\n";
    }
};

int main() {
    Deque station;
    int choice, id;

    do {
        cout << "\n--- Train Station Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger request ID: ";
            cin >> id;
            station.insertFront(id);
            break;

        case 2:
            cout << "Enter passenger request ID: ";
            cin >> id;
            station.insertRear(id);
            break;

        case 3:
            station.deleteFront();
            break;

        case 4:
            station.deleteRear();
            break;

        case 5:
            station.display();
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

