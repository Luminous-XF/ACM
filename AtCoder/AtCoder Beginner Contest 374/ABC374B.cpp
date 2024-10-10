//
// Created by Luminous on 2024/10/9.
// https://atcoder.jp/contests/abc374/tasks/abc374_b
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    string s, t;
    cin >> s >> t;

    int ans = INT_MAX, len = (int) min(s.length(), t.length());
    for (int i = 0; i < len; i++) {
        if (s[i] != t[i]) {
            ans = i + 1;
            break;
        }
    }

    if (ans == INT_MAX) {
        ans = (s.length() == t.length() ? 0 : len + 1);
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