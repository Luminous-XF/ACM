//
// Created by Luminous on 2024/10/11.
// https://codeforces.com/contest/1676/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 200 + 10;

int grid[MAX_N][MAX_N];

long long getSum(int x, int y, int n, int m) {
    long long res = 0;
    int xx = x - min(x, m - y - 1), yy = y + min(x, m - y - 1);
    while (xx < n && yy >= 0) {
        res += grid[xx][yy];
        xx++, yy--;
    }

    xx = x - min(x, y), yy = y - min(x, y);
    while (xx < n && yy < m) {
        res += grid[xx][yy];
        xx++, yy++;
    }

    return res - grid[x][y];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, getSum(i, j, n, m));
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