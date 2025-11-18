#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;
    map<long long, long long> powers;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            powers[i]++;
            n /= i;
        }
    }

    if (n > 1) powers[n]++;  // если осталось простое число

    string result = "";
    for (auto it = powers.begin(); it != powers.end(); ++it) {
        result += to_string(it->first);
        if (it->second > 1)
            result += "^" + to_string(it->second);
        result += "*";
    }

    result.pop_back();  // удалить последнюю '*'
    cout << result;

    return 0;
}