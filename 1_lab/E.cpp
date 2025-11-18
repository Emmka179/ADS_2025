#include <iostream>
#include <cmath>
#include <climits>
// #include <bits/stdc++.h>
using namespace std;

class Queue{
private:
    int* arr;
    int size;

    int head;
    int tail;

    bool full;
    bool empty;
public:
    Queue(int size){
        arr = new int[size];
        this->size = size;

        head = 0;
        tail = 0;

        full = false;
        empty = true;
    }
    ~Queue(){//destructor
        delete[] arr;
    }

    void print(){
        int i = head;

        if(tail==head && full){
            cout<<arr[i]<<" ";
            if(i == size-1)
                i = 0;
            else
                i++;
        }

        while(i!=tail){
            cout<<arr[i]<<" ";
            if(i == size-1)
                i = 0;
            else
                i++;
        }

        cout<<endl;
    }

    bool isEmpty(){
        return empty;
    }

    bool isFull(){
        return full;
    }

    void tail_enqueue(int insertedItem){//O(1)
        empty = false;

        if(!full){
            arr[tail] = insertedItem;
            if(tail == size-1){
                tail = 0;
            }else{
                tail++;
            }

            if(tail==head){
                full = true;
            }
        }
        else{
            cout<<"queue is full!"<<endl;
        }
    }

    int head_dequeue(){
        full = false;
        int removedItem = INT_MIN;//placeholder

        if(!empty){
            removedItem = arr[head];
            if(head == size-1)
                head = 0;
            else
                head++;
            
            if(head == tail)
                empty = true;
        }
        else{
            cout<<"queue is empty!"<<endl;
        }

        return removedItem;
    }

    void head_enqueue(int insertedItem){
        empty = false;

        if(!full){
            if(head==0){
                head = size-1;
            }
            else{
                head--;
            }

            arr[head] = insertedItem;

            if(head == tail){
                full = true;
            }

        }
        else{
            cout<<"queue is full!"<<endl;
        }
        
    }

    int tail_dequeue(){
        full = false;
        int removedItem = INT_MIN;

        if(!empty){
            if(tail == 0){
                tail = size-1;
            }
            else{
                tail--;
            }

            removedItem = arr[tail];

            if(tail == head){
                empty = true;
            }

        }
        else{
            cout<<"queue is empty"<<endl;
        }
        return removedItem;
    }
};

int main() {
    Queue a(10);
    Queue b(10);
    int moves=0;

    for(int i=1; i<=5; i++){
        int n; cin >> n;
        a.tail_enqueue(n);
    }

    for(int i=1; i<=5; i++){
        int n; cin >> n;
        b.tail_enqueue(n);
    }

    while(moves < pow(10,6)){
        int a_card = a.head_dequeue();
        int b_card = b.head_dequeue();

        bool Boris_win = (a_card > b_card && !(a_card == 9 && b_card == 0)) || (a_card == 0 && b_card == 9);

        if(Boris_win){
            a.tail_enqueue(a_card);
            a.tail_enqueue(b_card);
        }
        else{
            b.tail_enqueue(a_card);
            b.tail_enqueue(b_card);
        }

        moves++;

        if (a.isEmpty()){
            cout << "Nursik " << moves;
            return 0;
        }
        if (b.isEmpty()){
            cout << "Boris " << moves;
            return 0;
        }

    }
    cout << "blin nichya";

    return 0;
}