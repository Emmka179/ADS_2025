#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    string* data;
public:
    Stack(int size){
        top = -1;
        data = new string[size];
    }
    ~Stack(){
        delete[] data;
    }
    void push(string value){
        data[++top] = value;
    }
    string getTop(){
        if(top == -1) return "";
        return data[top];
    }
    string pop(){
        if(top == -1) return "";
        return data[top--];
    }
    bool empty(){
        return top == -1;
    }
    int size(){
        return top + 1;
    }
    void print(){
        for(int i = 0; i <= top; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    Stack s(1000);

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        string last = "";
        for(int j = 0; j < m; j++){
            string ch;
            cin >> ch;
            if(j > 0 && ch == last){
                s.push("-1");
            } else {
                s.push(ch);
            }
            last = ch;
        }
        s.print();
    }
    return 0;
}