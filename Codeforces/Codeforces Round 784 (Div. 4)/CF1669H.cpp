//
// Created by Luminous on 2024/10/10.
// https://codeforces.com/contest/1669/problem/H
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt[31] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            cnt[j] += (a[i] >> j) & 1;
        }
    }

    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (n - cnt[i] <= k) {
            k -= n - cnt[i];
            ans += 1 << i;
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