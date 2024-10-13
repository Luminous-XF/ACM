//
// Created by Luminous on 2024/10/12.
// https://codeforces.com/contest/1676/problem/G
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

vector<int> edge[MAX_N];
string s;

struct TreeColor {
    int white;
    int black;
};

void init(int n) {
    for (int i = 0; i <= n; i++) {
        edge[i].clear();
    }
}

TreeColor dfs(int root, long long &ans) {
    TreeColor treeColor{0, 0};
    if (s[root - 1] == 'W') treeColor.white++;
    if (s[root - 1] == 'B') treeColor.black++;

    for (int to: edge[root]) {
        TreeColor subTreeColor = dfs(to, ans);
        treeColor.white += subTreeColor.white;
        treeColor.black += subTreeColor.black;
    }

    if (treeColor.white == treeColor.black) {
        ans++;
    }

    return treeColor;
}

void solve() {
    int n;
    cin >> n;

    init(n);
    for (int i = 2, vertex; i <= n; i++) {
        cin >> vertex;
        edge[vertex].push_back(i);
    }

    cin >> s;

    long long ans = 0;
    dfs(1, ans);

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