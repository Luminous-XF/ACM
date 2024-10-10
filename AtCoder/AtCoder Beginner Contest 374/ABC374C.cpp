//
// Created by Luminous on 2024/10/9.
// https://atcoder.jp/contests/abc374/tasks/abc374_c
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 20 + 10;

int a[MAX_N];

void dfs(int step, int n, long long sumA, long long sumB, long long &ans) {
    if (step == n) {
        ans = min(ans, max(sumA, sumB));
        return;
    }

    dfs(step + 1, n, sumA + a[step], sumB, ans);
    dfs(step + 1, n, sumA, sumB + a[step], ans);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = LONG_LONG_MAX;
    dfs(0, n, 0, 0, ans);

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