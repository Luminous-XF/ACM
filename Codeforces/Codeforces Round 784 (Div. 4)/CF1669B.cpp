//
// Created by Luminous on 2024/10/8.
// https://codeforces.com/contest/1669/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

unordered_map<int, int> book;

void init() {
    book.clear();
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        book[x]++;
    }

    for (auto &[num, cnt] : book) {
        if (cnt >= 3) {
            cout << num << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- > 0) {
        init();
        solve();
    }

    return 0;
}
