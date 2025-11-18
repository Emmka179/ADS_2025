#include <iostream>
using namespace std;

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
        void push(char x){
            cout << x << endl;
            if((int)x == (int)data[top]){
                top--;
                cout << 'delete' << endl;
            }
            else{
                top++;
                data[top] = x;
                cout << 'not delete' << endl;
            }
        }
        char pop(){
            top--;
            return data[top+1];
        }
        bool empty(){
            return top == -1;
        }
};

int main(){
    Stack s(10);
    s.push(5);
    s.push(10);
    cout << s.pop() << endl; // Outputs: 10
    cout << s.pop() << endl; // Outputs: 5
    return 0;
}