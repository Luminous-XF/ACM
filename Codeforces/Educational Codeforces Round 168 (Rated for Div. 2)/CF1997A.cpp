//
// Created by Luminous on 2024/7/31.
// https://codeforces.com/contest/1997/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    string s;
    cin >> s;

    int inx = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            inx = i;
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (inx == i) {
            if (s[i] == 'z') {
                cout << 'a';
            } else {
                cout << (char) (s[i] + 1);
            }
        }
        cout << s[i];
    }

    cout << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}