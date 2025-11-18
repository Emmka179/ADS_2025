#include <iostream>
using namespace std;

class Node{
private:
    Node* next;
    int data;
public:
    Node(int data){
        next = NULL;
        this->data = data;
    }

    void setNext(Node* new_next){
        next = new_next;
    }

    Node* getNext(){
        return next;
    }

    int getData(){
        return data;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insert_tail(Node* newNode){
        if(tail){
            tail->setNext(newNode);
            tail = newNode;
        }
        else{
            head = newNode;
            tail = newNode;
        }
    }

    Node* getHead(){
        return head;
    }

    void printList() {
        Node* current = head;
        while (current){
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    void insertAt(Node* newNode, int pos){
        if(pos == 0){
            newNode->setNext(head);
            head = newNode;
            if(tail == NULL) tail = newNode;
            return;
        }

        Node* current = head;
        for(int i = 0; i < pos - 1; i++)
            current = current->getNext();

        newNode->setNext(current->getNext());
        current->setNext(newNode);
        if(newNode->getNext() == NULL) tail = newNode;
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.insert_tail(new Node(x));
    }

    int data, pos;
    cin >> data >> pos;

    Node* newNode = new Node(data);
    list.insertAt(newNode, pos);

    list.printList();

    return 0;
}