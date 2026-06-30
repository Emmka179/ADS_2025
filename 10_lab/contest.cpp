// C task

// #include <bits/stdc++.h>
// using namespace std;

// bool can_finish(long long pos, long long odd_now, long long even_now, long long len) {
//     long long remain = len - pos;
//     if (odd_now + remain > even_now) return true;
//     return false;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long n;
//     cin >> n;
//     string s = to_string(n);
//     long long L = s.size();

//     for (long long len = L; len <= L + 1; len++) {
//         string candidate = (len == L ? s : "1" + string(len - 1, '0'));
//         long long odd = 0, even = 0;
//         bool valid = true;
//         bool increased = false;

//         for (long long i = 0; i < len; i++) {
//             if (!valid) break;
            
//             long long start_digit = candidate[i] - '0';
//             bool digit_assigned = false;

//             if (increased) {
//                 start_digit = 0;
//             }

//             for (long long d = start_digit; d <= 9; d++) {
//                 long long add_odd = (d % 2);
//                 long long add_even = 1 - add_odd;
                
//                 if (can_finish(i + 1, odd + add_odd, even + add_even, len)) {
//                     candidate[i] = char('0' + d);
//                     odd += add_odd;
//                     even += add_even;
                    
//                     if (d > (s[i] - '0') && len == L) {
//                         increased = true;
//                     }
                    
//                     digit_assigned = true;
//                     break;
//                 }
//             }

//             if (!digit_assigned) {
//                 valid = false;
//                 break;
//             }
//         }

//         if (valid) {
//             long long beautiful_num = stoll(candidate);
//             if (len == L + 1 && beautiful_num < n) {
//                 continue;
//             }
//             cout << beautiful_num - n << "\n";
//             return 0;
//         }
//     }

//     string candidate = "1" + string(L, '0');
//     long long beautiful_num = stoll(candidate);
//     cout << beautiful_num - n << "\n";
    
//     return 0;
// }


// B





