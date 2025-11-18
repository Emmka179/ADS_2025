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

void insSortDesc(int* arr, int size){
    int i;
    for(int j = 1; j < size; j++){
        int key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] < key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}
//Каждая Node хранит данные (data) и ссылки на соседей (next, prev).
//LinkedList хранит только два указателя: head и tail.

int main(){
    int n, s; cin >> n;
    LinkedList list;
    LinkedList mods;

    for (int i = 0; i < n; i++) {
        cin >> s;   
        Node* newNode = new Node(s);
        list.insert_tail(newNode);
    }

    Node* head = list.getHead();
    int max_count = 0;

    for (Node* i = head; i != NULL; i = i->getNext()) {
        int count = 0;
        for (Node* j = head; j != NULL; j = j->getNext())
            if (i->getData() == j->getData()) count++;
        if (count > max_count) max_count = count;
    }

    int modes[1000];
    int mode_size = 0;

    for(Node* i = head; i != NULL; i = i->getNext()){
        int count = 0;
        for(Node* j = head; j != NULL; j = j->getNext())
            if(i->getData() == j->getData()) count++;

        if(count == max_count){
            bool already = false;
            for(int k = 0; k < mode_size; k++)
                if(modes[k] == i->getData()){
                    already = true;
                    break;
                }
            if(!already) modes[mode_size++] = i->getData();
        }
    }

    insSortDesc(modes, mode_size);

    for(int i = 0; i < mode_size; i++)
        cout << modes[i] << " ";

    return 0;
}
