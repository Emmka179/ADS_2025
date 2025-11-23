#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class HashTable{
    private:
        LinkedList* arr;
        int size;
    public:
        HashTable(int size){
            arr = new LinkedList[size];
            this->size = size;
        }

        ~HashTable(){
            delete[] arr;
        }

        int id(string s){
            int sum = 0;
            for (int i = 0; i < s.size(); i++)
            {
                sum+=((int)s[i]) * (int)pow(256,(s.size()-1-i));
            }

            return sum;
        }

        int basic_hash(string s){
            int id_num = id(s);

            return id_num % size;
        }

        //rolling poly hashing
        int hash(string s){
            int h = (int)s[0];
            int alphabeth_size = 256;
            for (int i = 1; i < s.size(); i++)
            {
                h = ((h * alphabeth_size)%size + (int)s[i])%size;
            }
            return h;
        }

        void insert(string s){
            int h = hash(s);

            arr[h].insert_tail(s);
        }

        void print(){
            for (int i = 0; i < size; i++)
            {
                arr[i].print();
                cout<<endl;
            }
        }

        Node* search(string s){
            int h = hash(s);

            return arr[h].forwardSearch(s);
        }
};
