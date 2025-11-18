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
    int count;
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

    int getHead() {
    if (isEmpty()) {
        cout << "error\n";
        return -1;
    }
    return arr[head];
}

int getTail() {
    if (isEmpty()) {
        cout << "error\n";
        return -1;
    }

    // если хвост стоит в начале (0), то последний элемент в конце массива
    if (tail == 0) {
        return arr[size - 1];
    } 
    else {
        return arr[tail - 1];
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

// int main() {
//     string s;
//     Queue q(1000000);
//     while(cin >> s && s != "!"){
//         if(s == "-"){
//             int n; cin >> n;
//             q.tail_enqueue(n);
//         }
//         else if(s == "+"){
//             int n; cin >> n;
//             q.head_enqueue(n);
//         }
//         else if(s == "*"){
//             int sum = 0;
//             sum = q.head_dequeue() + q.tail_dequeue();
//         }
//         else{
//             return 0;
//         }
//     }
// }

int main(){
    string s;
    Queue q(1000000);
    while (cin >> s && s != "!"){
        if (s == "-"){
            int n; cin >> n;
            q.tail_enqueue(n);
        }
        else if (s == "+"){
            int n; cin >> n;
            q.head_enqueue(n);
        }
        else if (s == "*"){
            if (q.isEmpty()){
                cout << "error" << endl;
            }
            else{
                int first = q.getHead();
                int second = q.getTail();
                cout << first + second << endl;
                
                q.head_dequeue();
                if (!q.isEmpty()){
                    q.tail_dequeue();
                }
            }

        }
    }
}