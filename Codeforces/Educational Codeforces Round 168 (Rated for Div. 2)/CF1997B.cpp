//
// Created by Luminous on 2024/7/31.
// https://codeforces.com/contest/1997/problem/B
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

char a[2][MAX_N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (a[0][i] == 'x' && a[0][i + 1] == '.' && a[0][i + 2] == 'x' &&
            a[1][i] == '.' && a[1][i + 2] == '.') {
            ans++;
        }

        if (a[1][i] == 'x' && a[1][i + 1] == '.' && a[1][i + 2] == 'x' &&
            a[0][i] == '.' && a[0][i + 2] == '.') {
            ans++;
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
