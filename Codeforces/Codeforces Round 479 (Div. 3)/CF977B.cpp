//
// Created by Luminous on 2024/11/12 13:28.
// https://codeforces.com/contest/977/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<string, int> book;
    for (int i = 0; i < n - 1; i++) {
        book[s.substr(i, 2)]++;
    }

    string ans;
    int cnt = 0;
    for (auto &[key, value] : book) {
        if (value > cnt) {
            cnt = value;
            ans = key;
        }
    }

    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}