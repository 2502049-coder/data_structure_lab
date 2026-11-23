
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks;
    Student *left, *right;

    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};

vector<Student*> heap;

void swapData(Student* a, Student* b) {
    swap(a->name, b->name);
    swap(a->rollNo, b->rollNo);
    swap(a->marks, b->marks);
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i]->marks > heap[parent]->marks) {
            swapData(heap[i], heap[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}

void insertStudent(string name, int roll, int marks) {
    Student* newNode = new Student(name, roll, marks);

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
    cout << "\nStudent Heap (Level Order):\n";

    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i]->name
             << " | Roll: " << heap[i]->rollNo
             << " | Marks: " << heap[i]->marks << endl;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() &&
        heap[left]->marks > heap[largest]->marks) {
        largest = left;
    }

    if (right < heap.size() &&
        heap[right]->marks > heap[largest]->marks) {
        largest = right;
    }

    if (largest != i) {
        swapData(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

void deleteHighestStudent() {
    if (heap.empty()) {
        cout << "Heap is empty!";
        return;
    }

    cout << "\nDeleted Student: "
         << heap[0]->name
         << " Marks: " << heap[0]->marks << endl;

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

    insertStudent("Ali", 101, 85);
    insertStudent("Ahmed", 102, 92);
    insertStudent("Sara", 103, 78);
    insertStudent("Usman", 104, 95);
    insertStudent("Ayesha", 105, 88);
    insertStudent("Hamza", 106, 90);

    displayHeap();

    deleteHighestStudent();

    cout << "\nUpdated Heap:";
    displayHeap();

    return 0;
}

