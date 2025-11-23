#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;

    if (key < root->key) return search(root->left, key);
    else return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* removeNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->key)
        root->left = removeNode(root->left, key);
    else if (key > root->key)
        root->right = removeNode(root->right, key);
    else {
        // leaf
        if (!root->left && !root->right)
            return NULL;

        // one child
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        // two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}

int main() {
    Node* root = NULL;

    int arr[] = {8, 3, 10, 1, 6, 14};
    for (int x : arr) root = insert(root, x);

    cout << search(root, 6) << endl;  // 1
    cout << search(root, 7) << endl;  // 0

    root = removeNode(root, 10);

    return 0;
}
