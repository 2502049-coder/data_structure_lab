
#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
private:
    int packets[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int packetID) {
        if (isFull()) {
            cout << "Queue is full! Cannot add packet.\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        packets[rear] = packetID;
        count++;

        cout << "Packet " << packetID << " added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No packet to transmit.\n";
            return;
        }

        cout << "Packet " << packets[front]
             << " transmitted successfully.\n";

        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets waiting for transmission.\n";
            return;
        }

        cout << "Packets waiting: ";

        for (int i = 0; i < count; i++) {
            cout << packets[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};

int main() {
    CircularQueue network;
    int choice, packetID;

    do {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Add Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Packets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter packet ID: ";
            cin >> packetID;
            network.enqueue(packetID);
            break;

        case 2:
            network.dequeue();
            break;

        case 3:
            network.display();
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

