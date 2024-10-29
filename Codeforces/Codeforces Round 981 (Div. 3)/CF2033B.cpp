//
// Created by Luminous on 2024/10/29.
// https://codeforces.com/contest/2033/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 5e2 + 10;

int a[MAX_N][MAX_N];

int fun(int x, int y, int n) {
    int res = 0;
    while (x < n && y < n) {
        if (a[x][y] < 0) {
            res = max(res, -a[x][y]);
        }
        x++, y++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += fun(0, i, n);
        ans += fun(i, 0, n);
    }

    ans -= fun(0, 0, n);

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