#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prefix_suffix(string s){
    vector<int> pi(s.size());
    //number for storing the intermediate prefix:
    int k;

    pi[0] = 0;

    for (int i = 1; i < s.size(); i++)
    {
        k = pi[i-1];

        while(k>0){
            if(s[i] == s[k]){
                k++;
                break;
            }
            k = pi[k-1];
        }
        if(k==0 && s[i] == s[k]){
            k = 1;
        }
        pi[i] = k;
    }
    return pi;
}

auto search(string text, string pat){
    string s = pat+"$"+text;

    vector<int> pi = prefix_suffix(s);

    for (int i = 0; i < pi.size(); i++)
    {
        if(pi[i] == pat.size()){
            return i-2*pat.size();
        }
    }
    return -1;
}

vector<int> prefix_func(string s){
    int n = s.size();
    vector<int> vec(n);
    vec[0] = 0;
    for(int i = 1; i < n; i++){
        for(int l = 1; l <= i; l++){
            if(s.substr(0, l) == s.substr(i - l + 1, l))
                vec[i] = l;
        }
    }
    return vec;
}

int main(){
    string s, t; cin >> s >> t;
    // string s1 = s + '#' + t;
    vector<int> p = search(t, s);

    cout << p.size() << endl;

    for(int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}