#include <iostream>
#include <string>
using namespace std;

class UndoStack {
private:
    string actions[10];
    int top;

public:
    UndoStack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
            return;
        }
        actions[++top] = action;
    }

    void pop() {
        if (top == -1) {
            cout << "No action to undo!" << endl;
            return;
        }
        cout << "Undo action: " << actions[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }

        cout << "Actions (TOP to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void showTop() {
        if (top == -1)
            cout << "No current action." << endl;
        else
            cout << "Current TOP action: " << actions[top] << endl;
    }
};

int main() {
    UndoStack editor;

    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    editor.display();

    cout << "\nPerforming two Undo operations:" << endl;
    editor.pop();
    editor.pop();

    editor.showTop();

    cout << "\nRemaining actions:" << endl;
    editor.display();

    return 0;
}
