#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = NULL;
        right =  NULL;
    }
};

class BST{
    private:
    Node* root;
    public:
    BST(){
        root = NULL;
    }
    void insert(Node* cur, int data){
        if(root == NULL){
            root = new Node(data);
            return;
        }
        if(cur -> val == data){
            return;
        }
        if(cur->val < data){
            if(cur->right == NULL){
                cur->right = new Node(data);
                return;
            }
            insert(cur->right, data);
        }
        if(cur->val > data){
            if(cur->left == NULL){
                cur->left = new Node(data);
                return;
            }
            insert(cur->left, data);
        }
    }

    void preorder(Node* cur){
        if(cur == NULL) return;
        cout << cur->val << ' ';
        preorder(cur->left);
        preorder(cur->right);
    }

    int DFS(Node* root){
        if(root == NULL) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        return 1+max(left, right);
    }
}






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


