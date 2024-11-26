//
// Created by Luminous on 2024/11/26 18:37.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    double n;
    cin >> n;

    double l = -10000, r = 10000;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n) {
            r = mid;
        } else {
            l = mid;
        }
    }

    double ans = r;
    cout << fixed << setprecision(6) << ans << endl;
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