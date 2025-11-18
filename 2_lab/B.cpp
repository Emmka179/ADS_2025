#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Node{
private:
    Node* prev;
    Node* next;
    string data;
public:
    Node(string data){
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

    string getData(){
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

    // void printList() {
    //     Node* cur = head;
    //     while (cur) {
    //         cout << cur->getData() << " ";
    //         cur = cur->getNext();
    //     }
    //     cout << endl;
    // }

};

//Каждая Node хранит данные (data) и ссылки на соседей (next, prev).
//LinkedList хранит только два указателя: head и tail.

int main(){
    int n, k; cin >> n >> k;
    string s;
    LinkedList list;
    
    while(n-- > 0){
        cin >> s;
        Node* newNode = new Node(s);
        list.insert_tail(newNode); 
    }


    Node* head = list.getHead();
    Node* tail = list.getTail();

    for(int i=0; i<k; i++){
        Node* first = head;

        head = head->getNext();
        head->setPrev(NULL);

        tail->setNext(first);
        first->setPrev(tail);
        first->setNext(NULL);

        tail = first;
    }

    Node* current = head;
    
    while(current){
        cout << current->getData() << " ";
        current = current->getNext();
    }

    return 0;
    

}