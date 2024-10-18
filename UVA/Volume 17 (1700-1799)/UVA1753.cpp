//
// Created by Luminous on 2024/10/19.
// https://onlinejudge.org/external/17/1753.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e3 + 10;

double d[MAX_N];
double s[MAX_N];

bool check(int n, int t, double c) {
    double tt = 0;
    for (int i = 0; i < n; i++) {
        double ss = s[i] + c;
        if (ss <= 0) return false;
        tt += d[i] / (s[i] + c);
    }

    return tt <= t;
}

void solve() {
    int n, t;
    while (cin >> n >> t) {
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> s[i];
        }

        double left = -2e6, right = 2e6;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2;
            if (check(n, t, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        double ans = right;
        cout << fixed << setprecision(10) << ans << endl;
    }
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