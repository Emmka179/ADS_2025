#include <iostream>

#include <string>
using namespace std;

class Stack {
private:
    int top;
    char* data;
public:
    Stack(int size) {
        top = -1;
        data = new char[size];
    }
    ~Stack() {
        delete[] data;
    }
    void push(char value) {
        data[++top] = value;
    }
    char pop() {
        return data[top--];
    }
    char getTop() {
        return data[top];
    }
    bool empty() {
        return top == -1;
    }
};

int main() {
    string s;
    cin >> s;
    Stack st(s.size());

    for (char c : s) {
        if (!st.empty() && st.getTop() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
