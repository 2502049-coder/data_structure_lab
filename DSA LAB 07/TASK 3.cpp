
#include <iostream>
using namespace std;

const int SIZE = 5;

class PriorityQueue {
private:
    struct Patient {
        int id;
        int priority;
    };

    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int id, int priority) {
        if (isFull()) {
            cout << "Queue is full! Cannot add patient.\n";
            return;
        }

        if (priority < 1) {
            cout << "Priority must be 1 or greater.\n";
            return;
        }

        Patient newPatient;
        newPatient.id = id;
        newPatient.priority = priority;

        int i = count - 1;

        // Smaller priority number means greater urgency.
        // Equal priorities remain in arrival order.
        while (i >= 0 &&
               patients[i].priority > newPatient.priority) {
            patients[i + 1] = patients[i];
            i--;
        }

        patients[i + 1] = newPatient;
        count++;

        cout << "Patient P" << id << " added successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patients waiting for treatment.\n";
            return;
        }

        cout << "Treating patient P" << patients[0].id
             << " with priority "
             << patients[0].priority << ".\n";

        for (int i = 0; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }

        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients in the queue.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";

        for (int i = 0; i < count; i++) {
            cout << "Patient ID: P" << patients[i].id
                 << " | Priority: "
                 << patients[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue hospital;
    int choice, id, priority;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient ID (e.g. 102): ";
            cin >> id;
            cout << "Enter priority (1 = highest): ";
            cin >> priority;
            hospital.enqueue(id, priority);
            break;

        case 2:
            hospital.dequeue();
            break;

        case 3:
            hospital.display();
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

