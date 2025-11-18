#include <iostream>
using namespace std;

class Dequeue{
private:
    int *data;
    int head;
    int tail;
    bool full;
    int size;

public:
    int count;
    bool empty;
    Dequeue(int size){
        data = new int[size];
        this->size = size;

        head = 0;
        tail = 0;
        count = 0;

        full = false;
        empty = true;
    }

    ~Dequeue(){
        delete[] data;
    }

    void back_enqueue(int value){
        empty = false;
        if (!full){
            data[tail] = value;
            count++;
            if (tail == size - 1){
                tail = 0;
            } else {
                tail++;
            }
            if (tail == head){
                full = true;
            }
        }
    }

    int front_dequeue(){
        full = false;
        int x = -2147483647;
        if (!empty){
            x = data[head];
            count--;
            if (head == size - 1){
                head = 0;
            } else {
                head++;
            }
            if (tail == head){
                empty = true;
            }
        }
        return x;
    }

    bool isEmpty(){
        return (count == 0);
    }
};

int main(){
    int n; cin >> n;
    string str; cin >> str;

    Dequeue s(100000), k(100000);

    for (int i = 0; i < n; i++){
        if (str[i] == 'S') s.back_enqueue(i);
        else k.back_enqueue(i);
    }

    while (true){
        if (s.isEmpty()){cout << "KATSURAGI"; return 0;}
        if (k.isEmpty()){cout << "SAKAYANAGI"; return 0;}

        int si = s.front_dequeue();
        int ki = k.front_dequeue();

        if (si < ki){
            s.back_enqueue(si + n);
        } else {
            k.back_enqueue(ki + n);
        }
    }
}
