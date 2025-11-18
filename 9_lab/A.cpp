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

int search(string text, string pat){
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

int main(){
    string st, subst; cin >> st >> subst;
    string repeated = st;
    int ans = 1;
    while(repeated.size() < st.size() + subst.size()){
        if(repeated.find(subst) != string::npos){
            cout << ans;
            return 0;
        }
        repeated += st;
        ans++;
    }

    if (repeated.find(subst) != string::npos)
        cout << ans;
    else
        cout << -1;
}