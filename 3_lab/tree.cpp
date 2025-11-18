#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Tree {
public:
    Node *root;

    Tree() {
        root = NULL;
    }

    Node* insert_node(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (node->data < data) {
            node->right = insert_node(node->right, data);
            node->right->parent = node;
        } else if (node->data > data) {
            node->left = insert_node(node->left, data);
            node->left->parent = node;
        }
        return node; // обязательно возвращаем
    }
};

int main() {
    Tree *tree = new Tree();
    tree->root = tree->insert_node(tree->root, 10);

    tree->root = tree->insert_node(tree->root, 5);
    tree->root = tree->insert_node(tree->root, 15);
    tree->root = tree->insert_node(tree->root, 3);
    tree->root = tree->insert_node(tree->root, 7);
    tree->root = tree->insert_node(tree->root, 12);

    cout << tree->root->left->right->data << endl; // должно вывести 7

    return 0;
}
