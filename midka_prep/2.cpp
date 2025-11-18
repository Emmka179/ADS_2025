#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, x; cin >> n;

    string command;

    stack<int> st, maxi;    

    while(st.size() < n){
        cin >> command;
        if(command == "add"){
            cin >> x;
            st.push(x);
            if(maxi.empty() || x >= maxi.top()){
                maxi.push(x);
            }
        } 
        else if(command == "delete"){
            if(!st.empty()){
                if(st.top() == maxi.top()){
                    maxi.pop();
                }
            }
        }
        else if(command == "getcur"){
            if(!st.empty()){
                cout << st.top() << endl;
            } 
            else cout << "error" << endl;
        }
        else if(command == "getmax"){
            if(!st.empty()){
                cout << maxi.top() << endl;
            }
            else cout << "error" << endl;
        }
    }
    return 0;
}


