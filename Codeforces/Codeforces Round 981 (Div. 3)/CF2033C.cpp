//
// Created by Luminous on 2024/10/29.
// https://codeforces.com/contest/2033/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];
int dp[MAX_N][2];

int fun(int x, int y, int xx, int yy) {
    return (x == xx) + (y == yy);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 2) {
        cout << (a[1] == a[2]) << endl;
        return;
    }

    int x, y;
    if ((n & 1) == 1) {
        x = a[n / 2 + 1], y = a[n / 2 + 1];
        dp[n / 2 + 1][0] = dp[n / 2 + 1][1] = 0;
    } else {
        x = a[n / 2], y = a[n / 2 + 1];
        dp[n / 2 + 1][0] = dp[n / 2 + 1][1] = (x == y);
    }

    for (int i = n / 2 + 2; i <= n; i++) {
        int xx = a[n - i + 1], yy = a[i];
        dp[i][0] = min(dp[i - 1][0] + fun(x, y, xx, yy), dp[i - 1][1] + fun(y, x, xx, yy));
        dp[i][1] = min(dp[i - 1][0] + fun(x, y, yy, xx), dp[i - 1][1] + fun(y, x, yy, xx));
        x = xx, y = yy;
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
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