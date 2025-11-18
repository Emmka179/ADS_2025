#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n%i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;

    int num = 1;
    int primes = 0;
    int supnum = 0;

    for (; supnum < n; num++){
        if (isPrime(num)){
            primes++;
            if(isPrime(primes)){
                supnum++;
            }
        }
    }
        
    num--;
    cout << num;

    return 0;
}