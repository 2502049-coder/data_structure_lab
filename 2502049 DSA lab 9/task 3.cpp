
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int amount;
    Order *left, *right;

    Order(int id, string name, int a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = NULL;
    }
};

vector<Order*> heap;

void swapData(Order* a, Order* b) {
    swap(a->orderID, b->orderID);
    swap(a->customerName, b->customerName);
    swap(a->amount, b->amount);
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i]->amount > heap[parent]->amount) {
            swapData(heap[i], heap[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}

void insertOrder(int id, string name, int amount) {
    Order* newNode = new Order(id, name, amount);

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

void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() &&
        heap[left]->amount > heap[largest]->amount) {
        largest = left;
    }

    if (right < heap.size() &&
        heap[right]->amount > heap[largest]->amount) {
        largest = right;
    }

    if (largest != i) {
        swapData(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

void displayHeap() {
    cout << "\nOrders in Max Heap:\n";

    for (int i = 0; i < heap.size(); i++) {
        cout << "Order ID: " << heap[i]->orderID
             << " | Customer: " << heap[i]->customerName
             << " | Amount: " << heap[i]->amount << endl;
    }
}

int deleteRoot() {
    int maxAmount = heap[0]->amount;

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

    return maxAmount;
}

void heapSort() {
    vector<int> amounts;

    while (!heap.empty()) {
        amounts.push_back(deleteRoot());
    }

    reverse(amounts.begin(), amounts.end());

    cout << "\nOrder Amounts in Ascending Order:\n";

    for (int i = 0; i < amounts.size(); i++) {
        cout << amounts[i] << " ";
    }

    cout << endl;
}

int main() {

    insertOrder(1, "Ali", 5000);
    insertOrder(2, "Ahmed", 2000);
    insertOrder(3, "Sara", 8000);
    insertOrder(4, "Usman", 3000);
    insertOrder(5, "Ayesha", 6000);
    insertOrder(6, "Hamza", 1000);

    displayHeap();

    heapSort();

    return 0;
}

