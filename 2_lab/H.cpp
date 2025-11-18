#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class Linked_list {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() { return size == 0; }

    void insert(T value, int pos) {
        Node<T> *newNode = new Node<T>(value);
        if (pos == 0) { // insert at head
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        } else if (pos == size) { // insert at tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            Node<T> *curr = head;
            for (int i = 0; i < pos; i++) curr = curr->next;
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
        size++;
    }

    void remove(int pos) {
        if (isEmpty()) return;
        Node<T> *curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;
        delete curr;
        size--;
    }

    void replace(int p1, int p2) {
        if (p1 == p2) return;
        Node<T> *curr = head;
        for (int i = 0; i < p1; i++) curr = curr->next;

        // detach curr
        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;

        // now insert at p2
        if (p2 == 0) {
            curr->next = head;
            curr->prev = nullptr;
            if (head) head->prev = curr;
            head = curr;
            if (!tail) tail = curr;
        } else if (p2 == size - 1) {
            curr->prev = tail;
            curr->next = nullptr;
            if (tail) tail->next = curr;
            tail = curr;
        } else {
            Node<T> *posNode = head;
            for (int i = 0; i < p2; i++) posNode = posNode->next;
            curr->prev = posNode->prev;
            curr->next = posNode;
            posNode->prev->next = curr;
            posNode->prev = curr;
        }
    }

    void reverse() {
        Node<T> *curr = head;
        Node<T> *temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            temp = temp->prev;
            tail = head;
            head = temp;
        }
    }

    void cyclic_left(int x) {
        if (size == 0 || x == 0) return;
        x %= size;
        for (int i = 0; i < x; i++) {
            Node<T> *first = head;
            head = head->next;
            head->prev = nullptr;
            tail->next = first;
            first->prev = tail;
            first->next = nullptr;
            tail = first;
        }
    }

    void cyclic_right(int x) {
        if (size == 0 || x == 0) return;
        x %= size;
        for (int i = 0; i < x; i++) {
            Node<T> *last = tail;
            tail = tail->prev;
            tail->next = nullptr;
            last->next = head;
            head->prev = last;
            head = last;
            head->prev = nullptr;
        }
    }

    void print() {
        if (isEmpty()) {
            cout << -1 << endl;
            return;
        }
        Node<T> *curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Linked_list<int> lt;
    while (true) {
        int command; 
        cin >> command;
        if (command == 0) break;
        else if (command == 1) {
            int x, p; cin >> x >> p;
            lt.insert(x, p);
        } else if (command == 2) {
            int p; cin >> p;
            lt.remove(p);
        } else if (command == 3) {
            lt.print();
        } else if (command == 4) {
            int p1, p2; cin >> p1 >> p2;
            lt.replace(p1, p2);
        } else if (command == 5) {
            lt.reverse();
        } else if (command == 6) {
            int x; cin >> x;
            lt.cyclic_left(x);
        } else if (command == 7) {
            int x; cin >> x;
            lt.cyclic_right(x);
        }
    }
    return 0;
}