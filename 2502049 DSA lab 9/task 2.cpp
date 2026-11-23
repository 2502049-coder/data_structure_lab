
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Patient {
    string name;
    int patientID;
    int priority;
    Patient *left, *right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};

vector<Patient*> heap;

void swapData(Patient* a, Patient* b) {
    swap(a->name, b->name);
    swap(a->patientID, b->patientID);
    swap(a->priority, b->priority);
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i]->priority > heap[parent]->priority) {
            swapData(heap[i], heap[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}

void insertPatient(string name, int id, int priority) {
    Patient* newNode = new Patient(name, id, priority);

    heap.push_back(newNode);

    int i = heap.size() - 1;

    if (i > 0) {
        int parent = (i - 1) / 2;

        if (i % 2 == 1)
            heap[parent]->left = newNode;
        else
            heap[parent]->right = newNode;
    }

    heapifyUp(i);
}

void displayHeap() {
    cout << "\nPatients (Level Order):\n";

    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i]->name
             << " | ID: " << heap[i]->patientID
             << " | Priority: " << heap[i]->priority << endl;
    }
}

void showHighestPriority() {
    if (heap.empty()) {
        cout << "No patients!";
        return;
    }

    cout << "\nHighest Priority Patient:\n";
    cout << "Name: " << heap[0]->name << endl;
    cout << "ID: " << heap[0]->patientID << endl;
    cout << "Priority: " << heap[0]->priority << endl;
}

void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() &&
        heap[left]->priority > heap[largest]->priority) {
        largest = left;
    }

    if (right < heap.size() &&
        heap[right]->priority > heap[largest]->priority) {
        largest = right;
    }

    if (largest != i) {
        swapData(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

void deletePatient() {
    if (heap.empty()) {
        cout << "Heap is empty!";
        return;
    }

    cout << "\nPatient Treated: " << heap[0]->name << endl;

    int last = heap.size() - 1;

    swapData(heap[0], heap[last]);

    if (last > 0) {
        int parent = (last - 1) / 2;

        if (last % 2 == 1)
            heap[parent]->left = NULL;
        else
            heap[parent]->right = NULL;
    }

    delete heap[last];
    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);
}

int main() {

    insertPatient("Ali", 101, 5);
    insertPatient("Ahmed", 102, 9);
    insertPatient("Sara", 103, 3);
    insertPatient("Usman", 104, 10);
    insertPatient("Ayesha", 105, 7);
    insertPatient("Hamza", 106, 8);

    displayHeap();

    showHighestPriority();

    deletePatient();

    cout << "\nNext Patient for Treatment:";
    showHighestPriority();

    cout << "\nUpdated Heap:";
    displayHeap();

    return 0;
}

