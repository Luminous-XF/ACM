//
// Created by Luminous on 2024/10/9.
// https://codeforces.com/contest/1669/problem/E
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 11;
const int MAX_N = 1e5 + 10;

string str[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    long long ans = 0;
    int book1[N][N] = {0}, book2[N][N] = {0};
    for (int i = 0; i < n; i++) {
        int c1 = str[i][0] - 'a', c2 = str[i][1] - 'a';
        for (int c = 0; c < N; c++) {
            if (c2 != c) ans += book1[c1][c];
            if (c1 != c) ans += book2[c2][c];
        }

        book1[c1][c2]++;
        book2[c2][c1]++;
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