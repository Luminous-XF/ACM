//
// Created by Luminous on 2024/10/16.
// https://onlinejudge.org/external/103/10341.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;
const double EPS = 1e-14;

double fun(int p, int q, int r, int s, int t, int u, double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

void solve() {
    int p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (fun(p, q, r, s, t, u, 0) * fun(p, q, r, s, t, u, 1) > 0) {
            cout << "No solution" << endl;
            continue;
        }

        double left = 0, right = 1;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2;
            if (fun(p, q, r, s, t, u, mid) < 0) {
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << fixed << setprecision(4) << setw(4) << setfill('0') << right << endl;
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