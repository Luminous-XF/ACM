//
// Created by Luminous on 2024/10/12.
// https://codeforces.com/contest/1676/problem/E
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];
int preSum[MAX_N];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, greater<>());

    preSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        preSum[i] = preSum[i - 1] + a[i];
    }

    while (q-- > 0) {
        int x;
        cin >> x;

        int index = lower_bound(preSum, preSum + n, x) - preSum;
        if (index == n) {
            cout << -1 << endl;
        } else {
            cout << index + 1 << endl;
        }
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