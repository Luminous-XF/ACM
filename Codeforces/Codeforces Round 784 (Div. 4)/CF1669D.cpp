//
// Created by Luminous on 2024/10/9.
// https://codeforces.com/contest/1669/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool check(string s) {
    return count(s.begin(), s.end(), s[0]) != s.length();
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W') continue;

        int j = i;
        while (j + 1 < s.length() && s[j + 1] != 'W') j++;

        if (!check(s.substr(i, j - i + 1))) {
            cout << "NO" << endl;
            return;
        }

        i = j;
    }

    cout << "YES" << endl;
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