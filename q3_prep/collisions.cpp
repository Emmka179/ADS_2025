#include <iostream>
#include <vector>
using namespace std;


// 1. Separate Chaining (толкаем одинаковые хэши в один лист)

struct HashTable {
    int m; // количество бакетов
    vector<vector<int>> table;

    HashTable(int size) : m(size), table(size) {}

    int hash(int key) { return key % m; }

    void insert(int key) {
        int h = hash(key);
        table[h].push_back(key);
    }

    void print() {
        for (int i = 0; i < m; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " ";
            cout << "\n";
        }
    }
}



// 2. Open Addressing (Linear / Quadratic Probing, Double Hashing)

// Linear Probing

struct HashTableLinear {
    int m;
    vector<int> table;

    HashTableLinear(int size) : m(size), table(size, -1) {}

    int hash(int key) { return key % m; }

    void insert(int key) {
        int h = hash(key);
        for (int i = 0; i < m; i++) {
            int pos = (h + i) % m;
            if (table[pos] == -1) {
                table[pos] = key;
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < m; i++)
            cout << i << ": " << table[i] << "\n";
    }
};


// Quadratic Probing

struct HashTableQuadratic {
    int m;
    vector<int> table;

    HashTableQuadratic(int size) : m(size), table(size, -1) {}

    int hash(int key) { return key % m; }

    void insert(int key) {
        int h = hash(key);
        for (int i = 0; i < m; i++) {
            int pos = (h + i*i) % m;
            if (table[pos] == -1) {
                table[pos] = key;
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < m; i++)
            cout << i << ": " << table[i] << "\n";
    }
};


struct HashTableDouble {
    int m;
    vector<int> table;

    HashTableDouble(int size) : m(size), table(size, -1) {}

    int h1(int k) { return k % m; }
    int h2(int k) { return 1 + (k % (m - 1)); }

    void insert(int key) {
        int a = h1(key);
        int b = h2(key);

        for (int i = 0; i < m; i++) {
            int pos = (a + i * b) % m;
            if (table[pos] == -1) {
                table[pos] = key;
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < m; i++)
            cout << i << ": " << table[i] << "\n";
    }
};