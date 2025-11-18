#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int top;
    string* data;
public:
    Stack(int size) {
        top = -1;
        data = new string[size];
    }

    ~Stack() {
        delete[] data;
    }

    void push(string value) {
        data[++top] = value;
    }

    string getTop() {
        if(top == -1) return "";
        return data[top];
    }

    string pop() {
        if(top == -1) return "";
        return data[top--];
    }

    bool empty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    void print() {
        for(int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    int num;
    cin >> num;
    Stack s(1000);
    int count = 0;

    string prev = "";
    for(int i = 0; i < num; i++) {
        string name;
        cin >> name;
        if(name != prev) {
            s.push(name);
            count++;
            prev = name;
        }
    }

    cout << "All in all: " << count << endl;
    cout << "Students:" << endl;
    s.print();

    return 0;
}
