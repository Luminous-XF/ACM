//
// Created by Luminous on 2024/11/12 13:36.
// https://codeforces.com/contest/977/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    if (k == 0) {
        cout << (a[0] == 1 ? -1 : a[0] - 1) << endl;
        return;
    }

    cout << (a[k - 1] == a[k] ? -1 : a[k - 1]) << endl;
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