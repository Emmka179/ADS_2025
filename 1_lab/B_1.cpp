#include <iostream>
using namespace std;

// void insSort(int* arr, int size){
//     int i;
//     for(int j=1; j < size; j++){
//         int key = arr[j];
//         i = j-1;
//         while(i >= 0 && arr[i] > key){
//             //shift:
//             arr[i+1] = arr[i];
//             i--;
//         }
//         arr[i+1] = key; //insertion
//     }
// }

class Stack{
    private:
        int top;
        int* data;
    public:
        Stack(int size){
            top = -1;
            data = new int[size];
        }
        ~Stack(){
            delete[] data;
        }
        void push(int value){
            data[++top] = value;
        }
        // void push(char x){
        //     cout << x << endl;
        //     if((int)x == (int)data[top]){
        //         top--;
        //         cout << 'delete' << endl;
        //     }
        //     else{
        //         top++;
        //         data[top] = x;
        //         cout << 'not delete' << endl;
        //     }
        // }
        // bool isEmpty(){
        //     if(top >= 0){
        //         return false;
        //     }
        //     else {
        //         return true;
        //     }
        // }
        int getTop(){
            return data[top];
        }
        char pop(){
            top--;
            return data[top+1];
        }
        bool empty(){
            return top == -1;
        }
        // void answer(int x){
        //     if((int)x < (int)data[top]){
        //         top--; cout << '-1' << endl;
        //     }
        //     else{
        //         top++;
        //         data[top] = x; cout << data[top] << endl;
        //     }
        // }
};

int main(){
    int vvod; cin >> vvod;
    int* arr = new int[vvod];
    // int arr[vvod] = {cin >> vvod2};

    // insSort(arr, vvod);
    // for(int i = 0; i < vvod; i++){
    //     cout << arr[i] << " ";
    // }
    // return 0;
    Stack s(vvod);
    for (int i = 0; i < vvod; i++){
        int x; cin >> x;
        while(!s.empty() && s.getTop() > x){
            s.pop();          // удаляем из стека все элементы, которые больше x
        }
        if (s.empty()){
            cout << -1 << ' ';
        }
        else{
            cout << s.getTop() << ' ';
        }

        arr[i] = x;
        s.push(x);    // кладём его в стек
    }
    // cout << s.pop() << endl;

    delete[] arr;
    return 0;
}