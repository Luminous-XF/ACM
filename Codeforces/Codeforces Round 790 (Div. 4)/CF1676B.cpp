//
// Created by Luminous on 2024/10/11.
// https://codeforces.com/contest/1676/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 50 + 10;

int a[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minVal = *min_element(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] - minVal;
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