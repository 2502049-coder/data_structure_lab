#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

// Display tree members
void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << "Member: " << root->name << endl;

    if (root->left != NULL)
        cout << "Left Child: " << root->left->name << endl;
    else
        cout << "Left Child: None" << endl;

    if (root->right != NULL)
        cout << "Right Child: " << root->right->name << endl;
    else
        cout << "Right Child: None" << endl;

    cout << "-------------------" << endl;

    displayTree(root->left);
    displayTree(root->right);
}

int main() {

    Node* root = new Node("HOD");

    root->left = new Node("CS Coordinator");
    root->right = new Node("SE Coordinator");

    root->left->left = new Node("Ali");
    root->left->right = new Node("Ahmed");

    root->right->left = new Node("Sara");
    root->right->right = new Node("Ayesha");

    cout << "University Department Hierarchy" << endl;

    displayTree(root);

    return 0;
}
