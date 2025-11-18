#include <iostream>
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

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    void insSort(int* arr, int size){
    int i;
    for(int j=1; j < size; j++){
        int key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i] > key){
            //shift:
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key; //insertion
    }
}

};


int main(){
    int n, nums; cin >> n;
    string s, prev="";
    LinkedList list;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(!s.empty() && s != prev){
            list.insert_tail(new Node(s));
        }
    }

    cout << "All in all: " << s.size() << endl << "Students:";

    Node* head = list.getHead();

    for(Node* i = head; i != NULL; i = i->getNext()){
        cout << i->getData() << endl;
    }
    return 0;
}
