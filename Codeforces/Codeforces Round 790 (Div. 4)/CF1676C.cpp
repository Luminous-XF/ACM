//
// Created by Luminous on 2024/10/11.
// https://codeforces.com/contest/1676/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 50 + 10;

string s[MAX_N];

int getDiff(string &s1, string s2, int m) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        res += abs(s1[i] - s2[i]);
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, getDiff(s[i], s[j], m));
        }
    }

    cout << ans << endl;
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