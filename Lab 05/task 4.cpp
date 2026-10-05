#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string songName;
    Node* next;

    Node(string name) {
        songName = name;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addSong(string name) {
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

    void displayOnce() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "\nPlaylist (One Round):\n";

        do {
            cout << current->songName << " -> ";
            current = current->next;

        } while (current != head);

        cout << "Back to " << head->songName << endl;
    }

    void playTwoRounds() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "\nPlaying Playlist for 2 Complete Rounds:\n";

        // 5 songs x 2 rounds = 10 songs
        for (int i = 0; i < 10; i++) {
            cout << current->songName << endl;
            current = current->next;
        }
    }
};

int main() {

    Playlist playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.addSong("Song D");
    playlist.addSong("Song E");

    playlist.displayOnce();

    playlist.playTwoRounds();

    return 0;
}

