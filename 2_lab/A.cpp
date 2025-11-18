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
};

int main(){
    int n; 
    cin >> n;

    LinkedList list;
    for(int i = 0; i < n; i++){
        int m; 
        cin >> m;
        Node* newNode = new Node(m);
        list.insert_tail(newNode);
    }

    int target; 
    cin >> target;

    Node* current = list.getHead();
    int minDiff = INT_MAX;
    int index = -1;
    int currentIndex = 0;

    while(current != NULL){
        int diff = abs(current->getData() - target);
        if(diff == 0){ 
            index = currentIndex; 
            break;
        }
        if(diff < minDiff){
            minDiff = diff;
            index = currentIndex;
        }
        current = current->getNext();
        currentIndex++;
    }

    cout << index << endl;
    return 0;
}
