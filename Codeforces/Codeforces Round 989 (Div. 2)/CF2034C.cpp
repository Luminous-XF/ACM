//
// Created by Luminous on 2024/11/30 23:21.
// https://codeforces.com/contest/2034/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e3 + 10;

char G[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];


void init(int n, int m) {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            G[i][j] = '-';
            vis[i][j] = false;
            cnt[i][j] = 0;
        }
    }
}

void dfs(int x, int y, int n, int m) {
    if (G[x][y] == '?') {
        cnt[x][y]++;
        return;
    }

    if (vis[x][y]) return;

    vis[x][y] = true;
    if (G[x - 1][y] == 'D' || G[x - 1][y] == '?') dfs(x - 1, y, n, m);
    if (G[x + 1][y] == 'U' || G[x + 1][y] == '?') dfs(x + 1, y, n, m);
    if (G[x][y - 1] == 'R' || G[x][y - 1] == '?') dfs(x, y - 1, n, m);
    if (G[x][y + 1] == 'L' || G[x][y + 1] == '?') dfs(x, y + 1, n, m);
}

void solve() {
    int n, m;
    cin >> n >> m;

    init(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 1; i <= m; i++) dfs(0, i, n, m);
    for (int i = 1; i <= m; i++) dfs(n + 1, i, n, m);
    for (int i = 1; i <= n; i++) dfs(i, 0, n, m);
    for (int i = 1; i <= n; i++) dfs(i, m + 1, n, m);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == '?' && cnt[i][j] < 4) ans++;
            if (G[i][j] != '?' && !vis[i][j]) ans++;
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