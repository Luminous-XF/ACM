//
// Created by Luminous on 2024/10/11.
// https://codeforces.com/contest/1676/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    string s;
    cin >> s;

    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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