//
// Created by Luminous on 2024/10/29.
// https://codeforces.com/contest/2033/problem/E
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e6 + 10;

int a[MAX_N];
bool vis[MAX_N];

int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    return 1 + dfs(a[u]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    fill(vis, vis + n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cnt = dfs(i);
        if (cnt > 2) ans += (cnt - 1) / 2;
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