#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string playerName;
    Node* next;

    Node(string name) {
        playerName = name;
        next = NULL;
    }
};

class Game {
private:
    Node* head;
    Node* tail;

public:
    Game() {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;

            // Last node points to first node
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;

            // Make list circular
            tail->next = head;
        }
    }

    void displayTurns() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "\nPlayer Turns:\n";

        do {
            cout << current->playerName << " -> ";
            current = current->next;

        } while (current != head);

        cout << "Back to " << head->playerName << endl;
    }
};

int main() {

    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Usman");
    game.addPlayer("Bilal");
    game.addPlayer("Hamza");

    game.displayTurns();

    return 0;
}

