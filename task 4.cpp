#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Calculate height
int getHeight(Node* n) {
    if (n == NULL)
        return 0;

    return n->height;
}

// Calculate balance factor
int getBalance(Node* n) {
    if (n == NULL)
        return 0;

    return getHeight(n->left) -
           getHeight(n->right);
}

// Right Rotation
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(
        getHeight(y->left),
        getHeight(y->right)
    );

    x->height = 1 + max(
        getHeight(x->left),
        getHeight(x->right)
    );

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(
        getHeight(x->left),
        getHeight(x->right)
    );

    y->height = 1 + max(
        getHeight(y->left),
        getHeight(y->right)
    );

    return y;
}

// AVL Insertion
Node* insert(Node* root, int key) {

    // Normal BST insertion
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    else
        return root;

    // Update height
    root->height = 1 + max(
        getHeight(root->left),
        getHeight(root->right)
    );

    // Calculate balance
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order Traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->key << " ";

    inorder(root->right);
}

// Display AVL Tree
void displayTree(Node* root, int space = 0) {

    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->key
         << " (H=" << root->height
         << ", BF=" << getBalance(root)
         << ")" << endl;

    displayTree(root->left, space);
}

int main() {

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    int size = 7;

    // Insert appointment tokens
    for (int i = 0; i < size; i++) {

        root = insert(root, tokens[i]);
    }

    cout << "Appointment Tokens (In-order):" << endl;

    inorder(root);

    cout << "\n\nFinal Balanced AVL Tree:" << endl;

    displayTree(root);

    return 0;
}
