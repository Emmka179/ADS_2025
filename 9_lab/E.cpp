#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// vector<int> prefix_func(string s){
//     int n = s.size();
//     vector<int> vec(n);
//     vec[0] = 0;
//     for(int i = 1; i < n; i++){
//         for(int l = 1; l <= i; l++){
//             if(s.substr(0, l) == s.substr(i - l + 1, l))
//                 vec[i] = l;
//         }
//     }
//     return vec;
// }


// vector<int> prefix_func(string s){
//     int n = s.size();
//     vector<int> vec(n);
//     vec[0] = 0;
//     for(int i = 1; i < n; i++){
//         int j = vec[i-1];
//         while(j > 0 && s[j] != s[i])
//             j = vec[i-1];
//         if(s[j] = s[i]){
//             j++;
//         }
//         vec[i] = j;
//     }
//     return vec;
// }


vector<int> prefix_func(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        long long k; cin >> s >> k;

        vector<int> pi = prefix_func(s);

        long long n = s.size(), p = pi.back();
        
        cout << n + (n - p) * (k - 1) << endl;
    }
}
