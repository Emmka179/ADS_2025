#include <iostream>
#include <chrono>
using namespace std;
using  ns = chrono::nanoseconds; 
using get_time = chrono::steady_clock ;

class Stack {
    private:
        int* data;
        int top;

    public:
        Stack(int size) {
            data = new int[size];
            top = -1;
        }
        ~Stack() {
            delete[] data;
        }

        void push(int x) {
            top++;
            data[top] = x;  
        }

        int pop() {
            top--;
            return data[top+1];
        }

        int getTop() {
            return data[top];
        }

        bool empty() {
            return top==-1;
        }
        bool operator==(const Stack& other) {
            if (top != other.top)
            {
                return false;
            }

            int i = top;
            while (i >= 0)
            {
                if(data[i] != other.data[i]){
                    return false;
                }
                i--;
            }
            return true;
            
        }

};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Stack s_1(s1.length());
    Stack s_2(s2.length());

    for(int i = 0; i < s1.length(); i++){
        if (s1[i] == '#')
        {
            s_1.pop();
        }
        else s_1.push(s1[i]);
    }

    for(int i = 0; i < s2.length(); i++){
        if (s2[i] == '#')
        {
            s_2.pop();
        }
        else s_2.push(s2[i]);
    }
    if (s_1 == s_2){
        cout << "Yes";
    }
    else cout << "No";
    
    return 0;
}