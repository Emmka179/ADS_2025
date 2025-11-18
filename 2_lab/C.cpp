#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Node{
private:
    Node* prev;
    Node* next;
    int data;
public:
    Node(int data){
        prev = NULL;
        next = NULL;
        this->data = data;
    }

    void setNext(Node* new_next){
        next = new_next;
    }

    void setPrev(Node* new_prev){
        prev = new_prev;
    }

    Node* getNext(){
        return next;
    }
    Node* getPrev(){
        return prev;
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
            newNode->setPrev(tail);
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

    Node* getTail(){
        return tail;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

};

//Каждая Node хранит данные (data) и ссылки на соседей (next, prev).
//LinkedList хранит только два указателя: head и tail.

int main(){
    int n, s; cin >> n;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        cin >> s;   
        Node* newNode = new Node(s);
        list.insert_tail(newNode);
    }

    Node* current = list.getHead();

    while (current && current->getNext()) {
        Node* toDelete = current->getNext();
        Node* third = toDelete->getNext();      
        
        current->setNext(third);                
        if (third) third->setPrev(current);     
        delete toDelete;

        current = third;                        
    }

    list.printList();

    return 0;
    

}