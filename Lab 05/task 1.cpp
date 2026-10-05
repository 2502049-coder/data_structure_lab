#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* current = head;

        cout << "\nHistory (First -> Last):\n";

        while (current != NULL) {
            cout << current->website << " -> ";
            current = current->next;
        }

        cout << "NULL\n";
    }

    void displayReverse() {
        Node* current = tail;

        cout << "\nHistory (Last -> First):\n";

        while (current != NULL) {
            cout << current->website << " -> ";
            current = current->prev;
        }

        cout << "NULL\n";
    }
};

int main() {

    BrowserHistory history;

    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("Facebook");
    history.addWebsite("Wikipedia");
    history.addWebsite("GitHub");

    history.displayForward();
    history.displayReverse();

    return 0;
}

