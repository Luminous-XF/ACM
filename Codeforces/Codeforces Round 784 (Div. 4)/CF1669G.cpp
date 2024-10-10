//
// Created by Luminous on 2024/10/10.
// https://codeforces.com/contest/1669/problem/G
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 50 + 10;

string grid[MAX_N];

void fallDown(int column, int n) {
    for (int i = n - 1, bound = n; i >= 0; i--) {
        if (grid[i][column] == '*') {
            swap(grid[bound - 1][column], grid[i][column]);
            bound--;
        } else if (grid[i][column] == 'o') {
            bound = i;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < m; i++) {
        fallDown(i, n);
    }

    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }
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