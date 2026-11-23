
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Medicine {
    string name;
    int medicineID;
    int expiryDate;
    Medicine *left, *right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};

vector<Medicine*> heap;

void swapData(Medicine* a, Medicine* b) {
    swap(a->name, b->name);
    swap(a->medicineID, b->medicineID);
    swap(a->expiryDate, b->expiryDate);
}

// HEAPIFY UP
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        // Min Heap: smaller date moves up
        if (heap[i]->expiryDate < heap[parent]->expiryDate) {
            swapData(heap[i], heap[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}

// INSERT MEDICINE
void insertMedicine(string name, int id, int date) {
    Medicine* newNode = new Medicine(name, id, date);

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

// DISPLAY LEVEL ORDER
void displayHeap() {
    cout << "\nMedicines (Level Order):\n";

    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name
             << " | ID: " << heap[i]->medicineID
             << " | Expiry Date: " << heap[i]->expiryDate
             << endl;
    }
}

// HEAPIFY DOWN
void heapifyDown(int i) {
    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() &&
        heap[left]->expiryDate < heap[smallest]->expiryDate) {
        smallest = left;
    }

    if (right < heap.size() &&
        heap[right]->expiryDate < heap[smallest]->expiryDate) {
        smallest = right;
    }

    if (smallest != i) {
        swapData(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

// DELETE NEAREST EXPIRY MEDICINE
void deleteMedicine() {
    if (heap.empty()) {
        cout << "Heap is empty!";
        return;
    }

    cout << "\nMedicine with Nearest Expiry:\n";
    cout << "Name: " << heap[0]->name << endl;
    cout << "ID: " << heap[0]->medicineID << endl;
    cout << "Expiry Date: " << heap[0]->expiryDate << endl;

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

    insertMedicine("Panadol", 101, 20261215);
    insertMedicine("Brufen", 102, 20260110);
    insertMedicine("Calpol", 103, 20260820);
    insertMedicine("Augmentin", 104, 20260305);
    insertMedicine("Disprin", 105, 20261125);
    insertMedicine("Arinac", 106, 20260215);

    displayHeap();

    deleteMedicine();

    cout << "\nUpdated Heap:";
    displayHeap();

    return 0;
}

